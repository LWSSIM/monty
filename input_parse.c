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
 * get_token - splits string into words using (strtok)
 * @input: passed input line
 * @delimiter: passed delilimiter
 * Return: array of words
 */
char **get_token(char *input, const char *delimiter)
{
	unsigned int w_count = 0, index = 0;
	char *copy = strdup(input), *token = NULL;
	char **words = NULL;

	if (copy == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
	}
	token = strtok(copy, delimiter);
	while (token)
	{
		w_count++;
		token = strtok(NULL, delimiter);
	}
	w_count++; /*for NULL*/
	free(copy);

	words = malloc(((sizeof(char *) * w_count) + 1));
	if (words == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
	}
	copy = strdup(input);
	token = strtok(copy, delimiter);
	while (token != NULL)
	{
		words[index] = malloc((sizeof(char) * (strlen(token))) + 1);
		strcpy(words[index], token);
		token = strtok(NULL, delimiter);
		index++;
	}
	words[index] = NULL;

	free(copy);
	return (words); /*free when called*/
}
