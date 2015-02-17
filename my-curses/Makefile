SRC=src/*.c
BUILD=build
DEBUG_FLAGS=-g
CC_FLAGS=-Isrc -lncurses -lpthread

all: clean $(SRC)
	gcc -o $(BUILD)/my-curses $(SRC) $(CC_FLAGS)

debug: clean $(SRC)
	gcc -o $(BUILD)/my-curses-debug $(SRC) $(CC_FLAGS) $(DEBUG_FLAGS)

clean:
	-rm -rf $(BUILD)
	mkdir $(BUILD)
