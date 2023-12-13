#include "main.h"
/**
 * word_split - function that splits input into words
 * @inputs : inputs
 * Description : split words
 * Return: commands
 */

char **word_split(char *inputs)
{
char *split = NULL, *temp = NULL;
char **commands = NULL;
int count_t = 0, i = 0;
if (!inputs)
{
return (NULL);
}
temp = _strdup(inputs);
split = strtok(temp, " \t\n");
if (split == NULL)
{
free(inputs), inputs = NULL;
free(temp), temp = NULL;
return (NULL);
}
while (split)
{
count_t++;
split = strtok(NULL, " \t\n");    /* for the next word */
}
free(temp), temp = NULL;
commands = malloc(sizeof(char *) * (count_t + 1));
if (!commands)
{
free(inputs), inputs = NULL;
return (NULL);
}
split = strtok(inputs, " \t\n");
while (split)
{
commands[i] = _strdup(split);
split = strtok(NULL, " \t\n");    /* for the next word */
i++;
}
free(inputs), inputs = NULL;
commands[i] = NULL;
return (commands);
}
