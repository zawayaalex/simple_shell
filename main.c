#include "main.h"

/**
 * main - simple shell
 * @ac: count of arguments
 * @av: arguments
 * Return: 0 (success)
*/

int main(int ac, char **av)
{
char *inputs = NULL, **commands = NULL;
int out_log = 0, ind = 0, *ptr = &out_log;
(void) ac;
while (1)
{
inputs = take_inputs();
if (inputs == NULL) /* if end of file reached (ctrl + D) */
{
if (isatty(STDIN_FILENO)) /*for terminal only $*/
{
write(STDOUT_FILENO, "\n", 1);
}
return (out_log);
}
ind++;
/*free(inputs);*/
commands = word_split(inputs);
if (!commands)
{
continue;
}
if (is_inside(commands[0]))
{
inside_deal(commands, av, ptr, ind);
}
else
{
out_log = _execute(commands, av, ind);
}
}
}
