/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:23:47 by agunes            #+#    #+#             */
/*   Updated: 2022/09/23 15:06:02 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

typedef struct s_img
{
	int		alen;
	int		blen;
	char	**cub;
	char	*map;
	int		floor;
	int		ceilling;
	void	*so;
	void	*ea;
	void	*no;
	void	*we;
	int		*ea_data;
	int		*no_data;
	int		*we_data;
	int		*so_data;
	void	*p;
	double	camx;
	double	raydirx;
	double	raydiry;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wallx;
	double	pixel_cal;
	double	pixel_nbr;
	int		**wmap;
	int		mx;
	int		my;
	int		colour;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		mapx;
	int		mapy;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		next_idx;
}	t_img;

typedef struct s_cub3d
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*screen_img;
	void			*img2;
	double			px;
	double			py;
	double			rx;
	double			ry;
	double			viewx;
	double			viewy;
	double			move_speed;
	double			rotate_speed;
	double			old;
	double			old2;
	int				*img_data;
	int				*img_data2;
	int				img_width;
	int				img_height;
	int				*screen_img_data;
	int				img_x;
	int				img_y;
	int				bit_per_px;
	int				size_line;
	int				endian;
	int				witdh;
	int				height;
	int				flag;
	int				i;
	char			orientation;
	struct s_img	*img_s;
}	t_cub3d;

int		setupgame(t_cub3d *cub3d);
int		parsemap(t_cub3d *cub3d, char **argv);
char	*merge(char **map);
int		dbfree(char **array);
char	*deletechar(char *array, char c);
int		mlx_start(t_cub3d *cub3d);
int		preimg(t_cub3d *cub3d);
int		move(int key, t_cub3d *data);
void	jumpspace(t_cub3d *cub3d);
void	freeprefc(t_cub3d *cub3d, char **buff, int i);
void	draw_image(t_cub3d*data, t_img *map, int i);
void	print_img(t_cub3d *data, t_img *map);
void	print_roof(t_cub3d *data);
void	print_ground(t_cub3d *data);
void	mini_map(t_cub3d *data, t_img *map);
void	get_pos(t_cub3d *data);
void	set_values(t_cub3d *data, t_img *map);
#endif