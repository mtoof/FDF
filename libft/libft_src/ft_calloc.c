/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:33:28 by mtoof             #+#    #+#             */
/*   Updated: 2023/03/27 15:54:23 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc_mem;
	size_t	size_alloc;

	size_alloc = size * count;
	alloc_mem = (void *)malloc(sizeof(char) * size_alloc);
	if (!alloc_mem)
		return (NULL);
	ft_bzero(alloc_mem, size_alloc);
	return (alloc_mem);
}
