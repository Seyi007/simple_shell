#include "shell.h"

/**
 * _strlen - counts strings
 * @s: parameter s
 * Description: counts the string characters
 * Return: always 0
 */

int _strlen(char *s)
{
	int count = 0;

	while (*(s + count))
	{
		count++;
	}
	return (count);
}

/**
 * _strdup - String dup.
 * @str: string
 * Return: a pointer to a newly alloc space in memory, containing a copy of str
 */

char *_strdup(char *str)
{
	int i;
	char *p;

	if (str == NULL)
		return (NULL);
	p = malloc(sizeof(char) * (_strlen(str) + 1));
	if (p == NULL)
		return (NULL);
	for (i = 0 ; i < (_strlen(str) + 1) ; i++)
	{
		p[i] = str[i];
	}
	return (p);
}


/**
 * _strcmp - a function that compares two strings
 * @s1: input one
 * @s2: input two
 * Return: Always 0 (Success)
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	if (s1 && s2)
	{
		for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
		{
			if (s1[i] != s2[i])
				return (s1[i] - s2[i]);
		}
		return (0);
	}
	return (-1);
}

/**
 * free_tokens - free the tokens
 * @tokens: token
 * return: token free
 */
void free_tokens(char **tokens)
{
	int i = 0;

	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}

	free(tokens);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
