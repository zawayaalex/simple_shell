#include "main.h"
/**
 *_getenv - get eniroment inf
 *
 *@var: variable
 *Return: null or inf out
 */
char *_getenv(char *var)
{
char *temp, *loc, *val, *env_out;
int i;
for (i = 0; environ[i]; i++)
{
temp = _strdup(environ[i]);
loc = strtok(temp, "=");
if (_strcmp(loc, var) == 0)
{
val = strtok(NULL, "\n");
env_out = _strdup(val);
free(temp);
return (env_out);
}
free(temp), temp = NULL;
}
return (NULL);
}
