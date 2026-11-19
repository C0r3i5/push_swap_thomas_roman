# header

NAME = libftprintf.a

# Compiler und Flags
CC = cc
CFLAGS = -g -Wall -Wextra -Werror

# Libft Konfiguration
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Quelldateien und Header deines Projekts
# SRC = xxx.c
OBJ = $(SRC:.c=.o)
INCLUDES = -I. -I$(LIBFT_DIR)

all: $(NAME)

# 1. Libft kompilieren, bevor das Hauptprojekt gebaut wird
$(LIBFT):
	@make -C $(LIBFT_DIR)

# 2. Hauptbibliothek (z.B. libftprintf.a) erstellen und libft integrieren
$(NAME): $(LIBFT) $(OBJ)
	# Kopiere die libft.a als Basis für deine libftprintf.a (Standard bei 42)
	cp $(LIBFT) $(NAME)
	# Füge deine eigenen Object-Dateien hinzu
	ar rcs $(NAME) $(OBJ)

# Regel zum Kompilieren der .c zu .o Dateien
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
