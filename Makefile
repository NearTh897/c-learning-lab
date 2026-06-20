# Compilador
CC = gcc
# Flags de compilação
CFLAGS = -Wall -g
# Nome do executável
TARGET = programa

# Regra principal (gera o executável)
all: $(TARGET)

$(TARGET): main.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o

# Regra para gerar o objeto
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

# Limpa os arquivos gerados
clean:
	rm -f $(TARGET) *.o


