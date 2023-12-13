#include "main.h"

/**
 * is_inside - function for internal cmd
 * @commands: argument
 * Description: for preset orders
 * Return: 1 or 0
 */

int is_inside(char *commands)
{
char *inds[] = {
"exit", "env", "setenv",
"cd", NULL
};
int i;
for (i = 0; inds[i]; i++)
{
if (_strcmp(commands, inds[i]) == 0)
{
return (1);
}
}
return (0);
}

/**
 * inside_deal - fun to handel inside cmd
 * @commands: argument
 * @argv: input
 * @out_log: status output
 * @inds: index
 * Description: handle the cmd
 *
 */
void inside_deal(char **commands, char **argv, int *out_log, int inds)
{

if (_strcmp(commands[0], "exit") == 0)
{
exit_shell(commands, argv, out_log, inds);
}
else if (_strcmp(commands[0], "env") == 0)
{
print_env(commands, out_log);
}
}

/**
 * exit_shell - function for exit cmd
 * @commands: cmd inpu
 * @argv: argus
 * @out_log: status output
 * @inds: index
 * Description: handle exit order
 * Return: success
 */
void exit_shell(char **commands, char **argv, int *out_log, int inds)
{
int val_exit = (*out_log);
char *ind_as, message[] = ": exit: Illegal number: ";
if (commands[1])
{
if (is_positive(commands[1]))
{
val_exit = _astoin(commands[1]);
}
else
{
ind_as = _intoas(inds);
write(STDERR_FILENO, argv[0], _strlen(argv[0]));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, ind_as, _strlen(ind_as));
write(STDERR_FILENO, message, _strlen(message));
write(STDERR_FILENO, commands[1], _strlen(commands[1]));
write(STDERR_FILENO, "\n", 1);
free(ind_as);
freecharstar(commands);
(*out_log) = 2;
return;
}
}
freecharstar(commands);
exit(val_exit);
}

/**
 * print_env - fun to print env
 * @commands: cmd input
 * @out_log: status output
 * Description: print env
 */

void print_env(char **commands, int *out_log)
{
int i;
for (i = 0; environ[i]; i++)
{
write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
write(STDOUT_FILENO, "\n", 1);
}
freecharstar(commands);
(*out_log) = 0;
}
