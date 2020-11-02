#include "../cub3d.h"

void	set_ray(game_p *game, int pos)
{
	game->ray.cam_x = ((2 * pos) / (double)game->window.width) - 1;
	game->ray.dir_x = game->pers.dir_x + game->pers.plane_x * game->ray.cam_x;
	game->ray.dir_y = game->pers.dir_y + game->pers.plane_y * game->ray.cam_x;
	game->pers.map_x = (int)game->pers.x;
	game->pers.map_y = (int)game->pers.y;
	game->ray.deltaDistX = sqrt(1 + (game->ray.dir_y * game->ray.dir_y)
	/ (game->ray.dir_x * game->ray.dir_x));
	game->ray.deltaDistY = sqrt(1 + (game->ray.dir_x * game->ray.dir_x)
	/ (game->ray.dir_y * game->ray.dir_y));
	game->ray.hit = 0;
}

void	set_step_and_dist(game_p *game)
{
	if (game->ray.dir_x < 0)
	{
		game->ray.stepX = -1;
		game->ray.sideDistX = (game->pers.x - game->pers.map_x)
		* game->ray.deltaDistX;
	}
	else
	{
		game->ray.stepX = 1;
		game->ray.sideDistX = (game->pers.map_x + 1.0 - game->pers.x)
		* game->ray.deltaDistX;
	}
	if (game->ray.dir_y < 0)
	{
		game->ray.stepY = -1;
		game->ray.sideDistY = (game->pers.y - game->pers.map_y)
		* game->ray.deltaDistY;
	}
	else
	{
		game->ray.stepY = 1;
		game->ray.sideDistY = (game->pers.map_y + 1.0 - game->pers.y)
		* game->ray.deltaDistY;
	}
}

void	find_hit(game_p *game)
{
	while (game->ray.hit == 0)
	{
		if (game->ray.sideDistX < game->ray.sideDistY)
		{
			game->ray.sideDistX += game->ray.deltaDistX;
			game->pers.map_x += game->ray.stepX;
			game->ray.side = 0;
		}
		else
		{
			game->ray.sideDistY += game->ray.deltaDistY;
			game->pers.map_y += game->ray.stepY;
			game->ray.side = 1;
		}
		if (game->map.map_matrix[game->pers.map_y][game->pers.map_x] == '1')
			game->ray.hit = 1;
	}
}

void	count_perp(game_p *game)
{
	if (game->ray.side == 0)
	{
		game->ray.perpWallDist = (game->pers.map_x - game->pers.x +
		(1 - game->ray.stepX) / 2) / game->ray.dir_x;
		game->tex.wallX = game->pers.y + game->ray.perpWallDist *
		game->ray.dir_y;
	}
	else
	{
		game->ray.perpWallDist = (game->pers.map_y - game->pers.y
		+ (1 - game->ray.stepY) / 2) / game->ray.dir_y;
		game->tex.wallX = game->pers.x + game->ray.perpWallDist
		* game->ray.dir_x;
	}
	game->tex.wallX -= floor((game->tex.wallX));
	game->tex.drawStart = -(int)(game->window.height / game->ray.perpWallDist)
	/ 2 + game->window.height / 2;
	if (game->tex.drawStart < 0)
		game->tex.drawStart = 0;
	game->tex.drawEnd = (int)(game->window.height / game->ray.perpWallDist)
	/ 2 + game->window.height / 2;
	if (game->tex.drawEnd > game->window.height)
		game->tex.drawEnd = game->window.height;
}

void	choose_texture(game_p *game)
{
	if (game->ray.side == 1)
		game->tex.texture = game->map.south_texture;
	else
		game->tex.texture = game->map.east_texture;
	if (game->ray.side == 0 && game->ray.dir_x > 0)
	{
		game->tex.texture = game->map.west_texture;
		game->tex.texX = 64 - game->tex.texX - 1;
	}
	if (game->ray.side == 1 && game->ray.dir_y < 0)
	{
		game->tex.texture = game->map.north_texture;
		game->tex.texX = 64 - game->tex.texX - 1;
	}
}
