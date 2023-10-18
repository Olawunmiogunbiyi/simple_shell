#include "main.h"
/**
 * cd_dir -A function to change directory
 * @argv:  directory argu,ment
 * @envp: Environment variable
 *
 * Return: retunr 0
 */
int cd_dir(char **argv, char **envp)
{
	char *oldpwd;
	int value = -1;
	char cwd[PATH_MAX];

	if (argv[1] == NULL)
	{
		value = chdir(_getenv("HOME", envp));
	}
	else if (_strcmp(argv[1], "-") == 0)
	{
		oldpwd = _getenv("OLDPWD", envp);
		if (oldpwd != NULL)
		{
			value = chdir(oldpwd);
		}
		else
		{
			myprintf("CD OLDPWD not set\n");
			return (-1);
		}
	}
	else
	{
		value = chdir(argv[1]);
	}
	if (value == -1)
	{
		perror("cd");
		return (-1);
	}
	else
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	free_vector(argv);
	return (0);
}
