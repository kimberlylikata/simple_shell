#include "shell.h"

/**
 * strcatcd - func
 * @datash: pointer to shell lib
 * @msg: pointer to dialog
 * @error: pointer to otherwse
 * @v_str: pointer to var
 * Return: ret
 */
char *strcatcd(data_shell *datash, char *msg, char *error, char *v_str)
{
	char *alien_flag;

	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, v_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, msg);
	if (datash->args[1][0] == '-')
	{
		alien_flag = malloc(3);
		alien_flag[0] = '-';
		alien_flag[1] = datash->args[1][1];
		alien_flag[2] = '\0';
		_strcat(error, alien_flag);
		free(alien_flag);
	}
	else
	{
		_strcat(error, datash->args[1]);
	}

	_strcat(error, "\n");
	_strcat(error, "\0");
	return (error);
}

/**
 * err_get_cd - func
 * @datash:  pointer
 * Return: success dir
 */
char *err_get_cd(data_shell *datash)
{
	int length, len_id;
	char *error, *v_str, *msg;

	v_str = aux_itoa(datash->counter);
	if (datash->args[1][0] == '-')
	{
		msg = ": Alien optn ";
		len_id = 2;
	}
	else
	{
		msg = "cd fail ";
		len_id = _strlen(datash->args[1]);
	}

	length = _strlen(datash->av[0]) + _strlen(datash->args[0]);
	length += _strlen(v_str) + _strlen(msg) + len_id + 5;
	error = malloc(sizeof(char) * (length + 1));

	if (error == 0)
	{
		free(v_str);
		return (NULL);
	}

	error = strcatcd(datash, msg, error, v_str);

	free(v_str);

	return (error);
}

/**
 * err_404 - function giver err
 * @datash:pointer
 * Return: msg
 */
char *err_404(data_shell *datash)
{
	int length;
	char *error;
	char *v_str;

	v_str = aux_itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(ver_str);
	length += _strlen(datash->args[0]) + 16;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, ": not found\n");
	_strcat(error, "\0");
	free(v_str);
	return (error);
}

/**
 * err_xshell - function to exit shell
 * @datash: pointer
 * Return: ret
 */
char *err_xshell(data_shell *datash)
{
	int length;
	char *error;
	char *v_str;

	v_str = aux_itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(v_str);
	length += _strlen(datash->args[0]) + _strlen(datash->args[1]) + 23;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(v_str);
		return (NULL);
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, v_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, ": Alien no.: ");
	_strcat(error, datash->args[1]);
	_strcat(error, "\n\0");
	free(v_str);

	return (error);
}

