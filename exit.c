#include "shell.h"
/**
 * exitshell - A function to exit the shell program
 * @tokk : string received from getline
 * @line: program line pointer
 *
 * return: void
 */
void exitshell(char **tokk, char *line)
{
	int status = EXIT_SUCCESS;

	if (tokk[1])
	{
		status = _atoi(tokk[1]);
		if (status > 0)
		{
			free_vector(tokk);
			free(line);
			exit(status);
		}
		else
		{
			status = 2;
			perror("2: Illegal number");
			free(line);
			free_vector(tokk);
			exit(status);
		}
	}
	free_vector(tokk);
	free(line);
	exit(status);
}
/**
 * _strcat - concatenates two strings
 * @dest: input value
 * @src: input value
 *
 * Return: void
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;

	while (dest[i] != '\0')
	{
		i++;
		j = 0;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
