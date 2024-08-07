#include "shell.h"

/**
 * rpt_char - func rpts char
 * @input: points to inp
 * @i: points to str
 * Return: rets char
 */
int rpt_char(char *input, int i)
{
	if (*(input - 1) == *input)
		return (rpt_char(input - 1, i + 1));

	return (i);
}

/**
 * err_sep - func
 * @input: points to inp
 * @i: points to str
 * @last: points to lst
 * Return: rets i
 */
int err_sep(char *input, int i, char last)
{
	int count;

	count = 0;
	if (*input == '\0')
		return (0);

	if (*input == ' ' || *input == '\t')
		return (err_sep(input + 1, i + 1, last));

	if (*input == ';')
		if (last == '|' || last == '&' || last == ';')
			return (i);

	if (*input == '|')
	{
		if (last == ';' || last == '&')
			return (i);

		if (last == '|')
		{
			count = rpt_char(input, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}

	if (*input == '&')
	{
		if (last == ';' || last == '|')
			return (i);

		if (last == '&')
		{
			count = rpt_char(input, 0);
			if (count == 0 || count > 1)
				return (i);
		}
	}

	return (err_sep(input + 1, i + 1, *input));
}

/**
 * first_char - func
 * @input: pointer to inp
 * @i:points to str
 * Return: rets f
 */
int first_char(char *input, int *i)
{
	for (*i = 0; input[*i]; *i += 1)
	{
		if (input[*i] == ' ' || input[*i] == '\t')
			continue;

		if (input[*i] == ';' || input[*i] == '|' || input[*i] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * disp_synterr - funct
 * @datash: pointerf to shell lb
 * @input: pointer to in
 * @i: points to str
 * @bool: bool
 * Return: rets synterr
 */
void disp_synterr(data_shell *datash, char *input, int i, int bool)
{
	char *msg, *msg2, *msg3, *error, *counter;
	int length;

	if (input[i] == ';')
	{
		if (bool == 0)
			msg = (input[i + 1] == ';' ? ";;" : ";");
		else
			msg = (input[i - 1] == ';' ? ";;" : ";");
	}

	if (input[i] == '|')
		msg = (input[i + 1] == '|' ? "||" : "|");

	if (input[i] == '&')
		msg = (input[i + 1] == '&' ? "&&" : "&");

	msg2 = ": SYNTAX ERROR! \"";
	msg3 = "\"UNEXPECTED ERR\n";
	counter = aux_itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(counter);
	length += _strlen(msg) + _strlen(msg2) + _strlen(msg3) + 2;

	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(counter);
		return;
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, counter);
	_strcat(error, msg2);
	_strcat(error, msg);
	_strcat(error, msg3);
	_strcat(error, "\0");

	write(STDERR_FILENO, error, length);
	free(error);
	free(counter);
}

/**
 * trace_synterr - func traces syny err
 * @datash: points to lib shell
 * @input: points to inp
 * Return: rets err
 */
int trace_synterr(data_shell *datash, char *input)
{
	int begin = 0;
	int fchar = 0;
	int i = 0;

	fchar = first_char(input, &begin);
	if (fchar == -1)
	{
		disp_synterr(datash, input, begin, 0);
		return (1);
	}

	i = err_sep(input + begin, 0, *(input + begin));
	if (i != 0)
	{
		disp_synterr(datash, input, begin + i, 1);
		return (1);
	}

	return (0);
}

