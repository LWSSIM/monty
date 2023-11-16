#include "monty.h"

/**
* _strdup - duplicate str to new allocated memory space
* @str: pointer to input string
* Return: pointer to new memory space && NULL if str = null
*/
char *_strdup(char *str)
{
	char *p;

	int i, size;

	if (str == 0)
		return (0);

	size = 0;
	while (str[size] != '\0')
		size++;

	p = malloc(sizeof(char) * (size + 1));
	if (p == 0)
		return (0);

	for (i = 0; i < size; i++)
	{
		p[i] = str[i];
	}
	p[size] = '\0';
	return (p);
}

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
* get_token - splits string into words using (strtok)
* @input: passed input line
* @delimiter: passed delilimiter
* @w_count: word count
*
* Return: array of words
*/
char **get_token(char *input, const char *delimiter, int *w_count)
{
	int index = 0, count = 0, trailing_spaces;

	char *copy = _strdup(input), *token = NULL, *nl;

	char **words = NULL;

	count = 0;
	if (copy == NULL)
		fprintf(stderr, "Error: malloc failed"), exit(EXIT_FAILURE);

	token = strtok(copy, delimiter);
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delimiter);
	}
	*w_count = count;
	free(copy);
	words = (char **)malloc((sizeof(char *) * count));
	if (words == NULL)
		fprintf(stderr, "Error: malloc failed"), exit(EXIT_FAILURE);

	copy = _strdup(input), token = strtok(copy, delimiter);
	for (index = 0; index < count; index++)
	{
		while (*token == ' ')
			token++;
		words[index] = _strdup(token), token = strtok(NULL, delimiter);
		nl = strchr(words[index], '\n');
		if (nl)
			*nl = '\0';
	}
	if (count > 0)
	{
		trailing_spaces = strspn(words[count - 1], " \t\r\f\v");
		if (trailing_spaces == (int)strlen(words[count - 1]))
			(*w_count)--, free(words[count - 1]);
	}
	free(copy);
	return (words); /*free when called*/
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
