#include "../cub3d.h"

void    print_parsed(game_p *game)
{
    int x;
  
    printf("%d\n", game->window.width);
    printf("%d\n", game->window.height);
    printf("%d\n", game->scale_x);
    printf("%d\n", game->scale_y);
    printf("%d\n", game->map.size_x);
    printf("%d\n", game->map.size_y);
    printf("%d\n", game->map.floor);
    printf("%d\n", game->map.ceiling);
    printf("%f\n", game->pers.x);
    printf("%f\n", game->pers.y);
    
    x = -1;
    while (game->map.map_matrix[++x])
    {
       printf("%s\n", game->map.map_matrix[x]);
    }
    printf("\n\n\n\n\n");
}

int     create_rgb(int r, int g, int b, int side, game_p *game)
{
	if (side == 1)
        game->map.floor = (r << 16 | g << 8 | b);
    else
        game->map.ceiling = (r << 16 | g << 8 | b); 
    return (0);
}

char    *swap_symbols(char *str)
{
    int counter;

    counter = -1;
    while (str[++counter])
    {
        if (str[counter] == ' ')
        {
            str[counter] = '1';
        }
    }
    return (str);
}

int     space_skip(char *new_str)
{
    int     counter;

    counter = 0;
    while (new_str[counter] == ' ')
        counter++;
    return (counter);
}