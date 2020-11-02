#include "../cub3d.h"
void	game_close(game_p *game)
{	
	free (game->map.map_matrix);
	free (game->perp_buffer);
	mlx_destroy_window(game->window.mlx_app, game->window.window_id);
	exit(0);
}

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

int		skip_by_func(int (*func)(int c), char *line)
{
	int counter;

	counter = 0;
	while (func(line[counter]))
		counter++;
	return (counter);
}
