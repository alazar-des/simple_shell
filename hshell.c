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
	ssize_t wr, nread;
	list_t *head = NULL;
	const char *name = "PATH";
	int status = 1;

	_getenv(name, &head);
	while (status)
	{
		wr = write(STDOUT_FILENO, "#cisfun $ ", 10);
		if (wr == -1)
		{
			perror("hsh: ");
			free_mem(buf, head);
			exit(EXIT_FAILURE);
		}
		nread = read_cmd(&buf, &len, head);
		if (nread != 1)
		{
			const ssize_t s = count_arg(buf);

			if (s < 1)
				continue;
			char *argv[s];

			parse_arg(buf, argv, s);
			status = execute(argv, head);
		}
	}
	free_mem(buf, head);
	return (0);
}
