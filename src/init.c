#include "../cub3d.h"

void	init_sprite_draw(game_p *game)
{
	game->sprite_draw.spriteX = 0;
	game->sprite_draw.spriteY = 0;
	game->sprite_draw.invDet = 0;
	game->sprite_draw.trX = 0;
	game->sprite_draw.trY = 0;
	game->sprite_draw.sprScX = 0;
	game->sprite_draw.spriteHeight = 0;
	game->sprite_draw.drawStart = 0;
	game->sprite_draw.drawEnd = 0;
	game->sprite_draw.spriteWidth = 0;
	game->sprite_draw.drawStartX = 0;
	game->sprite_draw.drawEndX = 0;
	game->sprite_draw.texX = 0;
	game->sprite_draw.d = 0;
	game->sprite_draw.texY = 0;
}

void	init_player(game_p *game)
{
	game->pers.count = 0;
	game->pers.dir_x = 0;
	game->pers.dir_y = 0;
	game->pers.x = 0;
	game->pers.y = 0;
	game->pers.plane_x = -0.7;
	game->pers.plane_y = 0.7;
	game->pers.moveSpeed = 0.2;
	game->pers.rotSpeed = -PI / 90;
}

int		init_map(game_p *game)
{
	game->map.size_x = -1;
	game->map.ceiling = -1;
	game->map.floor = -1;
	game->window.width = -1;
	game->window.height = -1;
	game->sprite_count = 0;
	if (start_parser(game) < 0)
		return (game->error);
	return (0);
}

int	init(game_p *game)
{
	game->map.map_list = NULL;
	init_player(game);
	game->window.mlx_app = mlx_init();
	if (init_map(game) < 0)
		return (game->error);
	game->perp_buffer = malloc(sizeof(double) * (game->window.width + 1));
	init_sprite_draw(game);
	if (game->sprite_count > 0)
		sprite_set(game);
	game->window.window_id = mlx_new_window(game->window.mlx_app,
											game->window.width,
											game->window.height,
											"Cub3D");
	game->ray.hit = 0;
	game->pers.plane_y *= game->pers.dir_x;
	game->pers.plane_x *= game->pers.dir_y;
	game->scale_x = game->window.width / game->map.size_x;
	game->scale_y = game->window.height / game->map.size_y;
	return (0);
}
