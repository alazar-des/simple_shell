#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "hsh.h"

/**
 * main - program entry point
 * Description - a shell that excutes commands
 *
 * Return: on success 0
 */
int main(void)
{
	char *buf = NULL;
	size_t len = 0;
	ssize_t wr, nread, s1, s2, i;
	list_t *head = NULL;
	const char *name = "PATH";
	int status = 1;
	char **argv;

	_getenv(name, &head);
	while (status)
	{
		wr = write(STDOUT_FILENO, "#cisfun $ ", 10);
		if (wr == -1)
		{
			perror("hsh: ");
			free_mem(buf, head);
			i = 0;
			if (argv != NULL)
			{
				while (argv[i] != NULL)
				{
					free(argv[i]);
					i++;
				}
				if (argv != NULL)
					free(argv);
			}
			exit(EXIT_FAILURE);
		}
		nread = read_cmd(&buf, &len, head);
		if (nread != 1)
		{
			s1 = count_arg(buf);
			s2 = s1;
			argv = malloc((s1 + 1) * (sizeof(char *)));
			if (s1 >= 1)
			{
				parse_arg(buf, argv, s1);
				status = execute(argv, head, s2);
			}
		}
	}
	free_mem(buf, head);
	free(argv);
	return (0);
}
