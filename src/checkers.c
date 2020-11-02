#include "../cub3d.h"

int		texture_to_img(game_p *game, unsigned int **adr, char *file)
{
	void	*img;
	int		tab[5];

	img = mlx_xpm_file_to_image(game->window.mlx_app, file, &tab[0], &tab[1]);
	if (img == NULL || tab[0] != 64 || tab[1] != 64)
		return (-1);
	*adr = (unsigned int *)mlx_get_data_addr(img, &tab[2], &tab[3], &tab[4]);
	free(img);
	return (0);
}

int		color_checker(char *new_str, game_p *game, int side)
{
	int		counter;
	int		r;
	int		g;
	int		b;

	counter = 0;
	counter += space_skip(&new_str[counter]);
	r = ft_atoi(&new_str[counter]);
	counter += skip_by_func(ft_isdigit, new_str + counter);
	if (new_str[counter] != ' ' && new_str[counter] != ',')
		return (game->error = -208 - side);
	while ((new_str[counter] == ' ' || new_str[counter] == ','))
		counter++;
	g = ft_atoi(&new_str[counter]);
	counter += skip_by_func(ft_isdigit, new_str + counter);
	if (new_str[counter] != ' ' && new_str[counter] != ',')
		return (game->error = -208 - side);
	while ((new_str[counter] == ' ' || new_str[counter] == ','))
		counter++;
	b = ft_atoi(&new_str[counter]);
	if (side == 1)
		game->map.floor = (r << 16 | g << 8 | b);
	else
		game->map.ceiling = (r << 16 | g << 8 | b); 
	return (0);
}

int		texture_checker(char *new_str, game_p *game, int side)
{
	int		fd;
	int		counter;

	counter = 0;
	while (ft_isalpha(new_str[counter]))
		counter++;
	new_str += space_skip(&new_str[counter]) + counter;
	fd = open(new_str, O_RDONLY);
	if (fd == -1)
		return (game->error = -203 - side);
	else
		close(fd);
	if (side == 1)
		texture_to_img(game, &game->map.north_texture, new_str);
	else if (side == 2)
		texture_to_img(game, &game->map.south_texture, new_str);
	else if (side == 3)
		texture_to_img(game, &game->map.west_texture, new_str);
	else if (side == 4)
		texture_to_img(game, &game->map.east_texture, new_str);
	else if (side == 5)
		texture_to_img(game, &game->map.sprite_texture, new_str);
	return (0);
}

int		resolution_checker(char *new_str, game_p *game)
{
	int		counter;

	counter = 0;
	while (ft_isalpha(new_str[counter]))
		counter++;
	counter += space_skip(&new_str[counter]);
	if ((game->window.width = ft_atoi(&new_str[counter])) <= 0)
		return (game->error = -201);
	while (ft_isdigit(new_str[counter]))
	{
		counter++;
	}
	if (new_str[counter] != ' ')
		return (game->error = -202);
	counter += space_skip(&new_str[counter]);
	if ((game->window.height = ft_atoi(&new_str[counter])) <= 0)
		return (game->error = -202);
	return (0);
}

int		check_pos_valid(size_t y_pos, size_t x_pos, game_p *game)
{
	char	**matrix;
	size_t	y_size;

	y_size = game->map.size_y;
	matrix = game->map.map_matrix;
	if (x_pos == 0 || x_pos == ft_strlen(matrix[y_pos]) - 1
					|| y_pos == 0 || y_pos == y_size - 1
					|| ft_strlen(matrix[y_pos - 1]) < x_pos
					|| ft_strlen(matrix[y_pos + 1]) < x_pos)
		return (game->error = -301);
	return (0);
}
