#include "../cub3d.h"

void	ft_bdata(game_p *game, int fd)
{
	int				i;
	int				j;
	unsigned char	buffer[4];

	i = game->window.width * (game->window.height - 1);
	while (i >= 0)
	{
		j = 0;
		while (j < game->window.width)
		{
			buffer[0] = (unsigned char)(game->window.addr[i] % 256);
			buffer[1] = (unsigned char)(game->window.addr[i] / 256 % 256);
			buffer[2] = (unsigned char)(game->window.addr[i] / 256 / 256 % 256);
			buffer[3] = (unsigned char)(0);
			write(fd, buffer, 4);
			i++;
			j++;
		}
		i -= 2 * game->window.width;
	}
}

void	ft_binfo(game_p *game, int fd)
{
	int				n;
	unsigned char	header[40];

	n = 0;
	while (n < 40)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(40);
	n = game->window.width;
	header[4] = (unsigned char)(n % 256);
	header[5] = (unsigned char)(n / 256 % 256);
	header[6] = (unsigned char)(n / 256 / 256 % 256);
	header[7] = (unsigned char)(n / 256 / 256 / 256);
	n = game->window.height;
	header[8] = (unsigned char)(n % 256);
	header[9] = (unsigned char)(n / 256 % 256);
	header[10] = (unsigned char)(n / 256 / 256 % 256);
	header[11] = (unsigned char)(n / 256 / 256 / 256);
	header[12] = (unsigned char)(1);
	header[14] = (unsigned char)(32);
	write(fd, header, 40);
}

void	ft_bfile(game_p *game, int fd)
{
	int				n;
	unsigned char	header[14];

	n = 0;
	while (n < 14)
		header[n++] = (unsigned char)(0);
	header[0] = (unsigned char)(66);
	header[1] = (unsigned char)(77);
	n = game->window.width * game->window.height * 4 + 54;
	header[2] = (unsigned char)(n % 256);
	header[3] = (unsigned char)(n / 256 % 256);
	header[4] = (unsigned char)(n / 256 / 256 % 256);
	header[5] = (unsigned char)(n / 256 / 256 / 256);
	header[10] = (unsigned char)(54);
	write(fd, header, 14);
}

int		ft_bitmap(game_p *game)
{
	int		fd;

	display(game);
	fd = open("bitmap.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	ft_bfile(game, fd);
	ft_binfo(game, fd);
	ft_bdata(game, fd);
	close(fd);
	ft_close(game, 0);
	return (1);
}