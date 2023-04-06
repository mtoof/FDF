/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:36:11 by mtoof             #+#    #+#             */
/*   Updated: 2022/12/19 12:02:09 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nlen(unsigned long n, int base)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = (n / base);
		i++;
	}
	return (i);
}

int	ft_convert(unsigned long num, int base, char sign)
{
	int		digit_counter;
	char	*ptr;
	char	*numbers;
	int		counter;

	counter = 0;
	numbers = "0123456789ABCDEF";
	digit_counter = nlen(num, base);
	ptr = (char *)malloc(sizeof(char) * digit_counter + 1);
	if (!ptr)
		return (0);
	ptr[digit_counter--] = '\0';
	if (num == 0)
		ptr[0] = '0';
	while (num != 0)
	{
		if (numbers[num % base] > '9')
			ptr[digit_counter--] = (numbers[num % base] + sign);
		else
			ptr[digit_counter--] = numbers[num % base];
		num /= base;
	}
	counter += ft_putstr(ptr);
	free(ptr);
	return (counter);
}
