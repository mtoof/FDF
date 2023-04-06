/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:59:13 by mtoof             #+#    #+#             */
/*   Updated: 2023/03/27 14:29:35 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_window(t_matrix *data)
{
	t_coordinate	tmp;

	tmp.img.mlx_ptr = mlx_init();
	tmp.img.win_ptr = mlx_new_window(tmp.img.mlx_ptr, X, Y, "FDF");
	tmp.data = data;
	default_settings(&tmp);
	window_handler(tmp);
}
