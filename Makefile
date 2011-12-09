CC=gcc
CFLAGS=-Wall -g
LIBS=-lpthread -lncurses
SRC=src
OBJ=obj
BIN=bin

all: mkdirs client server 

$(OBJ)/client.o: $(SRC)/client.c
	$(CC) -c -o $(OBJ)/client.o $(SRC)/client.c $(CFLAGS)

client: $(OBJ)/client.o
	$(CC) -o $(BIN)/subcom $(OBJ)/client.o $(CFLAGS) $(LIBS)

$(OBJ)/server.o: $(SRC)/server.c
	$(CC) -o $(OBJ)/server.o $(SRC)/server.c $(CFLAGS)

server: $(OBJ)/server.o
	$(CC) -o $(BIN)/subcom-server $(OBJ)/server.o $(CFLAGS) $(LIBS)


mkdirs:
	mkdir -p $(OBJ) $(BIN)

clean:
	rm -f $(OBJ)/*.o $(BIN)/subcom $(BIN)/subcom-server

run:
	$(BIN)/subcom

.PHONY: clean run mkdirs
