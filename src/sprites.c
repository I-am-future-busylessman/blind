#include "../cub3d.h"

void	sort_sprites(game_p *game)
{
	spr_p	tmp;
	int		i;
	int		j;

	i = -1;
	while (i++ < game->sprite_count)
	{
		j = i + 1;
		while (j < game->sprite_count)
		{
			if (game->sprite[i].dist < game->sprite[j].dist)
			{
				tmp = game->sprite[i];
				game->sprite[i] = game->sprite[j];
				game->sprite[j] = tmp;
			}
			j++;
		}
	}
}

void	sprite_set(game_p *game)
{
	size_t	x_pos;
	size_t	y_pos;
	int		i;

	i = 0;
	y_pos = -1;
	game->sprite = malloc(sizeof(spr_p) * (game->sprite_count));
	while (game->map.map_matrix[++y_pos])
	{
		x_pos = -1;
		while (game->map.map_matrix[y_pos][++x_pos])
		{
			if (game->map.map_matrix[y_pos][x_pos] == '2')
			{
				game->sprite[i].y = y_pos + 0.5;
				game->sprite[i].x = x_pos + 0.5;
				game->sprite[i].dist = ((game->pers.x - game->sprite[i].x)
				* (game->pers.x - game->sprite[i].x)
				+ (game->pers.y - game->sprite[i].y)
				* (game->pers.y - game->sprite[i].y));
				i++;
			}
		}
	}
	sort_sprites(game);
}
