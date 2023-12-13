#include "main.h"

/**
 *is_positive - check postivity
 *
 *@str: string input
 *Return: 0 or 1
 */

int is_positive(char *str)
{
int i;
if (!str)
{
return (0);
}
for (i = 0; str[i]; i++)
{
if (str[i] < '0' || str[i] > '9')
return (0);
}
return (1);
}
/**
 *_astoin - string to integer
 *
 * @str: string
 *Return: integer
 */

int _astoin(char *str)
{
int i, numb = 0;
for (i = 0; str[i]; i++)
{
numb *= 10;
numb += (str[i] - '0');
}
return (numb);
}
