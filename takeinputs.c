#include "main.h"
/**
 * take_inputs - take user input
 *
 * Description: inputs in
 * Return: inputs or NULL
 */
char *take_inputs(void)
{
char *inputs = NULL;
size_t len = 0;
ssize_t l;

if (isatty(STDIN_FILENO)) /*for terminal only $*/
{
write(STDOUT_FILENO, "$ ", 2);
}
l = getline(&inputs, &len, stdin);
if (l == -1)
{
free(inputs);
return (NULL);
}

return (inputs);
}
