#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUFFER_LENGTH 512
#define TRUE 1

void time_prompt(){
  /* this is what our child process will use as output */
  int sout = NULL;
  pid_t pid;
  /* attempt to fork new process */
    switch (pid = fork()) {
      case -1:
             //error;
      case 0:
        dup2(sout, STDOUT_FILENO);
        close(sout);
	/* process runs date program */
	char* args[] = {"", (char *) 0};
        execv("/bin/date", args);
    default:
      waitpid(pid);
	
    }    
}

int main(int argc, char **argv, char **envp)
{
 char buffer[BUFFER_LENGTH];
 char* args[] = {"", (char *) 0};
 /* path to files we want to execute */
 char* path = "/bin/";
  while(TRUE)
  {
    /* print the prompt */
    time_prompt();
        
    /* get input */
    fgets(buffer, BUFFER_LENGTH, stdin);
    buffer[strlen(buffer) -1 ] = '\0';
    /* process input for use */
    char* command;     
    command = malloc(strlen(path)+strlen(buffer)+1);
    strcpy(command, path);
    strcat(command, buffer);          
    
    int pid = fork();
    if(pid !=0)
      {
	waitpid(pid);
      }
    else
      {
	int rv = execv(command, args);
	printf("\n Error: %s", rv);
	printf("\n");
      }
  } 
  return 0;
}

