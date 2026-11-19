# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/19 13:24:31 by twalter           #+#    #+#              #
#    Updated: 2026/11/19 13:27:11 by twalter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

CC := cc

AR := ar rcs

RM := rm -f

CFLAGS := -Wall -Wextra -Werror

SOURCES := push_swap.c

OBJECTS := $(SOURCES:.c=.o)

DEPS := push_swap.h

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $^

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re