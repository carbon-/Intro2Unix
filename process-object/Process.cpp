#include "Process.h"

// Constructor
// Initializes the process, creates input/output pipes
Process::Process(const std::vector<std::string> &args)
{
	size = args.size();
	/*transform(args.begin(), args.end(), back_inserter(cargs),
		[](const string s) { return s.c_str()});*/
	for (uint i = 0; i < size; i++)
	{
		cargs.push_back(args[i].c_str());
	}
	
	cargs.push_back(NULL);
	char **p_cargs = &cargs[0];
	int exeStatus;
	try 
	{
		if (pipe(readpipe) == -1)
			throw "Read Pipe Error";
		else if (pipe(writepipe) == -1)
			throw "Write Pipe Error";

		m_pid = fork();
		if (m_pid == -1)
			throw "Fork Error";
		// in the child process
		else if (m_pid == 0)
		{			
			dup(CHILD_READ);
			dup(CHILD_WRITE);

			exeStatus = execvp(p_cargs[0], p_cargs);
			if (exeStatus)
				throw "Execution Error";
		}
		
	}
	catch (char* str)
		{
			cleanUp();
			std::cerr << "Exception Raised: " << str << endl;
		}
	}


	// DEBUG
	/*for (int i = 0; i < cargs.size(); i++)
	{
		std::cout << cargs.at(i) << std::endl;
	}*/


}

Process::~Process()
{
	cleanUp();
}

void Process::cleanUp()
{
	close(PARENT_READ);
	close(PARENT_WRITE);
	close(CHILD_WRITE);
	close(CHILD_READ);
	wait();
}

void Process::write(const std::string &writeString)
{
	write(PARENT_WRITE, writeString.c_str(), strlen(writeString.c_str())+1);
}

std::string Process::readline()
{
	
	char message[100];
	int bytes;
	bytes = read(PARENT_READ, message, sizeof(message));
	std::string rline (message);
	return rline;

	// debug
	// std::cout << bytes << endl;
}