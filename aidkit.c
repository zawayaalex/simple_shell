#include "main.h"
/**
 *freecharstar - free chars array
 *
 * @array: array of chars
 *Return: nothing
 */
void freecharstar(char **array)
{
int i;
if (!array)
{
return;
}
for (i = 0; array[i]; i++)
{
free(array[i]);
array[i] = NULL;
}
free(array), array = NULL;
}
/**
 *output_error - error message
 *
 *@thing: input name
 *@cmd: command
 *@ind: string index
 *Return: error message
 */
void output_error(char *thing, char *cmd, int ind)
{
char *ind_as;
ind_as = _intoas(ind);
write(STDERR_FILENO, thing, _strlen(thing));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, ind_as, _strlen(ind_as));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, cmd, _strlen(cmd));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, "not found\n", 10);
free(ind_as);
}

/**
 *_intoas - int to string
 *
 *@n: num
 *Return: ascii
 */

char *_intoas(int n)
{
char buf[20];
int i = 0;
if (n == 0)
{
buf[i++] = '0';
}
else
{
while (n > 0)
{
buf[i++] = (n % 10) + '0';
n /= 10;
}
}
buf[i] = '\0';
rev_str(buf, i);
return (_strdup(buf));
}

/**
 *rev_str - reverse string
 *
 *@str: input string
 *@len: string length
 *Return: nothing
 */
void rev_str(char *str, int len)
{
char temp;
int first = 0;
int last = len - 1;
while (first < last)
{
temp = str[first];
str[first] = str[last];
str[last] = temp;
first++;
last--;
}
}

