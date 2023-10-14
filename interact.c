#include "main.h"
/**
 * interract - shell interractive mode
 * @argc : int main first argument
 * @argv : int main command command line argument vector
 * @envp : environment variable
 *
 * Return: 0 unpon success
 */
int interract(int argc, char **argv, char **envp)
{
	char **tokk, *prompt, *line = NULL;
	ssize_t nread;
	size_t len = 0;

	if (argc)
		/* ok */
	if (argv)
		/* ok */
	while (1)
	{
		prompt = "$ ";
		myprintf(prompt);
		fflush(stdout);
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			if (feof(stdin))
			{
				free(line);
				myprintf("\n");
				exit(0);
			}
			free(line);
			perror("Error: getline");
			myprintf("\n");
			exit(EXIT_SUCCESS);
		}
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';
		tokk = tokenize(line);
		executecmd(tokk, envp, line);
		/*free_vector(tokk);*/
	}
	free(line);/* */
	return (0);
}