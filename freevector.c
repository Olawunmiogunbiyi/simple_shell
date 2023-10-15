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
