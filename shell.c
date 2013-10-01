#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUFFER_LENGTH 512
void time_prompt(){
  /* this is what our child process will use as output */
  int sout;
  /* attempt to fork new process */
    switch (fork()) {
      case -1:
             //error;
      case 0:
        dup2(sout, STDOUT_FILENO);
        close(sout);
	/* process runs date program */
        execlp("date", "date", NULL);
    }
}

int main(int argc, char **argv, char **envp)
{
 char buffer[BUFFER_LENGTH];
 char* path = "/bin/";
 char* ls = "ls";
  while(1)
  {
    /* print the prompt */
    time_prompt();
        
    /* get input */
     fgets(buffer, BUFFER_LENGTH, stdin);
     buffer[strlen(buffer) -1 ] = '\0';
     char* command;     
     command = malloc(strlen(path)+strlen(buffer)+1);
     strcpy(command, path);
     strcat(command, buffer);          
     int pid = fork();
     if(pid !=0)
       {
	 wait(NULL);
       }
     else
       {
	 int rv = execv(command, argv);
	 printf("\n code from execv is: %i", rv);
       }
  }   
  return 0;
}

