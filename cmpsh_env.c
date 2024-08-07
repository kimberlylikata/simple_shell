#include "shell.h"

/**
 * cmp_envnm - func
 * @nenv: pointer
 * @name: pointer to nm
 *Return: new env
 */
int cmp_envnm(const char *nenv, const char *name)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * _getenv -func gets env
 * @name: pointr to nm
 * @_environ: pointer to env
 * Return: rets env
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int i, mov;

	ptr_env = NULL;
	mov = 0;
	/* */
	/*  */
	for (i = 0; _environ[i]; i++)
	{
		/* mov to get environ array*/
		mov = cmp_envnm(_environ[i], name);
		if (mov)
		{
			ptr_env = _environ[i];
			break;
		}
	}

	return (ptr_env + mov);
}

/**
 * _env - func envir
 * @datash: pointer to var
 * Return: rets env
 */
int _env(data_shell *datash)
{
	int i, j;

	for (i = 0; datash->_environ[i]; i++)
	{

		for (j = 0; datash->_environ[i][j]; j++)
			;

		write(STDOUT_FILENO, datash->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}

