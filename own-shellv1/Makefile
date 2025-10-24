# Nombre del ejecutable
TARGET = shell

# Compilador
CC = gcc

# Flags de compilación
CFLAGS = -Wall -Wextra -g

# Archivos fuente
SRC = shell.c utils.c builtin.c

# Archivos objeto (se generan automáticamente)
OBJ = $(SRC:.c=.o)

# Regla por defecto: compilar todo
all: $(TARGET)

# Cómo generar el ejecutable a partir de los objetos
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Cómo generar archivos objeto a partir de archivos fuente
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(OBJ) $(TARGET)

# Ejecutar el programa
run: $(TARGET)
	./$(TARGET)