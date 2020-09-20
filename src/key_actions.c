#include "../cub3d.h"
#include <stdio.h>
void	game_close(game_p *game)
{
	mlx_destroy_window(game->window.mlx_app, game->window.window_id);
	exit(0);
}

void		check_valid_move(game_p *game, int dir)
{
	if (dir == 1)
	{
		if (game->map.map_matrix[(int)(game->pers.y + game->pers.dir_y*game->pers.moveSpeed)][(int)(game->pers.x)] != '1')
			game->pers.y += game->pers.dir_y*game->pers.moveSpeed;
		if (game->map.map_matrix[(int)(game->pers.y )][(int)(game->pers.x + game->pers.dir_x*game->pers.moveSpeed)] != '1')
			game->pers.x += game->pers.dir_x*game->pers.moveSpeed;
	}
	else if (dir == 2)
	{
		if (game->map.map_matrix[(int)(game->pers.y + game->pers.plane_y*game->pers.moveSpeed)][(int)(game->pers.x)] != '1')
			game->pers.y += game->pers.plane_y*game->pers.moveSpeed;
		if (game->map.map_matrix[(int)(game->pers.y )][(int)(game->pers.x + game->pers.plane_x*game->pers.moveSpeed)] != '1')
			game->pers.x += game->pers.plane_x*game->pers.moveSpeed;
	}
	else if (dir == 3)
	{
		if (game->map.map_matrix[(int)(game->pers.y - game->pers.dir_y*game->pers.moveSpeed)][(int)(game->pers.x)] != '1')
			game->pers.y -= game->pers.dir_y*game->pers.moveSpeed;
		if (game->map.map_matrix[(int)(game->pers.y )][(int)(game->pers.x - game->pers.dir_x*game->pers.moveSpeed)] != '1')
			game->pers.x -= game->pers.dir_x*game->pers.moveSpeed;
	}
	else if (dir == 4)
	{
		if (game->map.map_matrix[(int)(game->pers.y - game->pers.plane_y*game->pers.moveSpeed)][(int)(game->pers.x)] != '1')
			game->pers.y -= game->pers.plane_y*game->pers.moveSpeed;
		if (game->map.map_matrix[(int)(game->pers.y )][(int)(game->pers.x - game->pers.plane_x*game->pers.moveSpeed)] != '1')
			game->pers.x -= game->pers.plane_x*game->pers.moveSpeed;
	}
}

int		key_bind( int keycode, game_p *game)
{
	if (keycode == 124)
	{
		game->pers.old_dir_x = game->pers.dir_x;
		game->pers.dir_x = game->pers.dir_x * cos(-game->pers.rotSpeed) - game->pers.dir_y * sin(-game->pers.rotSpeed);
		game->pers.dir_y = game->pers.old_dir_x * sin(-game->pers.rotSpeed) + game->pers.dir_y * cos(-game->pers.rotSpeed);
		game->pers.old_plane_x = game->pers.plane_x;
		game->pers.plane_x = game->pers.plane_x * cos(-game->pers.rotSpeed) - game->pers.plane_y * sin(-game->pers.rotSpeed);
		game->pers.plane_y = game->pers.old_plane_x * sin(-game->pers.rotSpeed) + game->pers.plane_y * cos(-game->pers.rotSpeed);
	}
	else if (keycode == 123)
	{
		game->pers.old_dir_x = game->pers.dir_x;
		game->pers.dir_x = game->pers.dir_x * cos(game->pers.rotSpeed) - game->pers.dir_y * sin(game->pers.rotSpeed);
		game->pers.dir_y = game->pers.old_dir_x * sin(game->pers.rotSpeed) + game->pers.dir_y * cos(game->pers.rotSpeed);
		game->pers.old_plane_x = game->pers.plane_x;
		game->pers.plane_x = game->pers.plane_x * cos(game->pers.rotSpeed) - game->pers.plane_y * sin(game->pers.rotSpeed);
		game->pers.plane_y = game->pers.old_plane_x * sin(game->pers.rotSpeed) + game->pers.plane_y * cos(game->pers.rotSpeed);
	}
	if (keycode == 13)
		check_valid_move(game, 1);
	else if (keycode == 0)
		check_valid_move(game, 2);
	else if (keycode == 1)
		check_valid_move(game, 3);
	else if (keycode == 2)
		check_valid_move(game, 4);
	else if (keycode == 53)
	{
		game_close(game);
		return (0);
	}
	//printf("\n\n\n %f , %f", game->pers.y, game->pers.x);
	display(game);
	return (0);
}