#include "shell.h"

/**
 * err_env - func
 * @datash: pointer to shell var lib
 * Return: 1 on success null otherwise
 */
char *err_env(data_shell *datash)
{
	int length;
	char *error;
	char *v_str;
	char *msg;

	v_str = aux_itoa(datash->counter);
	msg = ": Unable to edit environ\n";
	length = _strlen(datash->av[0]) + _strlen(v_str);
	length += _strlen(datash->args[0]) + _strlen(msg) + 4;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(v_str);
		return (NULL);
	}

	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, v_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, msg);
	_strcat(error, "\0");
	free(v_str);

	return (error);
}
/**
 * err_path_X26 - function
 * @datash: pointer to var lib
 * Return: 1 on sccess else Null
 */
char *err_path_X26(data_shell *datash)
{
	int length;
	char *v_str;
	char *error;

	v_str = aux_itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(v_str);
	length += _strlen(datash->args[0]) + 24;
	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(error);
		free(v_str);
		return (NULL);
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, v_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, ": Access denied\n");
	_strcat(error, "\0");
	free(v_str);
	return (error);
}

