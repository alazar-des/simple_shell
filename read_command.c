#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "hsh.h"

/**
 * read_cmd - read input command to the shell
 * @buf_ptr: pointer to a char * that the input command will be written
 * @len_ptr: size_t pointer that getline pointer returns
 * @head: linked list that contains the environmental
 * valriable path directories
 *
 * Return: the character length read form the stdin
 */
ssize_t read_cmd(char **buf_ptr, size_t *len_ptr, list_t *head)
{
	ssize_t nread;

	while ((nread = getline(buf_ptr, len_ptr, stdin)) == -1)
	{
		if (feof(stdin))
		{
			write(STDOUT_FILENO, "\n", 1);
			free_mem(*buf_ptr, head);
			exit(EXIT_SUCCESS);
		}
		else
		{
			exit(EXIT_FAILURE);
		}
	}
	return (nread);
}
