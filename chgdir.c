#include "main.h"
/**
 * cd_dir -A function to change directory
 * @args:  directory argument
 * @envp: Environment variable
 *
 * Return: retunr 0
 */
int cd_dir(char **args, char **envp)
{
	char *new_dir;

	char cwd[PATH_MAX];

	if (args[1] == NULL || strcmp(args[1], "~") == 0)
	{
		new_dir = _getenv("HOME", envp);
	}
	else if (strcmp(args[1], "-") == 0)
	{
		new_dir = _getenv("OLDPWD", envp);
	}
	else
	{
		new_dir = args[1];
	}
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		perror("getcwd");
		return (1);
	}
	if (setenv("OLDPWD", cwd, 1) != 0)
	{
		perror("setenv");
		return (1);
	}
	if (chdir(new_dir) != 0)
	{
		perror("chdir");
		return (1);
	}
	if (setenv("PWD", new_dir, 1) != 0)
	{
		perror("setenv");
		return (1);
	}
	free_vector(args);
	return (0);
}
