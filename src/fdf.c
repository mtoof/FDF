/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:55:03 by mtoof             #+#    #+#             */
/*   Updated: 2023/03/27 17:36:28 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_matrix	*data;

	if (argc != 2)
	{
		ft_printf("%s <file name>", argv[0]);
		return (-1);
	}
	data = malloc(sizeof(t_matrix));
	if (!data)
	{
		perror("fdf");
		exit(1);
	}
	create_matrix(data, argv[1]);
	create_window(data);
	return (0);
}
