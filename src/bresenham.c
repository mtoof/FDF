/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:06:32 by mtoof             #+#    #+#             */
/*   Updated: 2023/03/29 14:06:43 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham(t_coordinate tmp, t_matrix *data)
{
	tmp.color = color_check(tmp, data);
	zoom_shift(&tmp, data);
	tmp.dx = ft_abs((int)tmp.p2.x - (int)tmp.p1.x);
	tmp.dy = ft_abs((int)tmp.p2.y - (int)tmp.p1.y);
	tmp.s_x = slop((int)tmp.p1.x, (int)tmp.p2.x);
	tmp.s_y = slop((int)tmp.p1.y, (int)tmp.p2.y);
	tmp.err = (tmp.dx - tmp.dy);
	while ((int)tmp.p1.x != (int)tmp.p2.x || (int)tmp.p1.y != (int)tmp.p2.y)
	{
		my_mlx_pixel_put(&tmp.img, (int)tmp.p1.x, (int)tmp.p1.y, tmp.color);
		tmp.err2 = (2 * tmp.err);
		if (tmp.err2 > -tmp.dy)
		{
			tmp.err -= (int)tmp.dy;
			tmp.p1.x += (int)tmp.s_x;
		}
		if (tmp.err2 < tmp.dx)
		{
			tmp.err += (int)tmp.dx;
			tmp.p1.y += tmp.s_y;
		}
	}
	my_mlx_pixel_put(&tmp.img, (int)tmp.p1.x, (int)tmp.p1.y, tmp.color);
}
