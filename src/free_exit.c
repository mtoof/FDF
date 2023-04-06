/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:31:15 by mtoof             #+#    #+#             */
/*   Updated: 2023/03/28 18:33:28 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_exit(t_read *f_info, t_matrix *matrix, int flag)
{
	perror("fdf");
	if (flag == 1)
		ft_free(f_info->lines);
	free(f_info);
	free(matrix);
	exit(0);
}

void	free_matrix(t_matrix *data, int flag)
{
	int	i;

	i = 0;
	if (flag == 1)
	{
		while (i < data->height)
		{
			free(data->stack[i]);
			i++;
		}
	}
	free(data->stack);
	free(data);
	exit (0);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
	return ;
}

void	ft_free_file(t_read *f_info)
{
	ft_free(f_info->lines);
	free(f_info);
	return ;
}
