#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hsh.h"

/**
 * _getenv - add PATH environmental variable to a linked list
 * @name: the PATH string
 * @head: pointer to the linked list
 *
 * Return: pointer to the head node
 */
char *_getenv(const char *name, list_t **head)
{
	unsigned int i;
	char *token, *value, *temp;
	const char *delim = "=";
	const char *delim2 = ":";

	i = 0;
	value = NULL;
	while (environ[i])
	{
		temp = _strdup(environ[i]);

		cpy_str(environ[i], temp);
		token = strtok(temp, delim);
		if (_strcmp(token, name) == 0)
		{
			while ((value = strtok(NULL, delim2)) != NULL)
			{
				add_node_end(head, value);
			}
		}
		free (temp);
		i++;
	}
	return (value);
}
