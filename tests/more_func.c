#include "shell.h"

/**
* execute - entry point
* @args: arguments
* Return: an execution or error
*/
int execute(char *commandarray[])
{
	char *executable_path = NULL;
	char *command = NULL;
	pid_t pid;
	int status;

	command = commandarray[0];
	/* executable_path = path_finder; */

	if (executable_path == NULL)
	{
		not_found(command);
		return (2);
	}

	pid = fork();

	if (pid < 0)
	{
		perror("Error: ");
		return (-1);
	}
	if (pid > 0)
	{
		wait(&status);
	}

	if (pid == 0)
	{
		execve(); /* execve(const char *pathname, char *const argv[], char *const envp[]); */
		perror("Error: ");
		exit(1);
	}

	free(executable_path);
	return (0);
}

/**
 * not_found - prints if a command is not found
 * @command: command
 * Return: an error message
 */
int not_found(char *command)
{
	/* write(2, name, strlen(name)); no se que poner aca*/
	write(2, ": 1: ", 5);
	write(2, command, strlen(command));
	write(2, ": not found\n", 12);
}
