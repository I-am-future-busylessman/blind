#include "../cub3d.h"
void    my_mlx_pixel_put(game_p *game, int x, int y, int color)
{
    char    *dst;

    dst = game->window.addr + (y * game->window.line_length + x * (game->window.bits_per_pixel / 8));
    *(unsigned int*)dst = color;
    
}

void    draw_rect(game_p *game)
{
    int move_x;
    int move_y;

    move_x = -1;
    while (++move_x < game->cube.size_x)
    {
        move_y = -1;
        while (++move_y < game->cube.size_y)
        {   
            if ((game->cube.x + move_x <= game->window.width) && (game->cube.x + move_x >= 0))
                my_mlx_pixel_put(game, game->cube.x + move_x, game->cube.y + move_y, game->cube.color);
        }
    }
}

void	cast_rays(game_p *game)
{
	int pos;

    pos = -1;

    game->perp_buffer = malloc(sizeof(double) * (game->window.width + 1));
    while (++pos <= game->window.width)
    {
        game->ray.cam_x = ((2 * pos) / (double)game->window.width) - 1;
        game->ray.dir_x = game->pers.dir_x + game->pers.plane_x * game->ray.cam_x;
        game->ray.dir_y = game->pers.dir_y + game->pers.plane_y * game->ray.cam_x;
        game->pers.map_x = (int)game->pers.x;
        game->pers.map_y = (int)game->pers.y;
        game->ray.deltaDistX = sqrt(1 + (game->ray.dir_y * game->ray.dir_y) / (game->ray.dir_x * game->ray.dir_x));
        game->ray.deltaDistY = sqrt(1 + (game->ray.dir_x * game->ray.dir_x) / (game->ray.dir_y * game->ray.dir_y));
        game->ray.hit = 0;
        if (game->ray.dir_x < 0)
        {
            game->ray.stepX = -1;
            game->ray.sideDistX = (game->pers.x - game->pers.map_x) * game->ray.deltaDistX;
        }
        else
        {
            game->ray.stepX = 1;
            game->ray.sideDistX = (game->pers.map_x + 1.0 - game->pers.x) * game->ray.deltaDistX;
        }
        if (game->ray.dir_y < 0)
        {
            game->ray.stepY = -1;
            game->ray.sideDistY = (game->pers.y - game->pers.map_y) * game->ray.deltaDistY;
        }
        else
        {
            game->ray.stepY = 1;
            game->ray.sideDistY = (game->pers.map_y + 1.0 - game->pers.y) * game->ray.deltaDistY;
        }
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
        if (game->ray.side == 0)
        {
            game->ray.perpWallDist = (game->pers.map_x - game->pers.x + (1 - game->ray.stepX) / 2) / game->ray.dir_x;
            game->tex.wallX = game->pers.y + game->ray.perpWallDist * game->ray.dir_y;
        }
        else
        {
            game->ray.perpWallDist = (game->pers.map_y - game->pers.y + (1 - game->ray.stepY) / 2) / game->ray.dir_y;
            game->tex.wallX = game->pers.x + game->ray.perpWallDist * game->ray.dir_x;
        }
        game->tex.wallX -= floor((game->tex.wallX));
        game->tex.drawStart = -(int)(game->window.height / game->ray.perpWallDist) / 2 + game->window.height / 2;

        if (game->tex.drawStart < 0)
            game->tex.drawStart = 0;
        game->tex.drawEnd = (int)(game->window.height / game->ray.perpWallDist) / 2 + game->window.height / 2;
            if (game->tex.drawEnd > game->window.height)
                game->tex.drawEnd = game->window.height;
        game->tex.texX = (int)(game->tex.wallX * (double)(64));

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
        game->tex.step = 1.0 * 64 / ((int)(game->window.height / game->ray.perpWallDist));
        game->tex.texPos = (game->tex.drawStart - game->window.height / 2) * game->tex.step;
        while (game->tex.drawStart < game->tex.drawEnd)
        {
            game->tex.texY = (int)game->tex.texPos + 32;
            game->tex.texPos += game->tex.step;
            my_mlx_pixel_put(game, pos, game->tex.drawStart, game->tex.texture[(64 * game->tex.texY ) + game->tex.texX]);
            game->tex.drawStart++;
        }
        game->perp_buffer[pos] = game->ray.perpWallDist;
    }
}

void    draw_map(game_p *game)
{
    int x;
    int y;

    y = -1;
    game->cube.size_x = game->scale_x;
    game->cube.size_y = game->scale_y;
    while (game->map.map_matrix[++y])
    {
        x = -1;
        while (game->map.map_matrix[y][++x])
        {
            game->cube.x = x * game->scale_x;
            game->cube.y = y * game->scale_y;
            if (game->map.map_matrix[y][x] == '1')
            {
                game->cube.color = 0x0000BFFF;
                draw_rect(game);
            }
            else if (game->map.map_matrix[y][x] == '2')
            {
                game->cube.color = 0x00000080;
                draw_rect(game);
            }
        }
    }
}

void    draw_player(game_p *game)
{
    game->cube.x = (int)(game->pers.x * game->scale_x);
    game->cube.y = (int)(game->pers.y * game->scale_y);
    game->cube.size_x = 5;
    game->cube.size_y = 5;
    game->cube.color = 0x0000FF00;
    draw_rect(game);
}

void    draw_background(game_p *game)
{
    game->cube.x = 0;
    game->cube.y = 0;
    game->cube.size_x = game->window.width;
    game->cube.size_y = game->window.height/2;
    game->cube.color = game->map.ceiling;
    draw_rect(game);
    game->cube.x = 0;
    game->cube.y = game->window.height/2;
    game->cube.size_x = game->window.width;
    game->cube.size_y = game->window.height/2;
    game->cube.color = game->map.floor;
    draw_rect(game);
}


void    cast_sprites(game_p *game)
{
    int     counter;
    int     stripe;
    int     i;
    counter = -1;
    while (++counter < game->sprite_count - 1)
    {
        game->sprite[counter].dist = ((game->pers.x - game->sprite[counter].x) * (game->pers.x - game->sprite[counter].x) + (game->pers.y - game->sprite[counter].y) * (game->pers.y - game->sprite[counter].y));
    }
    sort_sprites(game);
    counter = -1;
    while (++counter < game->sprite_count)
    {
        double  spriteX = game->sprite[counter].x - game->pers.x;
        double  spriteY = game->sprite[counter].y - game->pers.y;
        double  invDet = 1.0/(game->pers.plane_x*game->pers.dir_y - game->pers.dir_x * game->pers.plane_y);
        double  transformX = invDet * (game->pers.dir_y * spriteX - game->pers.dir_x * spriteY);
        double  transformY = invDet * ((-game->pers.plane_y * spriteX) + game->pers.plane_x * spriteY);
        int     spriteScreenX = (int)((game->window.width / 2) * (1 + transformX/transformY));
        int     spriteHeight = abs((int)(game->window.height/transformY));
        int     drawStart = -spriteHeight/2 + game->window.height / 2 ;
        if (drawStart < 0)
            drawStart = 0;
        int     drawEnd = spriteHeight/2 + game->window.height/2;
        if (drawEnd > game->window.height)
            drawEnd = game->window.height - 1;
        int     spriteWidth = abs((int)(game->window.height/transformY));
        int     drawStartX = -spriteWidth / 2 + spriteScreenX;
        if(drawStartX < 0) drawStartX = 0;
        int drawEndX = spriteWidth / 2 + spriteScreenX;
        if(drawEndX >= game->window.width) 
        drawEndX = game->window.width - 1;
        stripe = drawStartX - 1;
        while (++stripe < drawEndX)
        {
            int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * 64 / spriteWidth) / 256;
            if(transformY > 0 && stripe > 0 && stripe < game->window.width && transformY < game->perp_buffer[stripe])
            {
                i = drawStart - 1;
                while (++i < drawEnd)
                {
                    int d = (i) * 256 - game->window.height * 128 + spriteHeight * 128;
                    int texY = ((d * 64) / spriteHeight) / 256;
                    game->cube.color = game->map.sprite_texture[64 * texY + texX];
                    if ((game->cube.color & 0x00FFFFFF) != 0)
                        my_mlx_pixel_put(game, stripe, i, game->cube.color);
                }
            }
        }
    }

}

void    display(game_p *game)
{
    game->window.img = mlx_new_image(game->window.mlx_app, game->window.width,
                                    game->window.height);
    game->window.addr = mlx_get_data_addr(game->window.img, &game->window.bits_per_pixel,
                                         &game->window.line_length, &game->window.endian);
    draw_background(game);
    //draw_map(game);
    //draw_player(game);
    cast_rays(game);
    cast_sprites(game);
    mlx_put_image_to_window(game->window.mlx_app, game->window.window_id, game->window.img, 0, 0);
    free(game->window.addr);
    free(game->window.img);
}