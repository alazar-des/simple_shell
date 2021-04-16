#ifndef HEADER_FILE
#define HEADER_FILE


extern char **environ;

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

void parse_arg(char *buf, char *argv[], ssize_t argc);
ssize_t read_cmd(char **, size_t *, list_t *);
ssize_t count_arg(char *);
char *find_path(char *, struct list_s *);
char *_getenv(const char *, list_t **);
int execute(char *argv[], list_t *head);
list_t *add_node_end(list_t **, const char *);
size_t print_list(const list_t *);
void free_mem(char *, list_t *);
char *str_concat(char *, char *);
char *_strdup(const char *);
size_t _strlen(const char *);
void cpy_str(char *, char *);
int _strcmp(char *, const char *);

#endif
