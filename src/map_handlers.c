#include "../cub3d.h"

void    place_player(char elem, int x_pos, int y_pos, game_p *game)
{
    game->pers.x = x_pos;
    game->pers.y = y_pos;
    game->pers.count = 1;
    if (elem == 'N')
    {
        game->pers.dir_x = 0;
        game->pers.dir_y = 1;
    }
    else if (elem == 'S')
    {
        game->pers.dir_x = 0;
        game->pers.dir_y = -1;
    }
    else if (elem == 'W')
    {
        game->pers.dir_x = -1;
        game->pers.dir_y = 0;
    }
    else 
    {
        game->pers.dir_x = 1;
        game->pers.dir_y = 0;
    }
}

int     lst_parse(game_p *game)
{
    int counter;

    counter = 0;
    game->map.size_y = ft_lstsize(game->map.map_list) + 1 ;
    if (!(game->map.map_matrix = malloc(sizeof(char *) * ft_lstsize(game->map.map_list) + 1)))
    {
        free(game->map.map_matrix);
        return(game->error = -101);
    }
    while (game->map.map_list)
    {
        game->map.map_matrix[counter] = ft_strdup(game->map.map_list->content);
        counter++;
        game->map.map_list = game->map.map_list->next;
    }
    game->map.map_matrix[counter] = NULL;
    return (0);
}

int map_collector(char *new_str, game_p *game, int status)
{
    int len;

    len = ft_strlen(new_str);
    ft_lstadd_back(&game->map.map_list,ft_lstnew(swap_symbols(new_str)));
    if (len > game->map.size_x)
        game->map.size_x = len;
    if (status == 1)
    {
        if(lst_parse(game) < 0)
            return(game->error);
        if (map_checker(game) < 0)
            return(game->error);
    }
    return(0);
}