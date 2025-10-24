# Nombre del ejecutable
TARGET = snake

# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = -lncurses

# Archivos fuente
SRCS = main.c  board.c entities.c input.c

# Archivos objeto (los mismos nombres con .o)
OBJS = $(SRCS:.c=.o)

# Regla principal
all: $(TARGET)

# Cómo compilar el ejecutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Cómo compilar archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos objeto y ejecutable
clean:
	rm -f $(OBJS) $(TARGET)

# Atajo para recompilar todo
rebuild: clean all

.PHONY: all clean rebuild
