#include "shell.h"

/**
 * bfree - frees a pointer and NULLs the address
 * @ptr_f: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr_f)
{
	if (ptr_f && *ptr_f)
	{
		free(*ptr_f);
		*ptr_f = NULL;
		return (1);
	}
	return (0);
}
