#include "main.h"
/**
 * tokenize- a function to break a string into tokens
 * @str: string to be passed
 *
 * Return: a vector or null
 */

char **tokenize(char *str)
{
	char *buf = NULL, *bufp = NULL, *token = NULL, *delim = " :\n\t\r";
	char **tokens = NULL;
	int tokensize = 1;
	size_t index = 0, flag = 0;

	buf = strdup(str);
	if (!buf)
		return (NULL);
	bufp = buf;
	while (*bufp)
	{
		if (strchr(delim, *bufp) != NULL && flag == 0)
		{
			tokensize++;
			flag = 1;
		}
		else if (strchr(delim, *bufp) == NULL && flag == 1)
			flag = 0;
		bufp++;
	}
	tokens = malloc(sizeof(char *) * (tokensize + 1));
	token = strtok(buf, delim);
	while (token)
	{
		tokens[index] = strdup(token);
		if (tokens[index] == NULL)
		{
			free(tokens);
			return (NULL);
		}
		token = strtok(NULL, delim);
		index++;
	}
	tokens[index] = '\0';
	free(buf);
	return (tokens);
}