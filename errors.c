#include "shell.h"

/**
 *print_input_string - prints an input string
 * @strp: the string to be printed
 *
 * Return: Nothing
 */
void print_input_string(char *strp)
{
	int k = 0;

	if (!strp)
		return;
	while (strp[k] != '\0')
	{
		write_char_stderr(strp[k]);
		i++;
	}
}

/**
 * write_char_stderr - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int write_char_stderr(char c)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(2, buf, j);
		j = 0;
	}
	if (c != BUF_FLUSH)
		buf[j++] = c;
	return (1);
}

/**
 * write_fd - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int write_fd(char c, int fd)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(fd, buf, j);
		j = 0;
	}
	if (c != BUF_FLUSH)
		buf[j++] = c;
	return (1);
}

/**
 *_print_string - prints an input string
 * @strp: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _print_string(char *strp, int fd)
{
	int j = 0;

	if (!strp)
		return (0);
	while (*strp)
	{
		j += write_fd(*strp++, fd);
	}
	return (i);
}
