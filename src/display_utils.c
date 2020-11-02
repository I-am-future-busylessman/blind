#include "../cub3d.h"

void	my_mlx_pixel_put(game_p *game, int x, int y, int color)
{
	char	*dst;

	dst = game->window.addr + (y * game->window.line_length
	+ x * (game->window.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_rect(game_p *game)
{
	int move_x;
	int move_y;

	move_x = -1;
	while (++move_x < game->cube.size_x)
	{
		move_y = -1;
		while (++move_y < game->cube.size_y)
		{
			if ((game->cube.x + move_x <= game->window.width)
			&& (game->cube.x + move_x >= 0))
				my_mlx_pixel_put(game, game->cube.x + move_x,
				game->cube.y + move_y, game->cube.color);
		}
	}
}
