NAME_CLIENT = client
NAME_SERVER = server
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./ft_printf/libft/libft.a
PRINTF = ./ft_printf/libftprintf.a
INCLUDES = -I $(PRINTF_DIR) -I $(LIBFT_DIR)

SRC_CLIENT = client.c
SRC_SERVER = server.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

all: $(LIBFT) $(PRINTF) $(NAME_CLIENT) $(NAME_SERVER)

$(LIBFT):
	@echo "Compiling libft..."
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF): $(LIBFT)
	@echo "Compiling ft_printf..."
	@$(MAKE) -C $(PRINTF_DIR)

$(NAME_CLIENT): $(SRC_CLIENT) $(LIBFT) $(PRINTF)
	@echo "Compiling client..."
	$(CC) $(CFLAGS) $(SRC_CLIENT) $(LIBFT) $(PRINTF) $(INCLUDES) -o $(NAME_CLIENT)

$(NAME_SERVER): $(SRC_SERVER) $(LIBFT) $(PRINTF)
	@echo "Compiling server..."
	$(CC) $(CFLAGS) $(SRC_SERVER) $(LIBFT) $(PRINTF) $(INCLUDES) -o $(NAME_SERVER)

clean:
	@echo "Cleaning..."
	@rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
	@$(MAKE) -C ./ft_printf/libft clean
	@$(MAKE) -C ./ft_printf/ clean

fclean: clean
	@echo "Full clean..."
	@rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@$(MAKE) -C ./ft_printf/libft fclean
	@$(MAKE) -C ./ft_printf/ fclean

re: fclean all

.PHONY: all clean fclean re
