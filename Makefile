# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twalter <twalter@student.42heilbronn.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/19 13:24:31 by twalter           #+#    #+#              #
#    Updated: 2026/11/19 20:18:05 by twalter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

FT_PRINTF_PATH := ./ft_printf

FT_PRINTF := $(FT_PRINTF_PATH)/libftprintf.a

CC := cc

AR := ar rcs

RM := rm -f

CFLAGS := -Wall -Wextra -Werror -I$(FT_PRINTF_PATH)

SOURCES := push_swap.c

OBJECTS := $(SOURCES:.c=.o)

DEPS := push_swap.h $(FT_PRINTF_PATH)/ft_printf.h

all: $(NAME)
	$(MAKE) -C $(FT_PRINTF_PATH)

$(FT_PRINTF): 
	$(MAKE) -C $(FT_PRINTF_PATH)

$(NAME): $(FT_PRINTF) $(OBJECTS)
	cp $(FT_PRINTF) $(NAME)
	$(AR) $(NAME) $(OBJECTS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(MAKE) -C $(FT_PRINTF_PATH) clean
	$(RM) $(OBJECTS)

fclean: clean
	$(MAKE) -C $(FT_PRINTF_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re