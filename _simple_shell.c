#include "_simple_shell.h"
/**
 * print_2d - function that print an array
 * @Array: the array want to print
 */
void print_2d(char **Array)
{
	int it = 0;

	if (Array == NULL)
		return;

	while (Array[it])
	{
		puts(Array[it]);
		it++;
	}
}
/**
 * start_shell - function that start the shell
 *
 */
void start_shell(void)
{
	int nread = 0;

	do {
		nread = *((int *)reader(READ));

		if (nread <= 0)
		{
			reader(FREE);
			if (nread == 1)
			{
				inc_line_index();
				continue;
			}

			if (nread == -1 || nread == INTRPT_CODE)
				break;
		}

		if (nread > 0)
		{
			reader(TOKENIZE);
			_exec();
		}

		reader(FREE);
		inc_line_index();
	} while (nread >= 0);
}
/**
 * shell_atoi - the function atoi the number
 * @ascii: the ascii sign or the argument
 * Return: NULL or the number
 */
void *shell_atoi(char *ascii)
{
	int *r, it, unit, tmp;

	if (ascii == NULL)
		return (NULL);

	r = malloc(sizeof(int));
	tmp  = 0;
	unit = 1;
	it   = (_strlen(ascii) - 1);
	while (it >= 0)
	{
		if (it == 0)
		{
			if (ascii[it] == '-')
			{
				tmp *= (-1);
				*r = tmp;
				return (r);
			}
		}

		if (ascii[it] >= '0' && ascii[it] <= '9')
		{
			tmp += ((int)(ascii[it] - '0')) * unit;
			unit *= 10;
			it--;
			continue;
		}

		free(r);
		return (NULL);
	}

	*r = tmp;
	return (r);
}
