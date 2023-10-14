#include "main.h"
/**
 * set_env_var - sets the enviromental var
 * @args: the argument to set
 *
 * Return: void since were void
 */

void set_env_var(char **args)
{
	int i = 1;

	if (!args[i] || !args[i + 1])
	{
		myprintf("Usage set to setenv VAR_NAME VALUE");
		myprintf("\n");
		free_vector(args);
		return;
	}
	if (setenv(args[i], args[i + 1], 1) != 0)
	{
		free_vector(args);
		perror("setenv");
	}
}

/**
 * un_set_env_var - unset the enviromental varible
 * @args: the argument to set
 *
 * Return: void since were void
 */

void un_set_env_var(char **args)
{
	int i = 1;

	if (!args[i])
	{
		myprintf("Usage unseted");
		myprintf("\n");
		free_vector(args);
		return;
	}
	if (unsetenv(args[i]) != 0)
	{
		perror("unsetenv");
		free_vector(args);
	}

}
/**
 * print_env - a function to env from environ
 * @argv: the argument to set
 * @envp: environment varia
 *
 * Return: void
 */
void print_env(char **argv, char **envp)
{
	int i = 0;

	if (!envp)
	{
		perror("Error loading envp");
		free_vector(argv);
		exit(EXIT_FAILURE);
	}
	while (envp[i] != NULL)
	{
		myprintf(envp[i]);
		myprintf("\n");
		i++;
	}
	free_vector(argv);
	/*free(line);*/
	/*free_vector(envp);*/

}