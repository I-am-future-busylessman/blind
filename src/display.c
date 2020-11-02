#include "../cub3d.h"

void	cast_rays(game_p *game)
{
	int pos;

	pos = -1;
	while (++pos <= game->window.width)
	{
		set_ray(game, pos);
		set_step_and_dist(game);
		find_hit(game);
		count_perp(game);
		choose_texture(game);
		game->tex.texX = (int)(game->tex.wallX * (double)(64));
		game->tex.step = 1.0 * 64 / ((int)(game->window.height
		/ game->ray.perpWallDist));
		game->tex.texPos = (game->tex.drawStart
		- game->window.height / 2) * game->tex.step;
		while (game->tex.drawStart < game->tex.drawEnd)
		{
			game->tex.texY = (int)game->tex.texPos + 32;
			game->tex.texPos += game->tex.step;
			my_mlx_pixel_put(game, pos, game->tex.drawStart,
			game->tex.texture[(64 * game->tex.texY) + game->tex.texX]);
			game->tex.drawStart++;
		}
		game->perp_buffer[pos] = game->ray.perpWallDist;
	}
}

void	draw_background(game_p *game)
{
	game->cube.x = 0;
	game->cube.y = 0;
	game->cube.size_x = game->window.width;
	game->cube.size_y = game->window.height / 2;
	game->cube.color = game->map.ceiling;
	draw_rect(game);
	game->cube.x = 0;
	game->cube.y = game->window.height / 2;
	game->cube.size_x = game->window.width;
	game->cube.size_y = game->window.height / 2;
	game->cube.color = game->map.floor;
	draw_rect(game);
}

void	cast_sprites(game_p *game)
{
	int		counter;
	int		stripe;

	sort_sprites(game);
	counter = -1;
	while (++counter < game->sprite_count)
	{
		set_sprite_draw(game, counter);
		stripe = game->sprite_draw.drawStartX - 1;
		while (++stripe < game->sprite_draw.drawEndX)
		{
			game->sprite_draw.texX = (int)(256
			* (stripe - (-game->sprite_draw.spriteWidth
			/ 2 + game->sprite_draw.sprScX)) * 64
			/ game->sprite_draw.spriteWidth) / 256;
			if (game->sprite_draw.trY > 0 && stripe > 0
			&& stripe < game->window.width
			&& game->sprite_draw.trY < game->perp_buffer[stripe])
			{
				draw_sprite(game, stripe);
			}
		}
	}
}

void	display(game_p *game)
{
	game->window.img = mlx_new_image(game->window.mlx_app, game->window.width,
	game->window.height);
	game->window.addr = mlx_get_data_addr(game->window.img,
	&game->window.bits_per_pixel,
	&game->window.line_length, &game->window.endian);
	draw_background(game);
	cast_rays(game);
	cast_sprites(game);
	mlx_put_image_to_window(game->window.mlx_app,
	game->window.window_id, game->window.img, 0, 0);
	free(game->window.addr);
	free(game->window.img);
}
