#include "main.h"

/**
 *_getpath - get path of the current command
 *@commands: user command
 *
 * Return: NULL or path found
 */

char *_getpath(char *commands)
{
char *path_loc, *tot_cmd, *path_dir;
struct stat s;

for (int i = 0; commands[i]; i++)
{
if (commands[i] == '/')
{
if (stat(commands, &s) == 0) /*path exist?*/
{
return (_strdup(commands));
}
else
return (NULL);
}
}
path_loc = _getenv("PATH");
if (!path_loc)
{
return (NULL);
}
path_dir = strtok(path_loc, ":");
while (path_dir)
{
tot_cmd = malloc(_strlen(path_dir) + _strlen(commands) + 2);
if (tot_cmd)
{
_strcpy(tot_cmd, path_dir);
_strcat(tot_cmd, "/");
_strcat(tot_cmd, commands);
if (stat(tot_cmd, &s) == 0)
{
free(path_loc);
return (tot_cmd);
}
free(tot_cmd), tot_cmd = NULL;
path_dir = strtok(NULL, ":");
}
}
free(path_loc);
return (NULL);
}
