CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic 
CFLAGS += -Iinc -Ilibmx/inc

TARGET = pathfinder

SRC = ./src/*.c
OBJ = ./obj/*.o

LIBMX_SRC = ./libmx/src/*.c 
LIBMX_OBJ = ./libmx/obj/*.o

default: $(TARGET)

$(TARGET): $(OBJ) $(LIBMX_OBJ)
	$(CC) $(CFLAGS) $^ -o $@
	
./obj/%.o: ./src/%.c
	$(CC) $(CFLAGS) -c $< -o $@
	
./libmx/obj/%.o: ./libmx/src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-$(RM) -f $(OBJ) $(LIBMX_OBJ)
	
install: $(TARGET)
	cp $(TARGET) /usr/local/bin/
	
uninstall:
	rm -f /usr/local/bin/$(TARGET)

re: clean all

.PHONY: default clean install uninstall re