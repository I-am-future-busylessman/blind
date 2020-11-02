#include "../cub3d.h"

void	sort_sprites(game_p *game)
{
	spr_p	tmp;
	int		i;
	int		j;

	i = -1;
	while (++i < game->sprite_count)
		game->sprite[i].dist = ((game->pers.x - game->sprite[i].x)
		* (game->pers.x - game->sprite[i].x) + (game->pers.y
		- game->sprite[i].y) * (game->pers.y - game->sprite[i].y));
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

void	set_sprite_draw(game_p *game, int counter)
{
	spr_d_p		sd;
	player_p	p;

	p = game->pers;
	sd = game->sprite_draw;
	sd.spriteX = game->sprite[counter].x - p.x;
	sd.spriteY = game->sprite[counter].y - p.y;
	sd.invDet = 1.0 / (p.plane_x * p.dir_y - p.dir_x * p.plane_y);
	sd.trX = sd.invDet * (p.dir_y * sd.spriteX - p.dir_x * sd.spriteY);
	sd.trY = sd.invDet * ((-p.plane_y * sd.spriteX) + p.plane_x * sd.spriteY);
	sd.sprScX = (int)((game->window.width / 2) * (1 + sd.trX / sd.trY));
	sd.spriteHeight = abs((int)(game->window.height / sd.trY));
	sd.drawStart = -sd.spriteHeight / 2 + game->window.height / 2;
	if (sd.drawStart < 0)
		sd.drawStart = 0;
	sd.drawEnd = sd.spriteHeight / 2 + game->window.height / 2;
	if (sd.drawEnd > game->window.height)
		sd.drawEnd = game->window.height - 1;
	sd.spriteWidth = abs((int)(game->window.height / sd.trY));
	sd.drawStartX = -sd.spriteWidth / 2 + sd.sprScX;
	if (sd.drawStartX < 0)
		sd.drawStartX = 0;
	sd.drawEndX = sd.spriteWidth / 2 + sd.sprScX;
	if (sd.drawEndX >= game->window.width)
		sd.drawEndX = game->window.width - 1;
	game->pers = p;
	game->sprite_draw = sd;
}

void	draw_sprite(game_p *game, int stripe)
{
	int		i;

	i = game->sprite_draw.drawStart - 1;
	while (++i < game->sprite_draw.drawEnd)
	{
		game->sprite_draw.d = (i) * 256 - game->window.height
		* 128 + game->sprite_draw.spriteHeight * 128;
		game->sprite_draw.texY = ((game->sprite_draw.d * 64)
		/ game->sprite_draw.spriteHeight) / 256;
		game->cube.color = game->map.sprite_texture[64
		* game->sprite_draw.texY + game->sprite_draw.texX];
		if ((game->cube.color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(game, stripe, i, game->cube.color);
	}
}
