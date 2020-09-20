#include "../cub3d.h"

void    sort_sprites(game_p *game)
{
	spr_p	tmp;
	int		i;
	int		j;

	i = 0;
	while (i < game->sprite_count - 1)
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
		i++;
	}
}
    

void    sprite_set(game_p *game)
{
    size_t  x_pos;
    size_t  y_pos;
    char    **matrix;
    int     counter;

    counter = 0;
    matrix = game->map.map_matrix;
    y_pos = -1;
    game->sprite = malloc(sizeof(sprite_set) * (game->sprite_count + 1));
    while (matrix[++y_pos])
    {
       x_pos = -1;
       while (matrix[y_pos][++x_pos])
       {
            if (matrix[y_pos][x_pos] == '2')
            {
                game->sprite[counter].y = y_pos;
                game->sprite[counter].x = x_pos;
                game->sprite[counter].dist = ((game->pers.x - game->sprite[counter].x) * (game->pers.x - game->sprite[counter].x) + (game->pers.y - game->sprite[counter].y) * (game->pers.y - game->sprite[counter].y));
                counter++;
            }
       }
    }
    sort_sprites(game);
}

void    init_player(game_p *game)
{
    game->pers.count = 0;
    game->pers.dir_x = 0;
    game->pers.dir_y = 0;
    game->pers.x = 0;
    game->pers.y = 0;
    game->pers.plane_x = 0;
    game->pers.plane_y = 0.66;
    game->pers.moveSpeed = 0.2;
    game->pers.rotSpeed = - PI/90;
}

int     init_map(game_p *game)
{
    game->map.size_x = -1;
    game->map.ceiling = -1;
    game->map.floor = -1;
    game->window.width = -1;
    game->window.height = -1;
    game->sprite_count = 0;
    if(start_parser(game) < 0)
        return(game->error);
    return(0);
}

void    init(game_p *game)
{
    int error;

    game->map.map_list = NULL;
    init_player(game);
    game->window.mlx_app = mlx_init();
    error = init_map(game);
    //sprite_set(game);
    game->window.window_id = mlx_new_window(game->window.mlx_app, game->window.width,
                                            game->window.height, "Cub3D");
    game->ray.hit = 0;
    game->scale_x = game->window.width/game->map.size_x;
    game->scale_y = game->window.height/game->map.size_y;
    print_parsed(game);
}