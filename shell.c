#include <stdio.h>
void check_if_newline(char *c)
{
  if(c == '\n')
    printf("CON_SHELL$");
}
void display_shell_prompt()
{
  char *c ='\0';
  printf("\nCON_SHELL$ ");
  while(c != EOF)
    {
      c = getchar();
      process input(c);
    }
    printf("\n");
}
int main(int argc, char **argv, char **envp)
{
  display_shell_prompt();
  return 0;
}
