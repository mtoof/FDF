/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:43:45 by mtoof             #+#    #+#             */
/*   Updated: 2023/03/29 14:01:54 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	color_check(t_coordinate tmp, t_matrix *data)
{
	int	z1;
	int	z2;

	z1 = data->stack[(int)tmp.p1.y][(int)tmp.p1.x].z;
	z2 = data->stack[(int)tmp.p2.y][(int)tmp.p2.x].z;
	if (data->stack[(int)tmp.p1.y][(int)tmp.p1.x].color != 0)
		return (data->stack[(int)tmp.p1.y][(int)tmp.p1.x].color);
	if (data->stack[(int)tmp.p2.y][(int)tmp.p2.x].color != 0)
		return (data->stack[(int)tmp.p2.y][(int)tmp.p2.x].color);
	else
	{
		if (z1 * tmp.z_scale < z2 * tmp.z_scale || z1 * tmp.z_scale != z2
			* tmp.z_scale)
			return (0x069869);
		else if ((z1 * tmp.z_scale) == 0 || (z2 * tmp.z_scale) == 0)
			return (0xFFFFFF);
		else if ((z1 * tmp.z_scale) < 0 || (z2 * tmp.z_scale) < 0)
			return (0x0000FF);
		else
			return (0xFFFF00);
	}
}
