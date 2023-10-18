#include "main.h"
/**
 * non_inter_mode - run batch commands
 * @argc: arguement vector
 * @argv: second argument
 * @envp: third argument
 *
 * Return:0 when succefull
 */
int non_inter_mode(int argc, char **argv, char **envp)
{
	char **tokk, *dupstring = NULL, *line = NULL;
	ssize_t nread;
	size_t len = 0;

	if (argc)
		/* ok */
	if (argv)
		/* ok */
	while ((nread = getline(&line, &len, stdin)) != -1)
	{
		line[strcspn(line, "\n")] = '\0';

		if (strcmp(line, "exit") == 0)
		{
			break;
		}

		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';
		dupstring = _strdup(line);
		tokk = tokenize(line);
		executecmd(tokk, envp, line);
	/*	free_vector(tokk);*/
		free(dupstring);
	}
	free(line);
	return (0);

}
