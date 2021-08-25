#include "holberton.h"
#include <stdio.h>
#include <unistd.h>

/**
 * _getline - input from stdin
 * @command:  buffer
 * @size: chatr count
 * @fd: file descriptor 
 * Return: char count witn /n etc
 */

short _getline(char **command, int *size, int fd)
{
	short read_bytes = 0;

	read_bytes = read(fd, *command, *size);

	if (read_bytes == 0)
		return (-1);
	else if (read_bytes == -1)
	{
		free(*command);
		perror("Could not read input");
		exit(-1);
	}

	(*command)[read_bytes] = '\0';
	return (read_bytes);
}
