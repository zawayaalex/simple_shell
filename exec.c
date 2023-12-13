#include "main.h"

/**
 * _execute - function to execute
 * @commands: input cmd
 * @argv: arguments
 * @ind: index
 * Description: execution fun
 * Return: status number
 */
int _execute(char **commands, char **argv, int ind)
{
char *tot_cmd;
pid_t ch;
int out_log;

tot_cmd = _getpath(commands[0]);
if (!tot_cmd)
{
output_error(argv[0], commands[0], ind);
freecharstar(commands);
return (127);
}
ch = fork();
if (ch == 0)
{
if (execve(tot_cmd, commands, environ) == -1)
{
/*perror(argv[0]);*/
free(tot_cmd), tot_cmd = NULL;
freecharstar(commands);
/*exit(127);*/
}
}
else
{
waitpid(ch, &out_log, 0);
freecharstar(commands);
free(tot_cmd), tot_cmd = NULL;
}
return (WEXITSTATUS(out_log));
}
