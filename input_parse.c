#include "monty.h"

/**
* _getline - read line from stream
* @lineptr: ptr->line
* @n: lenght
* @stream: file strem
* Description:
* -stores address of bfr to *lineptr
* -*lineptr and *n are updated on success
* Return: nmbr of chars read || -1 on fail
*/
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t bfrsz = 257;
	size_t position = 0;
	int c;

	if (*lineptr == NULL || *n == 0)
	{
		*n = bfrsz;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	while (1)
	{
		c = fgetc(stream);
		if (c == EOF)
		{
			break;
		}
		if (position >= *n - 1)
		{
			bfrsz *= 2;
			*n = bfrsz;
			*lineptr = (char *)realloc(*lineptr, *n);
			if (*lineptr == NULL)
				return (-1);
		}
		(*lineptr)[position++] = c;
		if (c == '\n')
			break;
	}
	if (position == 0 && c == EOF)
		return (-1);
	(*lineptr)[position] = '\0';
	return (position);
}

/**
* check_space - check for non_white spcae
* @str: input
* @chars_read: nbr of chars
* Return: i
*/
int check_space(char *str, ssize_t chars_read)
{
	int i = 0;

	ssize_t j;

	for (j = 0; j < chars_read; j++)
	{
		if (!_isspace(str[j]))
		{
			i = 1;
			break;
		}
	}
	return (i);
}
/**
* _isspace - check if char is space
* @c: input
* Return: bool
*/
int _isspace(char c)
{
	return (c == ' ' ||
			c == '\t' ||
			c == '\n' ||
			c == '\r' ||
			c == '\v' ||
			c == '\f');
}

/**
 * check_int - check if str is int
 * @str: str to check
 * Return: 0 || 1
 */
int check_int(char *str)
{
	int i, flag = 0;

	if (str[0] == '-' || str[0] == '+')
	{
		flag = 1;
		str++;
	}
	for (i = 0; i < (int)strlen(str); i++)
	{
		if (!isdigit(str[i]))
			return (0);
	}
	if (flag == 1 && i == 0)
		return (0);
	return (1);
}
