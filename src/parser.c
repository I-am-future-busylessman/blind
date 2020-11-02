#include "../cub3d.h"

int		config_check(game_p *game)
{
	if (game->map.north_texture == NULL
		|| game->map.south_texture == NULL
		|| game->map.west_texture == NULL
		|| game->map.east_texture == NULL
		|| game->map.sprite_texture == NULL
		|| game->map.ceiling < 0
		|| game->map.floor < 0
		|| game->window.height < 0
		|| game->window.width < 0)
		return (game->error = -300);
	return (0);
}

int		line_identify_2(char *new_str, game_p *game, int skipped)
{
	if (new_str[skipped] == 'E')
		return (texture_checker(new_str + skipped, game, 4));
	else if (new_str[skipped] == 'S')
		return (texture_checker(new_str + skipped, game, 5));
	else if (new_str[skipped] == 'F')
		return (color_checker(new_str + skipped + 1, game, 1));
	else if (new_str[skipped] == 'C')
		return (color_checker(new_str + skipped + 1, game, 2));
	else
		return (0);
}

int		line_identify(char *new_str, game_p *game)
{
	int		skipped;

	skipped = space_skip(new_str);
	if (new_str[skipped] == '1')
	{
		if (config_check(game))
			return (game->error);
		return (map_collector(new_str, game));
	}
	else if (new_str[skipped] == 'R')
		return (resolution_checker(new_str + skipped, game));
	else if (new_str[skipped] == 'N')
		return (texture_checker(new_str + skipped, game, 1));
	else if (new_str[skipped] == 'S' && new_str[skipped + 1] == 'O')
		return (texture_checker(new_str + skipped, game, 2));
	else if (new_str[skipped] == 'W')
		return (texture_checker(new_str + skipped, game, 3));
	return (line_identify_2(new_str, game, skipped));
}

int		start_parser(game_p *game)
{
	char	*new_str;
	int		file_descriptor;

	file_descriptor = open(game->settings_file, O_RDONLY);
	new_str = NULL;
	while ((game->error = get_next_line(file_descriptor, &new_str)))
	{
		if (game->error == -1)
			return (game->error = -201);
		if ((line_identify(new_str, game)) < 0)
			return (game->error);
	}
	game->map.size_y = ft_lstsize(game->map.map_list) + 1;
	if ((line_identify(new_str, game)) < 0)
			return (game->error);
	if (lst_parse(game) < 0)
			return (game->error);
	if (map_checker(game) < 0)
		return (game->error);
	close(file_descriptor);
	return (game->error);
}
