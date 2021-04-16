#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hsh.h"

/**
 * count_arg - counts words in the buf
 * @buf: the string its words to be counted
 *
 * Return: the number of counted words
 */
ssize_t count_arg(char *buf)
{
	ssize_t argc = 1, i = 0;

	while (buf[i] != '\0')
	{
		if (i > 0)
		{
			if (buf[i - 1] != ' ')
				if (buf[i] == ' ')
					argc++;
		}
		else
		{
			if (buf[i] == ' ')
				argc++;
		}
		i++;
	}
	if (buf[0] == ' ')
		argc--;
	if (buf[i - 2] == ' ')
		argc--;
	return (argc);
}

/**
 * parse_arg - parse the string into words
 * @buf: the input string to be parsed
 * @argv: input command in pointer to array format
 * @argc: number of arrays in argv
 *
 * Return: parsed words
 */
void parse_arg(char *buf, char **argv, ssize_t argc)
{
	ssize_t i;
	char *delim = " \n";

	argv[0] = strtok(buf, delim);
	for (i = 1; i < argc; i++)
		argv[i] = strtok(NULL, delim);
	argv[i] = NULL;
}
