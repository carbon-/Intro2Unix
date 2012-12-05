#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
#include <string>
#include <vector>

#define PARENT_READ readpipe[0];
#define PARENT_WRITE writepipe[1];
#define CHILD_READ writepipe[0];
#define CHILD_WRITE readpipe[1];
//using namespace std;



class Process
{
public:
    /* Initialize the process, create input/output pipes */
    Process(const std::vector<std::string> &args);
    
    /* Close any open file streams or file descriptors,
       insure that the child has terminated */
    virtual ~Process();
    
    /* write a string to the child process */
    void write(const std::string&);

    /* read a full line from child process, 
       if no line is available, block until one becomes available */
    std::string readline();
    
    pid_t pid() const { return m_pid; };

    void cleanUp();

private:
    void exec();
    std::vector<const char *> cargs;
    std::string m_name;
    int readpipe[2];    
    int writepipe[2];
    int size;
    FILE* m_pread;
    pid_t m_pid;
};
