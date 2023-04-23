# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 15:50:23 by mtoof             #+#    #+#              #
#    Updated: 2023/04/23 08:48:21 by mtoof            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_DIR = libft_src/ gnl_src/ printf_src/
OBJ_DIR = obj/

vpath %.c $(SRC_DIR)

SRC = 	ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c	\
		ft_isprint.c ft_memset.c ft_memcpy.c ft_memmove.c ft_strlen.c ft_tolower.c	\
		ft_toupper.c ft_memcmp.c ft_memchr.c ft_strncmp.c ft_strnstr.c ft_strrchr.c	\
		ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strdup.c ft_calloc.c ft_atoi.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_substr.c ft_strjoin.c	\
		ft_putendl_fd.c ft_strtrim.c ft_strmapi.c ft_itoa.c ft_striteri.c ft_split.c
PRINTF_SRC = ft_putchar.c ft_putstr.c ft_printf.c ft_convert.c
GNL_SRC = get_next_line.c get_next_line_utils.c
SRC_B = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
		ft_lstmap_bonus.c

SRCS = $(SRC) $(PRINTF_SRC) $(GNL_SRC)

OBJS = $(SRCS:%.c=$(OBJ_DIR)%.o)

HEADER = ./header/
FLAGS = -Wall -Werror -Wextra

.PHONY: obj_dir

all: $(NAME)
	
$(NAME): $(OBJS)
	@ar rcs $@ $?

$(OBJS): $(OBJ_DIR)%.o: %.c | obj_dir
	@cc $(FLAGS) -I$(HEADER) -c -o $@ $<

# bonus: $(SRC_B:.c=.o)
#$(SRC_B:.c=.o): $(SRC_B)	
#	@cc $(FLAGS) -c $(SRC_B) $(HEADER)
#	@ar rcs $(NAME) $(SRC_B:.c=.o)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

obj_dir:
	@mkdir -p $(OBJ_DIR)
