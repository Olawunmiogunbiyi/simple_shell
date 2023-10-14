#include "main.h"
/**
 * free_vector - A function to free vectors
 * @argv : vector to be freed
 *
 * Return : void
 */
void free_vector(char **argv)
{
	int i;

	if (argv)
	{
		i = 0;

		while (argv[i] != NULL)
		{
			if (argv[i])
			{
				free(argv[i]);
			}
			i++;
		}
		free(argv);
	}
}


func.c

#include "main.h"
/**
 * _strlen - the function to count the string
 * @s: the string to be countenate
 *
 * Return: Always void
 */

int _strlen(char *s)
{
	int c;

	for (c = 0; s[c] != '\0'; c++)
	{


	}
	return (c);
}