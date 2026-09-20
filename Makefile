# Compilador e flags
CC = gcc
CFLAGS = -Wall -IHeaders

# Diretórios
SRC_DIR = Source
OBJ_DIR = $(SRC_DIR)
BIN = programa

# Liste os seus arquivos .c precedidos de $(SRC_DIR)/
SRCS = main.c \
       $(SRC_DIR)/CENTRODEPESQUISA.c \
       $(SRC_DIR)/DADOPOKEMON.c \
       $(SRC_DIR)/DADOTREINADOR.c \
       $(SRC_DIR)/POKELISTA.c

OBJS = $(SRCS:.c=.o)

# Regra padrão
all: $(BIN)

# Linkagem final
$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(BIN) $(OBJS)

# Compilação dos arquivos .c em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Executar com arquivo de teste
run: $(BIN)
	./$(BIN) testes/arquivo.txt

# Limpar arquivos compilados
clean:
	rm -f $(OBJ_DIR)/*.o $(BIN)