#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "mlb/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# define PI 3.141592653589793

//structures

typedef struct		sprite_params 
{
	double			x;
	double			y;
	double			dist;
}					spr_p;


typedef struct		texture_params
{
	int 			texNum;
	double 			wallX;
	int 			texX;
	int 			texY;
	double 			step;
	double 			texPos;
	int 			drawStart;
	int				drawEnd;
	unsigned int	*texture;
}					tex_p;

typedef struct		ray_params
{
	double			cam_x;
	double			dir_x;
	double			dir_y;
	double 			sideDistX;
    double 			sideDistY;
	double			deltaDistX;
	double 			deltaDistY;
	double 			perpWallDist;
	int				stepX;
    int 			stepY;
	int				hit;
	int				side;
}					ray_p;

typedef struct		cube_params
{
	int				x;
	int				y;
	int				size_x;
	int				size_y;
	int				color;
}					cube_p;

typedef struct		player_params
{
	double			x;
	double			y;
	int				map_x;
	int				map_y;
	double			dir_x;
	double			old_dir_x;
	double			dir_y;
	int				count;
	double 			moveSpeed;
	double 			rotSpeed;
	double			old_plane_x;
	double			plane_x;
	double			plane_y;
}					player_p;

typedef struct		map_params
{
		int				size_x;
		int				size_y;
		unsigned int	*north_texture;
		unsigned int	*south_texture;
		unsigned int	*west_texture;
		unsigned int	*east_texture;
		unsigned int	*sprite_texture;
		int				floor;
		int				ceiling;
		char			**map_matrix;
		list			*map_list;
}					map_p;

typedef	struct		window_params
{
	void			*mlx_app;
	void			*window_id;
	void			*img;
	char        	*addr;
	int         	bits_per_pixel;
    int         	line_length;
    int         	endian;
	int 			width;
	int				height;
}					window_p;

typedef struct		game_params
{
	char			*settings_file;
	int				error;
	window_p		window;
	map_p			map;
	player_p		pers;
	cube_p			cube;
	ray_p			ray;
	tex_p			tex;
	int				scale_x;
	int				scale_y;
	spr_p			*sprite;
	int				sprite_count;
	double 			*spriteDistance;
	int 			*spriteOrder;
	double			*perp_buffer;
}					game_p;

//checkers
int 	check_pos_valid(size_t y_pos, size_t x_pos, game_p *game);
int 	map_checker(game_p *game);
int 	resolution_checker(char *new_str, game_p *game);
int 	color_checker(char *new_str, game_p *game, int side);
int 	texture_checker(char *new_str, game_p *game, int side);

//map_handlers
int		lst_parse(game_p *game);
int 	map_collector(char *new_str, game_p *game, int status);
void    place_player(char elem, int x_pos, int y_pos, game_p *game);

//init
void	init(game_p *game);
int    	init_map(game_p *game);

//spites.c
void    sort_sprites(game_p *game);
void    sprite_set(game_p *game);

//parser
int 	start_parser(game_p *game);
int     line_identify(char *new_str, game_p *game, int status);
void 	sprite_set(game_p *game);

//cub3d_utils
char    *swap_symbols(char *str);
int		space_skip(char *new_str);
int		create_rgb(int r, int g, int b, int side, game_p *game);
void    print_parsed(game_p *game);

//display
void	display(game_p *game);
void    draw_player(game_p *game);
void    draw_background(game_p *game);
void    draw_rect(game_p *game);
void    my_mlx_pixel_put(game_p *game, int x, int y, int color);

//key_actions
int		key_bind( int keycode, game_p *game);
void	check_valid_move(game_p *game, int dir);
void	sprite_set(game_p *game);

#endif