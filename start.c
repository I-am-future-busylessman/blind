#include "cub3d.h"

int	main(int argc, char **argv)
{
	int		i;
	int		fd;
	game_p	game;

	if (argc == 3 && ft_namecheck(argv[1], "cub") && ft_savecheck(argv[2], "--save"))
		init(&game);
	else if (argc == 2 && ft_namecheck(argv[1], "cub"))
		init(&game);
	else
		write(2, "Error : Invalid arguments\n", 26);
	return (0);
	game.settings_file = "map.cub";
	game.error = 0;
	init(&game);
	if (game.error == 0)
	{
		display(&game);
		mlx_hook(game.window.window_id, 2, 1L << 0, key_bind, &game);
		mlx_loop(game.window.mlx_app);
	}
	game_close(&game);
	ft_printf("%d\n", game.error);
	return (0);
}
