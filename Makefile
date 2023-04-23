# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 17:41:39 by mtoof             #+#    #+#              #
#    Updated: 2023/04/23 08:41:57 by mtoof            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
S = ./src/
SRC = $Sfdf.c $Sread_file.c $Swindow_handler.c $Simg_handler.c $Sisometric.c \
		$Sread_file_utils.c $Sft_atoi_base.c $Screate_window.c $Skey_handler.c \
		$Szoom_shift_isometric.c $Sdefault_settings.c $Scolor_handling.c $Sfree_exit.c \
		$Sbresenham.c $Skey_handler_utils.c
HEADER = ./header
FLAGS = -Werror -Wall -Wextra
LIB = ./libft/libft.a
KEY = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	@echo "\033[0;32mCompiling libft"
	@make -C ./libft
	@echo "\033[0;32mCompiling FDF"
	@cc $(FLAGS) $(SRC) -I$(HEADER) $(LIB) $(KEY) -o $@

clean:
	@make clean -C ./libft

fclean: clean
	@make fclean -C ./libft
	@/bin/rm -f $(NAME)

re: fclean all
