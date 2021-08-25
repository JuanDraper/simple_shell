#include "holberton.h"
#include <stdio.h>
/**
 * _strcpy - copies string
 * @dest: pointer to  copy
 * @src:  char array
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	if (dest && src)
		while ((*dest++ = *src++))
			;
	return (dest);
}
