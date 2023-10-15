#include "main.h"

/**
 * hash - a hlper function to help hash some character constant
 * @str : string passed
 *
 * Return: returns the hashed value
 */
unsigned long hash(const char *str)
{
	unsigned long hash = 5381;

	int c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;
	return (hash);
}
/**
 * _strchr - a function to finds a certain character
 * @s: the memory to be  searched
 * @c: the charcter to to search for
 *
 * Return: A pointer to the address of the memory
 */

char *_strchr(char *s, char c)
{
	int k = 0;

	int length = _strlen(s);

	for (; k <= length; k++)
	{
		if (s[k] == c)
		{
			return (&s[k]);
		}
	}
	return (NULL);
}

/**
 * _strdup - A function that duplicates a string and returns the pointer
 * @str: the string to duplicate
 *
 *   Return: Always 0 for sucess
 */

char *_strdup(const char *str)
{
	char *buffer;
	int i;

	int len = 0;

	while (str[len])

		len++;

	buffer = (char *)malloc(len + 1);

	if (buffer == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < len; i++)
	{
		buffer[i] = str[i];
	}

	buffer[len] = '\0';

	return (buffer);
}
