CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
CFLAGS += -Iinc -Ilibmx/inc

TARGET = pathfinder

SRC_DIR = ./src
OBJ_DIR = ./obj
LIBMX_DIR = ./libmx/src

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
LIBMX_FILES = $(wildcard $(LIBMX_DIR)/*.c)
LIBMX_OBJ = $(patsubst $(LIBMX_DIR)/%.c,$(OBJ_DIR)/%.o,$(LIBMX_FILES))

default: $(TARGET)

$(TARGET): $(OBJ_FILES) $(LIBMX_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(LIBMX_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	-$(RM) -rf $(OBJ_DIR)

install: $(TARGET)
	cp $(TARGET) /usr/local/bin/

uninstall:
	rm -f /usr/local/bin/$(TARGET)

re: clean all

.PHONY: default clean install uninstall re
