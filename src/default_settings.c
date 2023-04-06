/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:17:50 by mtoof             #+#    #+#             */
/*   Updated: 2023/03/29 15:06:20 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	default_settings(t_coordinate *tmp)
{
	tmp->shift_x = X / 3;
	tmp->shift_y = -200.0;
	tmp->elevate_z = 0.0;
	tmp->zoom = 40;
	tmp->z_scale = 1;
	tmp->two_d = 0;
}
