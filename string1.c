#include "shell.h"

/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup - duplicates a string
 * @str_d: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str_d)
{
	int length = 0;
	char *ret;

	if (str_d == NULL)
		return (NULL);
	while (*str_d++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str_d;
	return (ret);
}

/**
 *_puts - prints an input string
 *@str_d: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str_d)
{
	int i = 0;

	if (!str_d)
		return;
	while (str_d[i] != '\0')
	{
		_putchar(str_d[i]);
		i++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c_prt: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c_prt)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c_prt == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c_prt != BUF_FLUSH)
		buf[i++] = c_prt;
	return (1);
}
