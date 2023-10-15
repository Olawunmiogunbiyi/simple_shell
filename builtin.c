#include "shell.h"

/**
 * _myexit - Exits the shell.
 * @info: Structure containing potential arguments.
 * Return: Exits with a given exit status:
 * - 0 if info->argv[0] != "exit"
 * - -2 if exit with a specific status is requested
 */
int _myexit(info_t *info)
{
	int exit_status;

	if (info->argv[1])
	{
		exit_status = _erratoi(info->argv[1]);
		if (exit_status == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = exit_status;
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - Changes the current directory of the process.
 * @info: Structure containing potential arguments.
 * Return: Always 0.
 */
int _mycd(info_t *info)
{
    char *dir, buffer[1024], *s = getcwd(buffer, 1024);
    int chdir_ret;
    if (!s)
        _puts("TODO: >>getcwd failure emsg here<<\n");
    if (!info->argv[1])
	{
        dir = _getenv(info, "HOME=");
        chdir_ret = chdir((dir ? dir : _getenv(info, "PWD=")) ?: "/");
    }
	else if (_strcmp(info->argv[1], "-") == 0)
	{
        if (!_getenv(info, "OLDPWD="))
		{
            _puts(s);
            _putchar('\n');
            return (1);
        }
        _puts(_getenv(info, "OLDPWD="));
        _putchar('\n');
        chdir_ret = chdir((_getenv(info, "OLDPWD=") ?: "/"));
    }
	else
	{
        chdir_ret = chdir(info->argv[1]);
    }
    if (chdir_ret == -1)
	{
        print_error(info, "can't cd to ");
        _eputs(info->argv[1]);
        _eputchar('\n');
    }
	else
	{
        _setenv(info, "OLDPWD", _getenv(info, "PWD="));
        _setenv(info, "PWD", getcwd(buffer, 1024));
    }
    return (0);
}

/**
 * _myhelp - Provides help information.
 * @info: Structure containing potential arguments.
 * Return: Always 0.
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented\n");
	if (0)
		_puts(*arg_array); /* Temp att_unused workaround */
	return (0);
}
