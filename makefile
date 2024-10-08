CC = gcc
CFLAGS = -Wall -Wextra -Werror

MAKE = make

FT_PRINTF_DIR = ft_printf
LIBFT_DIR = libft

SRCS = ./client.c ./server.c
OBJS = $(SRCS:.c=.o)

FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a
LIBFT_LIB = $(LIBFT_DIR)/libft.a

CLIENT = client
SERVER = server

all: $(CLIENT) $(SERVER)

$(CLIENT): $(LIBFT_LIB) $(FT_PRINTF_LIB) $(OBJS)
	$(CC) $(CFLAGS) ./client.o -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -o $(CLIENT)

$(SERVER): $(LIBFT_LIB) $(FT_PRINTF_LIB) $(OBJS)
	$(CC) $(CFLAGS) ./server.o -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -o $(SERVER)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(CLIENT) $(SERVER)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
