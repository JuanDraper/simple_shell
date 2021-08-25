#include "holberton.h"
#include <stdlib.h>
#include <linux/limits.h>
/**
* prepare_command - Parses and check commands
* @command: input from user
* @argv: Argument .
* @envp: Env.
* @alias: Alias .
* @filename: Name of file.
* @new_envs: New env.
* @status: status
*/
void prepare_command(char *command, char *argv[], char *envp[], char *alias[],
char *filename, char *new_envs[], int *status)
{
	short i = 0, j = 0, quote_flag = 0, idx = 0, checks = -1, tok_res;
	char *exec_comm, new_command[ARG_MAX], *av[100];

	while (command[i])
	{
		if (command[i + 1] && (command[i] == '\n' || command[i] == ';'))
		{
			new_command[j++] = ' ', new_command[j++] = '\n';
			new_command[j++] = ' ', i++;
			continue;
		}
		else if (command[i] == '\'' || command[i] == '"')
		{
			quote_flag = ~quote_flag;
			i++;
			continue;
		}
		else if (command[i] == ' ' && quote_flag)
		{
			new_command[j++] = '\'';
			i++;
			continue;
		}
		new_command[j] = command[i], i++, j++;
	}
	free(command), new_command[j] = '\0';
	new_command[_strlen(new_command) - 1] = '\0', exec_comm = new_command;
	do {
		exec_comm += idx;
		checks = check_newlines(exec_comm, &idx);
		tok_res = tokenize(exec_comm, av, alias, filename, status, new_envs);
		if (tok_res)
		{
			for (i = 0; av[i]; i++)
				free(av[i]);
			continue;
		}
		exec_command(filename, av, argv[0], envp, status);
	} while (!checks || (checks == 1 && !*status) || (checks == 2 && *status));
}
