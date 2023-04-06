# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 17:41:39 by mtoof             #+#    #+#              #
#    Updated: 2023/03/29 17:52:42 by mtoof            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
S = ./src/
SRC = $Sfdf.c $Sread_file.c $Swindow_handler.c $Simg_handler.c $Sisometric.c \
		$Sread_file_utils.c $Sft_atoi_base.c $Screate_window.c $Skey_handler.c \
		$Szoom_shift_isometric.c $Sdefault_settings.c $Scolor_handling.c $Sfree_exit.c \
		$Sbresenham.c $Skey_handler_utils.c
GNL_LIB = ./get_next_line/get_next_line.a
HEADER = ./header
FLAGS = -Werror -Wall -Wextra
LIB = ./libft/libft.a
MLX_MAC = ./minilibx_macos/
KEY = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	@echo "\033[0;32mCompiling libft"
	@make -C ./libft
	@echo "\033[0;32mCompiling Minilibx"
	@make -C ./minilibx_macos
	@echo "\033[0;32mCompiling get_next_line"
	@make -C ./get_next_line
	@echo "\033[0;32mCompiling FDF"
	@cc $(FLAGS) $(SRC) -I$(HEADER) $(GNL_LIB) $(LIB) -L $(MLX_MAC) $(KEY) -o $@

clean:
	@make clean -C ./libft
	@make clean -C $(MLX_MAC)

fclean: clean
	@make fclean -C ./libft
	@make fclean -C ./get_next_line
	@/bin/rm -f $(NAME)

re: fclean all
