/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sepehr <sepehr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:55:17 by mtoof             #+#    #+#             */
/*   Updated: 2023/04/23 08:38:55 by sepehr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/header/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>

# ifndef X
#  define X 1024
# endif

# ifndef PI
#  define PI 3.14159265
# endif

# ifndef Y
#  define Y 768
# endif

typedef struct s_stack
{
	int				z;
	unsigned int	color;
}					t_stack;

typedef struct s_point
{
	float			x;
	float			y;
	int				z;
}					t_point;

typedef struct s_matrix
{
	int				w;
	int				h;
	int				width;
	int				height;
	int				**matrix;
	t_stack			**stack;
}					t_matrix;

typedef struct s_read
{
	int				fd;
	int				line_num;
	char			*line;
	char			*s_color;
	char			*cache_line;
	char			**str_split;
	char			**lines;
}					t_read;

typedef struct s_img
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_img;

typedef struct s_coordinate
{
	float			x;
	float			y;
	float			s_x;
	float			s_y;
	float			dx;
	float			dy;
	int				err;
	int				err2;
	int				color;
	int				zoom;
	float			shift_x;
	float			shift_y;
	float			p_shift_x;
	float			p_shift_y;
	float			elevate_z;
	int				two_d;
	int				z_scale;
	t_img			img;
	t_matrix		*data;
	t_point			p1;
	t_point			p2;
}					t_coordinate;

unsigned int		ft_abs(int x);
int					num_len(int n);
void				ft_free(char **str);
int					slop(int x1, int x2);
void				zoom(t_coordinate *tmp);
void				key_info(t_coordinate *tmp);
void				shifting(t_coordinate *tmp);
void				ft_free_file(t_read *f_info);
unsigned int		ft_atoi_base(const char *str);
void				create_window(t_matrix *data);
void				window_handler(t_coordinate tmp);
t_img				*img_pointer_handler(t_img *img);
void				default_settings(t_coordinate *tmp);
void				isometric(float *x, float *y, int z);
void				free_matrix(t_matrix *data, int flag);
int					key_handler(int key, t_coordinate *tmp);
void				key_checker(int key, t_coordinate **tmp);
void				two_d_handler(int key, t_coordinate **tmp);
void				zoom_shift(t_coordinate *tmp, t_matrix *data);
int					color_check(t_coordinate tmp, t_matrix *data);
void				create_matrix(t_matrix *matrix, char *file_name);
void				translation_handler(int key, t_coordinate **tmp);
void				ft_draw(t_matrix *data, t_coordinate coordinates);
void				bresenham(t_coordinate coordinates, t_matrix *data);
void				my_mlx_pixel_put(t_img *data, int x, int y, int color);
void				free_exit(t_read *f_info, t_matrix *matrix, int flag);
#endif