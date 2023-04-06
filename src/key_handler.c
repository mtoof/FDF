/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:54:03 by mtoof             #+#    #+#             */
/*   Updated: 2023/03/29 18:14:03 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_info(t_coordinate *tmp)
{
	mlx_string_put(tmp->img.mlx_ptr, tmp->img.win_ptr, 10, Y - 150, 0xFFFFFF,
		"zoom   	-> - / +");
	mlx_string_put(tmp->img.mlx_ptr, tmp->img.win_ptr, 10, Y - 130, 0xFFFFFF,
		"move   	-> use arrow keys");
	mlx_string_put(tmp->img.mlx_ptr, tmp->img.win_ptr, 10, Y - 110, 0xFFFFFF,
		"z axis 	-> w / s");
	mlx_string_put(tmp->img.mlx_ptr, tmp->img.win_ptr, 10, Y - 90, 0xFFFFFF,
		"projection -> p");
}

int	key_handler(int key, t_coordinate *tmp)
{
	if (key == 35)
		two_d_handler(key, &tmp);
	if (key == 53)
	{
		mlx_destroy_window(tmp->img.mlx_ptr, tmp->img.win_ptr);
		free(tmp->img.mlx_ptr);
		free_matrix(tmp->data, 1);
	}
	if ((key >= 123 && key <= 126) || key == 27 || key == 24 || key == 13
		|| key == 1 || key == 35)
	{
		key_checker(key, &tmp);
		mlx_destroy_image(tmp->img.mlx_ptr, tmp->img.img);
		mlx_clear_window(tmp->img.mlx_ptr, tmp->img.win_ptr);
		window_handler(*tmp);
	}
	return (0);
}
