#include "main.h"

/**
 * _getpath - a function to get path of a command
 *  @strings: string of command
 *  @envp: environment variable passed
 *
 *  Return: char NULL when not successfull or fulladdress of path
 */

char *_getpath(char *strings, char **envp)
{
	char *filepath = _getenv("PATH", envp), *dup_file_path;
	char *token;
	size_t total_len = 0;
	struct stat cmd;
	char *mypath;
	char *delim = ":";

	if (strings == NULL)
	{
		perror("NULL input received");
		return (NULL);
	}
	if (stat(strings, &cmd) == 0)
		return (_strdup(strings));

	dup_file_path = _strdup(filepath);
	token = strtok(dup_file_path, delim);
	while (token)
	{
		total_len = _strlen(token) + _strlen(strings) + 2;
		mypath = malloc(total_len);
		if (mypath == NULL)
			break;
		else if (mypath != NULL)
		{
			_strcpy(mypath, token);
			_strcat(mypath, "/");
			_strcat(mypath, strings);

			if (stat(mypath, &cmd) == 0)
			{
				free(dup_file_path);
				return (mypath);
			}
		}
		free(mypath);
		token = strtok(NULL, delim);
	}
	free(dup_file_path);
	return (NULL);
}
