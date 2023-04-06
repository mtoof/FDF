/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:36:42 by mtoof             #+#    #+#             */
/*   Updated: 2023/03/29 14:06:19 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < X && y < Y)
	{
		dst = data->addr + (y * data->line_length + (x * (data->bits_per_pixel
						/ 8)));
		*(unsigned int *)dst = color;
	}
}

int	slop(int x1, int x2)
{
	if (x1 < x2)
		return (1);
	else
		return (-1);
}

unsigned int	ft_abs(int x)
{
	if (x < 0)
		x = -x;
	return (x);
}

void	ft_draw(t_matrix *data, t_coordinate tmp)
{
	tmp.p1.y = -1;
	while (++tmp.p1.y < data->height)
	{
		tmp.p1.x = -1;
		while (++tmp.p1.x < data->width)
		{
			if (tmp.p1.x < data->width - 1)
			{
				tmp.p2.x = tmp.p1.x + 1;
				tmp.p2.y = tmp.p1.y;
				bresenham(tmp, data);
			}
			if (tmp.p1.y < data->height - 1)
			{
				tmp.p2.y = tmp.p1.y + 1;
				tmp.p2.x = tmp.p1.x;
				bresenham(tmp, data);
			}
		}
	}
}
