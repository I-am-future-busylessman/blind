#include "cub3d.h"
int    main(int argc, char **argv)
{
    int     i;
    int     fd;
    game_p  game;

    game.settings_file = "map.cub";
    init(&game);
    if (game.error == 0)
    {
        display(&game);
        mlx_hook(game.window.window_id, 2, 1L<<0, key_bind, &game);
        mlx_loop(game.window.mlx_app);
    }
    ft_printf("%d\n", game.error);
    return (0);
}