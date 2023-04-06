/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:10:36 by mtoof             #+#    #+#             */
/*   Updated: 2023/03/29 13:44:23 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	read_file(t_read *f_info)
{
	f_info->line_num = 0;
	while (1)
	{
		f_info->line = get_next_line(f_info->fd);
		if (!f_info->line)
			break ;
		f_info->line_num++;
		free(f_info->line);
	}
	f_info->lines = (char **)ft_calloc(sizeof(char *), f_info->line_num + 1);
	if (!f_info->lines)
		return ;
	close(f_info->fd);
}

static void	stash_file(t_matrix *matrix, t_read *f_info)
{
	int	i;

	i = 0;
	matrix->height = 0;
	matrix->width = 0;
	while (i < f_info->line_num)
	{
		f_info->line = get_next_line(f_info->fd);
		if (!f_info->line)
			break ;
		f_info->lines[i] = ft_strdup(f_info->line);
		i++;
		free(f_info->line);
	}
	close(f_info->fd);
	if (f_info->lines[0] == NULL)
		free_exit(f_info, matrix, 1);
	f_info->str_split = ft_split(f_info->lines[0], ' ');
	while (f_info->lines[matrix->height])
	{
		while (f_info->str_split[matrix->width]
			&& f_info->str_split[matrix->width][0] != '\n')
			matrix->width++;
		matrix->height++;
	}
}

static void	matrix_init(t_matrix *data, t_read *f_info)
{
	int	element;

	data->h = -1;
	while (++data->h < data->height)
	{
		f_info->str_split = ft_split(f_info->lines[data->h], ' ');
		data->w = -1;
		while (++data->w < data->width)
		{
			element = ft_atoi(f_info->str_split[data->w]);
			data->stack[data->h][data->w].z = element;
			if (num_len(element) < (int)ft_strlen(f_info->str_split[data->w])
				- 1)
			{
				f_info->s_color = ft_strchr(f_info->str_split[data->w], ',');
				f_info->s_color += 1;
				data->stack[data->h][data->w].color
					= ft_atoi_base(f_info->s_color);
			}
			else
				data->stack[data->h][data->w].color = 0;
		}
		ft_free(f_info->str_split);
	}
}

void	create_matrix(t_matrix *matrix, char *file_name)
{
	t_read	*f_info;
	int		i;

	f_info = malloc(sizeof(t_read));
	if (!f_info)
		free_matrix(matrix, 0);
	f_info->fd = open(file_name, O_RDONLY, 0);
	if (f_info->fd == 0 || f_info->fd < 0)
		free_exit(f_info, matrix, 0);
	read_file(f_info);
	f_info->fd = open(file_name, O_RDONLY, 0);
	if (f_info->fd == 0 || f_info->fd < 0)
		free_exit(f_info, matrix, 1);
	stash_file(matrix, f_info);
	ft_free(f_info->str_split);
	i = -1;
	matrix->stack = (t_stack **)malloc(sizeof(t_stack *) * matrix->height);
	if (!matrix->stack)
		free_exit(f_info, matrix, 1);
	while (++i < matrix->height)
		matrix->stack[i] = (t_stack *)malloc(sizeof(t_stack) * matrix->width);
	matrix_init(matrix, f_info);
	ft_free_file(f_info);
}
