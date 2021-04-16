#include <stdlib.h>
#include "hsh.h"

/**
 * free_list - free memory of linked list
 * @head: pointer to the first node of linked list
 *
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		if (temp->str != NULL)
			free(temp->str);
		free(temp);
	}
}

/**
 * free_argv - free memory of linked list
 * @argv: pointer to the first node of linked list
 *
 */
void free_argv(char **argv)
{
	int i;

	while (argv[i])
	{
		if (argv[i] != NULL)
			free(argv[i]);
		i++;
	}
	free(argv);
}

/**
 * free_buf - free memory of linked list
 * @buf: pointer to the first node of linked list
 *
 */
void free_buf(char *buf)
{
	if (buf != NULL)
		free(buf);
}

/**
 * free_mem - free memory of input pointers
 * @buf: buffer string
 * @head: pointer to the first node of linked list
 *
 */
void free_mem(char *buf, list_t *head)
{
	free_list(head);
	free_buf(buf);
}
