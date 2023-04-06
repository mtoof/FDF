/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_shift.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:28:44 by mtoof             #+#    #+#             */
/*   Updated: 2023/03/29 15:07:24 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(t_coordinate *tmp)
{
	tmp->p1.x *= tmp->zoom;
	tmp->p1.y *= tmp->zoom;
	tmp->p2.x *= tmp->zoom;
	tmp->p2.y *= tmp->zoom;
	if (tmp->z_scale != 0)
	{
		tmp->p1.z *= tmp->z_scale;
		tmp->p2.z *= tmp->z_scale;
		tmp->z_scale = 0;
	}
}

void	shifting(t_coordinate *tmp)
{
	tmp->p1.x += tmp->shift_x;
	tmp->p1.y += tmp->shift_y;
	tmp->p2.x += tmp->shift_x;
	tmp->p2.y += tmp->shift_y;
	if (tmp->elevate_z != 0)
	{
		tmp->p1.z += tmp->elevate_z;
		tmp->p2.z += tmp->elevate_z;
		tmp->elevate_z = 0;
	}
}

void	z_init(t_coordinate *tmp, t_matrix *data)
{
	tmp->p1.z = data->stack[(int)tmp->p1.y][(int)tmp->p1.x].z;
	tmp->p2.z = data->stack[(int)tmp->p2.y][(int)tmp->p2.x].z;
}

void	zoom_shift(t_coordinate *tmp, t_matrix *data)
{
	z_init(tmp, data);
	zoom(tmp);
	shifting(tmp);
	if (tmp->two_d == 0)
	{
		isometric(&(tmp)->p1.x, &(tmp)->p1.y, (tmp)->p1.z);
		isometric(&(tmp)->p2.x, &(tmp)->p2.y, (tmp)->p2.z);
	}
}
