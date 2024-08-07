#include "shell.h"

/**
* rev_str- func revs str
* @s:  pointer to str
* Return:  returns revd str
*/

void rev_str(char *s)
{
	int count = 0, i, j;

	char *str, temp;

	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}
	str = s;

	for (i = 0; i < (count - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			temp = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = temp;
		}
	}
}

