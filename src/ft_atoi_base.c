/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:13:33 by mtoof             #+#    #+#             */
/*   Updated: 2023/03/23 17:53:32 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	ft_atoi_base(const char *str)
{
	int				len;
	int				base;
	int				j;
	unsigned int	n;

	len = 0;
	n = 0;
	base = 1;
	len = ft_strlen(str);
	j = len - 1;
	while (j >= 0)
	{
		if (str[j] >= '0' && str[j] <= '9')
			n += (str[j] - 48) * base;
		else if (str[j] >= 'A' && str[j] <= 'F')
			n += (str[j] - 55) * base;
		base *= 16;
		j--;
	}
	return (n);
}
