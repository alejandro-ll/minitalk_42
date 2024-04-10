# Directorios
SRC_DIR := src
UTILS_DIR := utils
OBJ_DIR := obj

# Archivos fuente
CLIENT_SRC := $(SRC_DIR)/client.c
SERVER_SRC := $(SRC_DIR)/server.c
UTILS_SRC := $(UTILS_DIR)/utils.c

# Objetos
CLIENT_OBJ := $(OBJ_DIR)/client.o
SERVER_OBJ := $(OBJ_DIR)/server.o
UTILS_OBJ := $(OBJ_DIR)/utils.o

# Compilador y opciones
CC := gcc
CFLAGS := -Wall -Wextra -Werror

# Programas ejecutables
CLIENT := client
SERVER := server

.PHONY: all clean fclean re

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(SERVER): $(SERVER_OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(CLIENT_OBJ): $(CLIENT_SRC) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER_OBJ): $(SERVER_SRC) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(UTILS_OBJ): $(UTILS_SRC) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(CLIENT) $(SERVER)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all
