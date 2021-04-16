#include <stdlib.h>

/**
 * _strlen - return length of string
 * @str: string pointer
 *
 * Return: length of string
 */
size_t _strlen(const char *str)
{
	size_t count;

	count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

/**
 * cpy_str - copy string from s1 to s2
 * @src: source
 * @dest: destination
 *
 */
void cpy_str(char *src, char *dest)
{
	while (*src != '\0')
	{
		*dest = *src;
		dest++, src++;
	}
	*dest = '\0';
}

/**
 * str_concat - concatnate two strings
 * @s1: input string 1
 * @s2: input string 2
 *
 * Return: the concatnated string pointer
 */
char *str_concat(char *s1, char *s2)
{
	int size1, size2;
	char *con;

	if (s1 != NULL || *s1 != '\0')
		size1 = _strlen(s1);
	else
		size1 = 0;
	if (s2 != NULL || *s2 != '\0')
		size2 = _strlen(s2);
	else
		size2 = 0;
	if (size1 + size2 == 0)
		return (NULL);
	con = malloc(size1 + size2 + 1);
	if (con == NULL)
		return (NULL);
	if (size1 != 0)
		cpy_str(s1, con);
	if (size2 != 0)
		cpy_str(s2, con + size1);

	con[size1 + size2] = '\0';
	return (con);
}


/**
 * _strdup - duplicate string
 * @src: string to be duplicated
 *
 * Return: duplicated pointer in success, otherwise NULL
 */
char *_strdup(const char *src)
{
	size_t size, i;
	char *dest;

	size = _strlen(src);
	dest = malloc(size + 1);
	if (dest == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - compare two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: if s1 > s2 return positive, if s1 < s2 negative, otherwise 0
 */
int _strcmp(char *s1, const char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 - *s2 != 0)
			return (*s1 - *s2);
		s1++;
		s2++;
	}

	return (0);
}
