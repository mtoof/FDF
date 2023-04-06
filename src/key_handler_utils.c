/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:38:01 by mtoof             #+#    #+#             */
/*   Updated: 2023/03/29 18:20:27 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translation_handler(int key, t_coordinate **tmp)
{
	if (key == 126 && (*tmp)->two_d == 1)
		(*tmp)->shift_y -= 20.0;
	if (key == 126 && (*tmp)->two_d == 0)
		(*tmp)->elevate_z += 10;
	if (key == 125 && (*tmp)->two_d == 1)
		(*tmp)->shift_y += 20.0;
	if (key == 125 && (*tmp)->two_d == 0)
		(*tmp)->elevate_z -= 10;
	if (key == 124 && (*tmp)->two_d == 0)
	{
		(*tmp)->shift_x += 10.0;
		(*tmp)->shift_y -= 20.0;
	}
	if (key == 124 && (*tmp)->two_d == 1)
		(*tmp)->shift_x += 10.0;
	if (key == 123 && (*tmp)->two_d == 0)
	{
		(*tmp)->shift_x -= 10.0;
		(*tmp)->shift_y += 20.0;
	}
	if (key == 123 && (*tmp)->two_d == 1)
		(*tmp)->shift_x -= 10.0;
}

void	two_d_handler(int key, t_coordinate **tmp)
{
	if (key == 35)
	{
		if ((*tmp)->two_d == 0)
		{
			(*tmp)->two_d = 1;
			(*tmp)->p_shift_x = (*tmp)->shift_x;
			(*tmp)->p_shift_y = (*tmp)->shift_y;
			(*tmp)->shift_y = 0;
			(*tmp)->shift_x = 0;
		}
		else
		{
			(*tmp)->two_d = 0;
			(*tmp)->shift_x = (*tmp)->p_shift_x;
			(*tmp)->shift_y = (*tmp)->p_shift_y;
		}
	}
}

void	zoom_key_handler(int key, t_coordinate **tmp)
{
	if (key == 24)
	{
		if ((*tmp)->two_d == 0)
		{
			(*tmp)->zoom += 2;
			(*tmp)->elevate_z += 10;
			(*tmp)->shift_x -= 5.0;
			(*tmp)->shift_y += 5.0;
		}
		else
			(*tmp)->zoom += 2;
	}
	if (key == 27 && (*tmp)->zoom - 2 > 0)
	{
		if ((*tmp)->two_d == 0)
		{
			(*tmp)->zoom -= 2;
			(*tmp)->elevate_z -= 10;
			(*tmp)->shift_x += 5.0;
			(*tmp)->shift_y -= 5.0;
		}
		else
			(*tmp)->zoom -= 2;
	}
}

void	key_checker(int key, t_coordinate **tmp)
{
	if (key == 124)
		translation_handler(key, tmp);
	if (key == 123)
		translation_handler(key, tmp);
	if (key == 126)
		translation_handler(key, tmp);
	if (key == 125)
		translation_handler(key, tmp);
	if (key == 24)
		zoom_key_handler(key, tmp);
	if (key == 27 && (*tmp)->zoom - 2 > 0)
		zoom_key_handler(key, tmp);
	if (key == 13)
		(*tmp)->z_scale += 1;
	if (key == 1)
		(*tmp)->z_scale -= 1;
}
