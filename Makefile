PROJECT_NAME = my_game
RAYLIB_PATH = /home/chrissolanilla/raylib/src

CC = g++
CFLAGS = -Wall -std=c++14 -I$(RAYLIB_PATH) -I$(RAYLIB_PATH)/external
LDFLAGS = -L$(RAYLIB_PATH) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(PROJECT_NAME)

$(PROJECT_NAME): $(OBJECTS)
	@echo "Compiling with CFLAGS: $(CFLAGS)"
	@echo "Linking with LDFLAGS: $(LDFLAGS)"
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(PROJECT_NAME) $(OBJECTS)

run: all
	LD_LIBRARY_PATH=$(RAYLIB_PATH) ./$(PROJECT_NAME)

