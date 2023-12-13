#include "shell.h"

/**
 * Code by – Hind Ziki , Susan Gicheru . 
 * _myhistory - displays the history list, one command by line, preceded
 *              with lines number, starting at 0.
 * @info: Structure containing potentiel argument. used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * Code by – Hind Ziki , Susan Gicheru .
 * unset_alias - set alias to string.
 * @info: parameter structs.
 * @str: the string alias.
 *
 * Return: Always zero on success, 1 on errors.
 */
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * Code by – Hind Ziki , Susan Gicheru .
 * set_alias - set alias to strings.
 * @info: parameter structs.
 * @str: the string alias.
 *
 * Return: Always 0 on success, 1 on errors.
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * Code by – Hind Ziki , Susan Gicheru
 * print_alias - print an alias strings.
 * @node: the alias node.
 *
 * Return: Always 0 on success, 1 on errors.
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * Code by – Hind Ziki , Susan Gicheru .
 * _myalias - mimics the alias builtin (man alias).
 * @info: Structure containing potentiel argument. used to maintain
 *          constant functions prototypes.
 *  Return: Always zero.
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
