# Comando para executar:
# mingw32-make

CC = gcc
CFLAGS = -Wall -IHeaders

SRC_DIR = Source
OBJ_DIR = $(SRC_DIR)
BIN = programa

SRCS = main.c \
       $(SRC_DIR)/CENTRODEPESQUISA.c \
       $(SRC_DIR)/DADOPOKEMON.c \
       $(SRC_DIR)/DADOTREINADOR.c \
       $(SRC_DIR)/POKELISTA.c

OBJS = $(SRCS:.c=.o)

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(BIN)
	./$(BIN) testes/arquivo.txt

clean:
	rm -f $(OBJ_DIR)/*.o $(BIN)