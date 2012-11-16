/* ECE 2524 Shaishav Parekh 11/15/2012
 * dispatcher.cpp
 */
 
 #include <unistd.h>
 #include <signal.h>
 #include <string.h>
 #include <iostream>
 #include <stdio.h>
 #include <sys/wait.h>
 #include <stdlib.h>

int main ()
{
	// create a pipe
	int pipefd[2];
	// read end of pipe
	int read_fd;
	// write end of pipe
	int write_fd;
	// two child processes
	pid_t child1, child2;
	// return code for child processes
	pid_t rc_child1, rc_child2;
	// return states for child processes
	int child1_state, child2_state;

	// make sure pipe was successfully instantiated
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	// assign read and right ends
	read_fd = pipefd[0];
	write_fd = pipefd[1];

	// create a fork
	child1 = fork();
	// make sure fork was successfully created
	if (child1 == -1)
	{
		perror("child1 fork error");
		exit(EXIT_FAILURE);
	}
	// connect output to write end of pipe
	// close read end
	// exec generator
	if (child1 == 0)
	{
		close(1);
		dup(write_fd);
		close(read_fd);
		execlp("./generator", (char*) 0);
	}

	// create another fork
	child2 = fork();
	// make sure fork was successfully created
	if (child2 == -1)
	{
		perror("child2 fork error");
		exit(EXIT_FAILURE);
	}
	// connect input to read end of pipe
	// close write end
	// exec consumer
	if (child2 == 0)
	{
		close(0);
		dup(read_fd);
		close(write_fd);
		execlp("./consumer", (char*) 0);
	}
	// sleep for 1 second
	usleep(1000000);
	// send terminate signal to child1 aka generator process
	int success = kill (child1, SIGTERM);
	// error check
	if (success == -1)
	{
		perror("kill not successful");
		exit(EXIT_FAILURE);
	}

	// sleep to stabilize output
	usleep(50);

	// wait for generator child to exit
	rc_child1 = waitpid(child1, &child1_state, WNOHANG);
	
	// output some information to std::cerr
	if (rc_child1 >= 0)
	{
		std::cerr << "generator child process [" << child1 << "] exited with rc=" << WEXITSTATUS(child1_state) << "\n";
	}

	// wait for consumer child to exit
	rc_child2 = waitpid(child2, &child2_state, WNOHANG);

	// output some information to std::cerr
	if (rc_child2 >= 0)
	{
		std::cerr << "consumer child process [" << child2 << "] exited with rc=" << WEXITSTATUS(child2_state) << "\n";
	}

	// exit the program
	return 0;
}