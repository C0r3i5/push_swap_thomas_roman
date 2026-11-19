# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/02 11:48:45 by twalter           #+#    #+#              #
#    Updated: 2026/11/10 08:01:03 by twalter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

LIBFT_PATH	:= ./libft

LIBFT := $(LIBFT_PATH)/libft.a

CC := cc

AR := ar rcs

RM := rm -f

CFLAGS := -Wall -Wextra -Werror -I$(LIBFT_PATH)

SOURCES := ft_printf.c ft_printf_utils.c 

OBJECTS := $(SOURCES:.c=.o)

DEPS := ft_printf.h $(LIBFT_PATH)/libft.h

all: $(NAME)
	$(MAKE) -C $(LIBFT_PATH)

$(LIBFT): 
	$(MAKE) -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(OBJECTS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJECTS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) $(OBJECTS)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
