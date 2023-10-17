#include "main.h"

/**
 * free_memory - frees a pointer and Empty the address
 * @address: address of the pointer to free
 *
 * Return: 0 if not freed, otherwise 1 if freed.
 */

int free_memory(void **address)
{
	if (address && *address)
	{
		free(*address);
		*address = NULL;
		return (1);
	}
	return (0);
}
