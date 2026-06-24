CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -g

# Usar bash para suportar read -d '\0' e outros recursos
SHELL := /bin/bash

# Diretórios
SRC_DIR = src
BIN_DIR = bin

# Fonte a compilar (pode ser sobreposto na linha de comando)
# Exemplo: make SRC="src/05_jogos/advinhacao/main.c"
SRC ?= $(SRC_DIR)/01_fundamentos/hello.c

# Nome do executável gerado em bin/
TARGET := $(BIN_DIR)/$(notdir $(patsubst %.c,%,$(SRC)))

.PHONY: all build-all clean help run

# Por padrão, compila todos os exemplos
all: build-all

$(BIN_DIR):
	mkdir -p "$(BIN_DIR)"

$(TARGET): $(SRC) | $(BIN_DIR)
	$(CC) $(CFLAGS) "$(SRC)" -o "$(TARGET)"

run: $(TARGET)
	"$(TARGET)"

build-all: | $(BIN_DIR)
	@echo "Compilando todos os exemplos de $(SRC_DIR) para $(BIN_DIR)"
	@find "$(SRC_DIR)" -type f -name '*.c' -print0 | \
		while IFS= read -r -d '' src; do \
			rel=$${src#$(SRC_DIR)/}; \
			dest="$(BIN_DIR)/$${rel%.c}"; \
			mkdir -p "$$(dirname "$$dest")"; \
			echo "Compilando: $$src -> $$dest"; \
			$(CC) $(CFLAGS) "$$src" -o "$$dest" || exit 1; \
		done

help:
	@echo "Uso: make (compila todos)"
	@echo "Ou: make SRC=\"caminho/para/arquivo.c\" (compilar um arquivo específico)"

clean:
	rm -rf "$(BIN_DIR)"


