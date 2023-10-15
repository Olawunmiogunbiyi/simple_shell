#include "main.h"
/**
 * _atoi - converts a string to an integer
 *  @s: string to be converted
 *
 *  Return: the int converted from the string
 */

int _atoi(char *s)
{
	int count, d, n, mystringLenght, f, digit;

	count = d = n = mystringLenght = f = digit = 0;

	while (s[mystringLenght] != '\0')
		mystringLenght++;
	while (count < mystringLenght && f == 0)
	{
		if (s[count] == '-')
			++d;
		if (s[count] >= '0' && s[count] <= '9')
		{
			digit = s[count] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (s[count + 1] < '0' || s[count + 1] > '9')
				break;
			f = 0;
		}
		count++;
	}
	if (f == 0)
		return (0);
	return (n);
}
/**
 * myprintf - A function to print instead of printf
 * @datas : string received from the calling function
 *
 * retur: Return type is void
 */

void myprintf(const char *datas)
{
	write(1, datas, strlen(datas));
}

/**
* _strcmp - a function to compare string values
* @s1: first string input value
* @s2: second string input value
*
* Return: the difference in integer
*/

int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
/**
* _getenv - a function to get environment variables ie syspaths
* @name: name of the system variable to serach for
* @envp: environment variable
*
*Return: a vector or null
*/
char *_getenv(char *name, char **envp)
{
	size_t name_len = _strlen(name);

	for (; *envp != NULL; ++envp)
	{
		if (strncmp(*envp, name, name_len) == 0 && (*envp)[name_len] == '=')
		{
			return (&(*envp)[name_len + 1]);
		}
	}
	return (NULL);
}
