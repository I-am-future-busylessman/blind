#include "../cub3d.h"

char	*swap_symbols(char *str)
{
	int		counter;

	counter = -1;
	while (str[++counter])
	{
		if (str[counter] == ' ')
		{
			str[counter] = '1';
		}
	}
	return (str);
}

int		space_skip(char *new_str)
{
	int		counter;

	counter = 0;
	while (new_str[counter] == ' ')
		counter++;
	return (counter);
}
