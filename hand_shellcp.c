#include "shell.h"

/**
* cp_data - func copies inf
* @name: pointer to str
* @value: pointer to val
* Return: rets new
*/
char *cp_data(char *name, char *value)
{
	char *new;

	int len_nm, len_val, len;

	len_nm = _strlen(name);
	len_val = _strlen(value);
	len = len_nm + len_val + 2;
	new = malloc(sizeof(char) * (len));
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);
	_strcat(new, "\0");

	return (new);
}

/**
* set_env - func
* @name: pointer to str
* @value: pointr to vl
* @datash:pointer to shll voc
* Return: ret 1 else null
*/
void set_env(char *name, char *value, data_shell *datash)
{
	int i;

	char *var_env, *name_env;

	for (i = 0; datash->_environ[i]; i++)
	{
		var_env = _strdup(datash->_environ[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, name) == 0)
		{
			free(datash->_environ[i]);
			datash->_environ[i] = cp_data(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	datash->_environ = _reallocdp(datash->_environ, i, sizeof(char *) * (i + 2));
	datash->_environ[i] = cp_data(name, value);
	datash->_environ[i + 1] = NULL;
}

/**
* _setenv - func sts env
* @datash: pointer to shell lib
* Return: env
*/
int _setenv(data_shell *datash)
{

	if (datash->args[1] == NULL || datash->args[2] == NULL)
	{
		get_error(datash, -1);
		return (1);
	}

	set_env(datash->args[1], datash->args[2], datash);

	return (1);
}

/**
* _unsetenv - func unsets env
* @datash: pointer to lib sh
* Return: unsets env
*/
int _unsetenv(data_shell *datash)
{
	char **realloc_environ;
	char *var_env, *name_env;

	int i, j, k;

	if (datash->args[1] == NULL)
	{
		get_error(datash, -1);
		return (1);
	}
	k = -1;
	for (i = 0; datash->_environ[i]; i++)
	{
		var_env = _strdup(datash->_environ[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, datash->args[1]) == 0)
		{
			k = i;
		}
		free(var_env);
	}
	if (k == -1)
	{
		get_error(datash, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (i));
	for (i = j = 0; datash->_environ[i]; i++)
	{
		if (i != k)
		{
			realloc_environ[j] = datash->_environ[i];
			j++;
		}
	}
	realloc_environ[j] = NULL;
	free(datash->_environ[k]);
	free(datash->_environ);
	datash->_environ = realloc_environ;
	return (1);
}

