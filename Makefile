# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvachon <alvachon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 19:31:23 by alvachon          #+#    #+#              #
#    Updated: 2022/07/25 15:58:48 by alvachon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# $@ expands to the target name, i.e. target1
# $< expands to the first dependency, i.e. dependency1
# $^ expands to the complete list of dependencies, i.e. dependency1 dependency2
# -I Specifies a directory dir to search for included makefiles

# COMPILATION SYSTEM FOR STATIC LIBRARY LIBFTPRINTF.A

CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=libftprintf.a

SRC= ft_printf.c \
	 functions_flags.c \
	 functions_format.c \
	 functions_help1.c \
	 functions_help2.c \
	 functions_padding.c \
	 functions_print.c \
	 libft/ft_atoi.c \
	 libft/ft_itoa.c \
	 libft/ft_strlen.c \
	 libft/ft_strchr.c \
	 libft/ft_strdup.c \
	 libft/ft_isdigit.c \
	 libft/ft_memcpy.c \
	 libft/ft_strjoin.c \
	 libft/ft_calloc.c \
	 libft/ft_memset.c \

OBJ=$(SRC:%c=%o)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

all: $(NAME)

bonus: $(NAME)

# - - - - CUSTOM CALL (1) - - NORMINETTE

#norm: $(SRCS) $(HEADERS)
#	norminette $(SRCS)
#	norminette -R CheckDefine $(HEADERS)

# - - - - CLEAN OBJS (.o)

clean:
	rm -rf *.o
	rm -rf libft/*.o

# - - - - CLEAN ARCHIVE FILE AND NON USED FILES

fclean: clean
	rm -rf $(NAME)

# GENERIC CALL TO REMAKE EVERYTHING FOR LIBFT.A

re: fclean all

# NON-ASSOCIATED ACTION CALLS (8)

.PHONY: all clean fclean re norm
