#include "holberton.h"
/**
 * _strlen -  length of a string
 * @s: pointer to  string
 * Return:  chars in the string
 */
int _strlen(char *s)
{
	int n = 0;

	if (s)
		for (n = 0; *s; s++)
			n++;
	return (n);
}
