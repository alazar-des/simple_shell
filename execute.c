#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "hsh.h"
#include <string.h>

/**
 * print_env - print enviromental variables to studout
 *
 */
void print_env(void)
{
	unsigned int i = 0;
	int fd;

	while (environ[i] != NULL)
	{
		fd = write(1, environ[i], _strlen(environ[i]));
		if (fd == -1)
		{
			perror("hsh: ");
			exit(EXIT_FAILURE);
		}
		write(1, "\n", 1);
		i++;
	}
}

/**
 * execute - executes shell command
 * @argv: command input
 * @head: linked list of PATH environmental variable
 *
 * Return: on success 0
 */
int execute(char *argv[], list_t *head)
{
	pid_t pid;
	int status;

	if (_strcmp(argv[0], "env") == 0)
	{
		print_env();
		return (1);
	}
	if (_strcmp(argv[0], "exit") == 0)
		return (0);
	argv[0] = find_path(argv[0], head);
	if (argv[0] != NULL)
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("hsh");
			}
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
			perror("hsh");
		else
		{
			waitpid(pid, &status, 0);
			if (argv[0] != NULL)
				free(argv[0]);
		}
	}
	else
		write(STDOUT_FILENO, "hsh: No such file or directory\n", 31);
	return (1);
}
