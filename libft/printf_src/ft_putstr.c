/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:53:55 by mtoof             #+#    #+#             */
/*   Updated: 2022/12/12 09:08:00 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (s)
	{
		while (s[i] != '\0')
		{
			counter += ft_putchar(s[i]);
			i++;
		}
	}
	return (counter);
}
