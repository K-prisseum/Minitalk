CC = gcc
CFLAGS = -Wall -Wextra -Werror
CLIENT_SRC = client.c
SERVER_SRC = server.c
FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

CLIENT = client
SERVER = server

all: $(FT_PRINTF_LIB) $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJ) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ) $(FT_PRINTF_LIB)

$(SERVER): $(SERVER_OBJ) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJ) $(FT_PRINTF_LIB)

$(FT_PRINTF_LIB):
	make -C $(FT_PRINTF_DIR)

clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ)
	make -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(CLIENT) $(SERVER)
	make -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
