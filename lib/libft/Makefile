# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caalbert <caalbert@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/21 16:53:48 by caalbert          #+#    #+#              #
#    Updated: 2024/01/21 16:53:49 by caalbert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS  = ft_atoi.c \
		ft_atof.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_printf_utils.c \
		ft_printf.c \
		ft_printfd.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtok.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		get_next_line.c

SRCS_H =libft.h

O_PATH =./obj

OBJS = 	${addprefix ${O_PATH}/, ${SRCS:.c=.o}}

NAME = 	libft.a

$(O_PATH)/%.o: %.c
		@mkdir -p $(O_PATH)
		@gcc -Wall -Wextra -Werror -c $< -o $@

all:	${NAME}

${NAME}:${OBJS} ${SRCS_H}
		@ar -rcs $@ $^

clean:
		@rm -f ${OBJS}
		@rm -rf ${O_PATH}

fclean:	clean
		@rm -f ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
