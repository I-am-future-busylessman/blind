void    draw_player(game_p *game)
{
    game->cube.x = ceil(game->pers.x);
    game->cube.y = ceil(game->pers.y);
    game->cube.size_x = game->window.height/game->map.size_x;
    game->cube.size_y = game->window.height/game->map.size_x;
    game->cube.color = 0x0000FF00;
    draw_rect(game);
}

player_p    ray;
    float       start;
    float       end;
    double      hyp;
    int         pos;
    float       ang;

    pos = -1;
    ray = game->pers;
	start = ray.rot + PI/4;
    end = ray.rot - PI/4;
  while (++pos < game->window.width)
	{
		ray.x = game->pers.x;
		ray.y = game->pers.y;
		while (game->map.map_matrix[((int)(ray.y/game->scale_y))]
                                                [((int)(ray.x/game->scale_x))] != '1')
		{
			ray.x += cos(start);
			ray.y -= sin(start);
            //my_mlx_pixel_put(game, ray.x, ray.y, 0x00FF0000);
		}
        ang = start - game->pers.rot;
        //if (ang < 0)
        //    ang += 2*PI;
        //if (ang > 2*PI)
        //    ang -= 2*PI;
        hyp = hypot(ray.x - game->pers.x, ray.y - game->pers.y);
        game->cube.size_y = (int)(floor((game->window.height / (hyp * (round(cos(ang)*1000)/1000)) * game->scale_y)));
        //printf("\n\n\n%d\n%f\n", game->cube.size_y, hyp);
        if (game->cube.size_y > game->window.height)
            game->cube.size_y = game->window.height;
        game->cube.size_y = game->cube.size_y % 2 ? game->cube.size_y : game->cube.size_y - 1;  
        game->cube.x = (pos);
        game->cube.y = (game->window.height - game->cube.size_y) / 2;
        game->cube.size_x = 1;
        game->cube.color = 0x00FFFFFF;
        draw_rect(game);
		start -= PI / 2 / game->window.width;
	}



    game->ray.deltaDistX = (game->ray.dir_y == 0) ? 0 : ((game->ray.dir_x == 0) ? 1 : fabs(1 / game->ray.dir_x));
        game->ray.deltaDistY = (game->ray.dir_x == 0) ? 0 : ((game->ray.dir_y == 0) ? 1 : fabs(1 / game->ray.dir_y));