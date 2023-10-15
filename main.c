#include "shell.h"

/**
 * main - entry point
 * @args_c: arg count
 * @args_v: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int args_c, char **args_v)
{
	info_t info[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (args_c == 2)
	{
		fd = open(args_v[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(args_v[0]);
				_eputs(": 0: Can't open ");
				_eputs(args_v[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, args_v);
	return (EXIT_SUCCESS);
}
