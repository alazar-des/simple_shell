#include <unistd.h>
#include "hsh.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _strcon - concatinate 2 strings and write to the destination string
 * @dest: destination string
 * @s1: first string
 * @s2: second string
 *
 */
void _strcon(char *dest, char *s1, char *s2)
{
	int i = 0, j = 0;

	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '/';
	i++;
	while (s2[j] != '\0')
	{
		dest[i] = s2[j];
		i++, j++;
	}
	dest[i] = '\0';
}
/**
 * find_path - find the directory of the command
 * @cmd: string input command
 * @head: a struct that saves the PATH environmental directories
 *
 * Return: return the full path of the command
 */
char *find_path(char *cmd, list_t *head)
{
	int fd, i;
	char *temp1 = NULL, *fullpath = NULL;

	i = 0;
	while (cmd[i] != '\0')
	{
		if (cmd[i] == '/')
		{
			fullpath = _strdup(cmd);
			return (fullpath);
		}
		i++;
	}
	while (head != NULL)
	{
		temp1 = str_concat(head->str, "/");
		fullpath = str_concat(temp1, cmd);
		fd = access(fullpath, F_OK);
		if (fd == 0)
		{
			free(temp1);
			return (fullpath);
		}
		head = head->next;
		if (temp1 != NULL)
			free(temp1);
		if (fullpath != NULL)
			free(fullpath);
	}
	return (NULL);
}
