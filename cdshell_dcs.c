#include "shell.h"

/**
* cd_shell - func changes dir
* @datash: pointer to vars in shell  lib
* Return: rets new dir
*/
int cd_shell(data_shell *datash)
{
	char *dir;

	int ishomepg, ishomepg1, isellipsis;

	dir = datash->args[1];

	if (dir != NULL)
	{
		ishomepg = _strcmp("$HOME", dir);
		ishomepg1 = _strcmp("~", dir);
		isellipsis = _strcmp("--", dir);
	}

	if (dir == NULL || !ishomepg || !ishomepg1 || !isellipsis)
	{
		cd_to_home(datash);
		return (1);
	}

	if (_strcmp("-", dir) == 0)
	{
		cd_previous(datash);
		return (1);
	}

	if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
	{
		cd_dot(datash);
		return (1);
	}

	cd_to(datash);

	return (1);
}

