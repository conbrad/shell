#include <stdio.h>
#include <string.h>
#define BUFFER_LENGTH 512
int main(int argc, char **argv, char **envp)
{
  char buffer[BUFFER_LENGTH];
  char* path = "/bin"; 
  while(1)
  {    
     //print the prompt
     printf("myShell&gt;");
     //get input
     fgets(buffer, BUFFER_LENGTH, stdin);
     int pid = fork();
     if(pid !=0)
       {
	 wait(NULL);
       }
     else
       {
	 int rv = execv("/bin/date", argv);
       }
  }  
  return 0;
}
