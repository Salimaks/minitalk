# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skassimi <skassimi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 12:24:04 by skassimi          #+#    #+#              #
#    Updated: 2024/04/17 09:06:25 by skassimi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar -rcs
RM = rm -f

SOURCES = formats.c \
			ft_printf.c \
			fonctions.c

OBJECTS = $(SOURCES:.c=.o)

HEADER = ft_printf.h

.c.o:
	$(CC) $(FLAGS) -I. -c $< -o $(<:.c=.o)

$(NAME): $(OBJECTS) $(HEADER)
	$(AR) $(NAME) $(OBJECTS)

all: $(NAME)

re: clean fclean all

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	$(RM) $(NAME)


.PHONY: all clean fclean re bonus 