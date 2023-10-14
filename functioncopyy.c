#include "main.h"
/**
 * _strcpy - copies the string including the \0 char
 * @dest: destination of the string
 * @src: source of the string
 *
 * Return: a pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	char *start = dest;
	char *end = src;

	while (*end != '\0')
	{
		*start = *end;
		start++;
		end++;
	}
	*start = '\0';
	return (dest);
}