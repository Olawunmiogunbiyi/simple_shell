#include "shell.h"

/**
 * display_history - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int display_history(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str_a: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str_a)
{
	char *p, c;
	int ret;

	p = _strchr(str_a, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str_a, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias_to_string - sets alias to string
 * @info: parameter struct
 * @str_a: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias_to_string(info_t *info, char *str_a)
{
	char *p;

	p = _strchr(str_a, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (set_alias(info, str_a));

	set_alias(info, str_a);
	return (add_node_end(&(info->alias), str_a, 0) == NULL);
}

/**
 * print_alias_string - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias_string(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str_a, '=');
		for (a = node->str_a; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _manlias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _manlias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias_to_string(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
