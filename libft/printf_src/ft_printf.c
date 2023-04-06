/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:42:22 by mtoof             #+#    #+#             */
/*   Updated: 2022/12/19 12:18:59 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_int(va_list args, int counter)
{
	long	i;

	i = va_arg(args, int);
	if (i < 0)
	{
		counter += ft_putchar('-');
		i = -i;
	}
	counter += ft_convert(i, 10, 0);
	return (counter);
}

static int	ft_check(va_list args, const char *tmp)
{
	int	counter;

	counter = 0;
	if (*tmp == 'c')
		counter += ft_putchar(va_arg(args, int));
	else if (*tmp == 's')
		counter += ft_putstr(va_arg(args, char *));
	else if (*tmp == 'X')
		counter += ft_convert(va_arg(args, unsigned int), 16, 0);
	else if (*tmp == 'x')
		counter += ft_convert(va_arg(args, unsigned int), 16, 32);
	else if (*tmp == 'd' || *tmp == 'i')
		counter += ft_check_int(args, counter);
	else if (*tmp == 'u')
		counter += ft_convert(va_arg(args, unsigned int), 10, 0);
	else if (*tmp == 'p')
	{
		counter += ft_putstr("0x");
		counter += ft_convert((size_t)va_arg(args, void *), 16, 32);
	}
	else if (*tmp == '%')
		counter += ft_putchar('%');
	return (counter);
}

int	ft_printf(const char *tmp, ...)
{
	int		counter;
	va_list	args;

	counter = 0;
	va_start(args, tmp);
	while (*tmp)
	{
		if (*tmp != '%')
			counter += ft_putchar(*tmp);
		else if (*tmp == '%')
		{
			tmp++;
			counter += ft_check(args, tmp);
		}
		if (!*tmp)
			return (counter);
		tmp++;
	}
	va_end(args);
	return (counter);
}
