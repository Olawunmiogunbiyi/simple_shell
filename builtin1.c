#include "shell.h"

/**
 * _myhistory - Displays the history list, one command per line, preceded
 * with line numbers, starting at 0.
 * @info: Structure containing potential arguments.
 * Return: Always 0.
 */
int _myhistory(info_t *info)
{
    print_list(info->history);
    return (0);
}

/**
 * unset_alias - Unsets an alias to a string.
 * @info: Parameter struct.
 * @stra: The string alias.
 *
 * Return: 0 on success, 1 on error.
 */
int unset_alias(info_t *info, char *stra)
{
    char *p, c;
    int ret;

    p = _strchr(stra, '=');
    if (!p)
        return (1);
    c = *p;
    *p = 0;
    ret = delete_node_at_index(&(info->alias), get_node_index(info->alias, node_starts_with(info->alias, stra, -1)));
    *p = c;
    return (ret);
}

/**
 * set_alias - Sets an alias to a string.
 * @info: Parameter struct.
 * @stra: The string alias.
 *
 * Return: 0 on success, 1 on error.
 */
int set_alias(info_t *info, char *stra)
{
    char *p;

    p = _strchr(stra, '=');
    if (!p)
        return (1);
    if (!*++p)
        return (unset_alias(info, stra));

    unset_alias(info, stra);
    return (add_node_end(&(info->alias), stra, 0) == NULL);
}

/**
 * print_alias - Prints an alias string.
 * @node: The alias node.
 *
 * Return: 0 on success, 1 on error.
 */
int print_alias(list_t *node)
{
    char *p = NULL, *a = NULL;

    if (node)
    {
        p = _strchr(node->stra, '=');
        for (a = node->stra; a <= p; a++)
            _putchar(*a);
        _putchar('\'');
        _puts(p + 1);
        _puts("'\n");
        return (0);
    }
    return (1);
}

/**
 * _myalias - Mimics the alias builtin (man alias).
 * @info: Structure containing potential arguments.
 * Return: Always 0.
 */
int _myalias(info_t *info)
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
            set_alias(info, info->argv[i]);
        else
            print_alias(node_starts_with(info->alias, info->argv[i], '='));
    }

    return (0);
}
