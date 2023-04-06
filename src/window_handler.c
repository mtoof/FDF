/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:27:08 by mtoof             #+#    #+#             */
/*   Updated: 2023/03/28 18:43:56 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_handler(t_coordinate *tmp)
{
	mlx_destroy_window(tmp->img.mlx_ptr, tmp->img.win_ptr);
	free_matrix(tmp->data, 1);
	exit(0);
}

void	window_handler(t_coordinate tmp)
{
	tmp.img.img = mlx_new_image(tmp.img.mlx_ptr, X, Y);
	tmp.img.addr = mlx_get_data_addr(tmp.img.img, &tmp.img.bits_per_pixel,
			&tmp.img.line_length, &tmp.img.endian);
	ft_draw(tmp.data, tmp);
	mlx_put_image_to_window(tmp.img.mlx_ptr, tmp.img.win_ptr, tmp.img.img, 0,
		0);
	key_info(&tmp);
	mlx_key_hook(tmp.img.win_ptr, key_handler, &tmp);
	mlx_hook(tmp.img.win_ptr, 17, 0, mouse_handler, &tmp);
	mlx_loop(tmp.img.mlx_ptr);
}
