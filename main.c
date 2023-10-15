#include "main.h"
/**
 *  main - shell main entry point
 *  @argc : int main first argument
 *  @argv : int main command command line argument vector
 *  @envp : environment variable
 *
 *  Return: return 0 upon success
 *
 */
int main(int argc, char **argv, char **envp)
{
	if (!(argc < 2))
	{
		printf("Usage: %s path_to_file ...\n", argv[0]);
		return (1);
	}
	if (!isatty(STDIN_FILENO))
		non_inter_mode(argc, argv, envp);
	else
	{
		interract(argc, argv, envp);
	}
	/*free(line);*/
	return (0);
}
