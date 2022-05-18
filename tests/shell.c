#include "shell.h"

int execute(char *args[]);
/**
* split_line - parser
* @line: line
* @delim: delimitator
* Return: tokens
*/
char **split_line(char *line, const char *delim)
{
	int position = 0;
	/* const char s[] = " "; */
	char *token;
	char **tokens = malloc(1024 * sizeof(char *));

	/* border case */
	if (!tokens)
	{
		write(STDERR_FILENO, "allocation error", 17);
		exit(EXIT_FAILURE);
		free(line);
	}

	/* get the first token */
	token = _strdup(strtok(line, delim));

	/**
	* strtok return pointers to within the string you give it,
	* and place \0 bytes at the end of each token
	*/

	/* walk through other tokens */
	while (token != NULL)
	{
		tokens[position] = token;
		token = _strdup(strtok(NULL, delim));
		position++;
	}

	/* reallocate if necessary? */

	tokens[position] = NULL;
	free(line);
	return (tokens);
}


/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument value
 * @env: enviroment var
 * description: main function of shell
 * Return: 0
 */

int main(int argc __attribute__((unused)), char **argv, char **env)
{
	argv = argv;
	/* command loop */
	shell_loop(env);

	return (EXIT_SUCCESS);
}

/**
* shell_loop - THE LOOP :D
* @env: env
* Return: 0
*
*/
int shell_loop(char **env)
{
	char *line = NULL;
	char ex[] = "exit";
	size_t len = 1024;
	int read, i = 0;
	char **tokens;
	char *path;

	/* Command loop */
	/* Prompt */
	write(1, "(mcpshell) ", 11);
	/* Read line, getline allocates mem */
	read = getline(&line, &len, stdin);
	/* check mem */
	if (!line)
		exit(0);
	/* getline returns -1 if failed, including eof condition */
			if (read == -1)
			{
				free(line);

			/**
			* isatty returns 1 if fd is an open file descriptor referring to
			* a terminal; otherwise 0 is returned
			*/
			if (isatty(STDIN_FILENO) != 0)
				exit(EXIT_SUCCESS);
			else
				{
					perror("Error");
					exit(EXIT_FAILURE);
				}
			}

	/* change last position for a null byte (because getline doesn't) */
	if (line[read - 1] == '\n' || line[read - 1] == '\t')
		line[read - 1] = '\0';
	/* if (line == '\n') */
		/* free(line); */
	/* parser function: separates different arguments from stream*/
	tokens = split_line(line, " ");
	if (!tokens[0])
	{
		free_tokens(tokens);
		shell_loop(env);
	}
	/* Compare to "exit" command */
		if (!_strcmp(tokens[0], ex))
			{
				free_tokens(tokens);
				exit(0);
			}
	/* compare to "env" command             ???????? */
	path = path_finder(env);
	/* split_line(path, "=:"); */
		if (!_strcmp(tokens[0], path))
			{
				int j, len = 0;

				for (j = 0; env[j] != NULL; j++)
					{
						len = _strlen(env[j]);
						write(1, env[j], len);
						write(1, "\n", 1);
					}
				free(line);
				shell_loop(env);
			}


	while (tokens[i] != NULL)
	{
		printf("%s\n", tokens[i]); /* change printf    !!!!!!! */
		free(tokens[i]);
		i++;
	}

	/* execute int execute(char *args[]);                   '?????*/

	free(tokens);

	/* recursion for infinte loop */
	shell_loop(env);
	return (0);
}
