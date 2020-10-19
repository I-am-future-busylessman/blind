#include "../cub3d.h"

void	turn_right(game_p *game)
{
	game->pers.old_dir_x = game->pers.dir_x;
	game->pers.dir_x = game->pers.dir_x * cos(-game->pers.rotSpeed)
	- game->pers.dir_y * sin(-game->pers.rotSpeed);
	game->pers.dir_y = game->pers.old_dir_x * sin(-game->pers.rotSpeed)
	+ game->pers.dir_y * cos(-game->pers.rotSpeed);
	game->pers.old_plane_x = game->pers.plane_x;
	game->pers.plane_x = game->pers.plane_x * cos(-game->pers.rotSpeed)
	- game->pers.plane_y * sin(-game->pers.rotSpeed);
	game->pers.plane_y = game->pers.old_plane_x * sin(-game->pers.rotSpeed)
	+ game->pers.plane_y * cos(-game->pers.rotSpeed);
}

void	turn_left(game_p *game)
{
	game->pers.old_dir_x = game->pers.dir_x;
	game->pers.dir_x = game->pers.dir_x * cos(game->pers.rotSpeed)
	- game->pers.dir_y * sin(game->pers.rotSpeed);
	game->pers.dir_y = game->pers.old_dir_x * sin(game->pers.rotSpeed)
	+ game->pers.dir_y * cos(game->pers.rotSpeed);
	game->pers.old_plane_x = game->pers.plane_x;
	game->pers.plane_x = game->pers.plane_x * cos(game->pers.rotSpeed)
	- game->pers.plane_y * sin(game->pers.rotSpeed);
	game->pers.plane_y = game->pers.old_plane_x * sin(game->pers.rotSpeed)
	+ game->pers.plane_y * cos(game->pers.rotSpeed);
}

void	check_left_right_move(game_p *game, int dir)
{
	if (dir == 0)
	{
		if (game->map.map_matrix[(int)(game->pers.y - game->pers.plane_y
		* game->pers.moveSpeed)][(int)(game->pers.x)] != '1')
			game->pers.y -= game->pers.plane_y * game->pers.moveSpeed;
		if (game->map.map_matrix[(int)(game->pers.y)][(int)(game->pers.x
		- game->pers.plane_x * game->pers.moveSpeed)] != '1')
			game->pers.x -= game->pers.plane_x * game->pers.moveSpeed;
	}
	else if (dir == 2)
	{
		if (game->map.map_matrix[(int)(game->pers.y + game->pers.plane_y
		* game->pers.moveSpeed)][(int)(game->pers.x)] != '1')
			game->pers.y += game->pers.plane_y * game->pers.moveSpeed;
		if (game->map.map_matrix[(int)(game->pers.y)][(int)(game->pers.x
		+ game->pers.plane_x * game->pers.moveSpeed)] != '1')
			game->pers.x += game->pers.plane_x * game->pers.moveSpeed;
	}
}

void	check_valid_move(game_p *game, int dir)
{
	if (dir == 13)
	{
		if (game->map.map_matrix[(int)(game->pers.y + game->pers.dir_y
		* game->pers.moveSpeed)][(int)(game->pers.x)] != '1')
			game->pers.y += game->pers.dir_y * game->pers.moveSpeed;
		if (game->map.map_matrix[(int)(game->pers.y)][(int)(game->pers.x
		+ game->pers.dir_x * game->pers.moveSpeed)] != '1')
			game->pers.x += game->pers.dir_x * game->pers.moveSpeed;
	}
	else if (dir == 1)
	{
		if (game->map.map_matrix[(int)(game->pers.y - game->pers.dir_y
		* game->pers.moveSpeed)][(int)(game->pers.x)] != '1')
			game->pers.y -= game->pers.dir_y * game->pers.moveSpeed;
		if (game->map.map_matrix[(int)(game->pers.y)][(int)(game->pers.x
		- game->pers.dir_x * game->pers.moveSpeed)] != '1')
			game->pers.x -= game->pers.dir_x * game->pers.moveSpeed;
	}
	else
		check_left_right_move(game, dir);
}

int		key_bind(int keycode, game_p *game)
{
	if (keycode == 123)
		turn_left(game);
	else if (keycode == 124)
		turn_right(game);
	else if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
		check_valid_move(game, keycode);
	else if (keycode == 53)
	{
		mlx_destroy_window(game->window.mlx_app, game->window.window_id);
		exit(0);
		return (0);
	}
	display(game);
	return (0);
}
