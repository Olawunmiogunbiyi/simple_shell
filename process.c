#include "main.h"

/**
* process - the parent child process handled
* @command : cammands passed
* @envp : Command received
*
* Return: A int upon completion
*/
int  process(char **command, char **envp)
{
	char *full_tok_path = NULL;
	int status;

	full_tok_path = _getpath(command[0], envp);
	if (full_tok_path == NULL)
	{
		myprintf("command not found\n");
		exit(0);
	}
	else
	{
		pid_t child_pid = fork();

		if (child_pid == -1)
		{
			myprintf("error forking process\n");
			free_vector(command);
			exit(EXIT_FAILURE);
		}
		else if (child_pid == 0)
		{
			if (execve(full_tok_path, command, NULL) == -1)
			{
				perror("Error: execve");
			}
			myprintf("Error Executing Command\n");
			free(full_tok_path);
			free_vector(command);
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
			free_vector(command);
		}
		free(full_tok_path);
	}
	return (0);
}
