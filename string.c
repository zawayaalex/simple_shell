#include "main.h"

/**
 *_strdup - duplicate string
 *
 * @str_input: string input
 *Return: NULL or duplicated string
 */

char *_strdup(const char *str_input)
{
char *ptr_str;
int i, len = 0;

if (str_input == NULL)
{
return (NULL);
}
while (*str_input != '\0')
{
len++;
str_input++;
}
str_input = str_input - len;
ptr_str = malloc(sizeof(char) * (len + 1));
if (ptr_str == NULL)
{
return (NULL);
}
for (i = 0; i <= len; i++)
{
ptr_str[i] = str_input[i];
}
return (ptr_str);
}

/**
 *_strcmp - string comparing
 *
 *@str1: 1st string
 *@str2: 2nd string
 *Return: compare result
 */

int _strcmp(char *str1, char *str2)
{
int compare;

compare = (int)*str1 - (int)*str2;
while (*str1)
{
if (*str1 != *str2)
{
break;
}
str1++;
str2++;
compare = (int)*str1 - (int)*str2;
}
return (compare);
}

/**
 *_strlen - string length
 *
 * @c: input string
 *Return: length
 */

int _strlen(char *c)
{
int len = 0;
while (c[len])
{
len++;
}
return (len);
}

/**
 *_strcat - invert the string
 *@direct: destination
 *@inbound: input
 *Return: destination
 */
char *_strcat(char *direct, char *inbound)
{
char *ptr = direct;
while (*ptr)
{
ptr++;
}
while (*inbound)
{
*ptr = *inbound;
ptr++;
inbound++;
}
*ptr = *inbound;
return (direct);
}
/**
 *_strcpy - copy string
 *@direct: destination
 *@inbound: input
 *
 *Return: direct
 */
char *_strcpy(char *direct, char *inbound)
{
int i = 0;
while (inbound[i])
{
direct[i] = inbound[i];
i++;
}
direct[i] = '\0';
return (direct);
}
