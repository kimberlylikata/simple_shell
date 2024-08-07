#include "shell.h"

/**
 * get_err - func gets err
 * @datash: pointer to sh lib
 * @eval: pointer to ev
 * Return: ret eval else NULL
 */
int get_err(data_shell *datash, int eval)
{
	char *err;

	switch (eval)
	{
	case -1:
		err = err_env(datash);
		break;
	case 126:
		err = err_path_X26(datash);
		break;
	case 127:
		err = err_404(datash);
		break;
	case 2:
		if (_strcmp("exit", datash->args[0]) == 0)
			err = err_xshell(datash);
		else if (_strcmp("cd", datash->args[0]) == 0)
			err = err_get_cd(datash);
		break;
	}

	if (err)
	{
		write(STDERR_FILENO, err, _strlen(err));
		free(err);
	}

	datash->status = eval;
	return (eval);
}

