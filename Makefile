# Makefile

CC = gcc
CFLAGS = -g
#CFLAGS = -g0 -O3 
OBJ = queue/queue.o priority_queue/pqueue.o

all: $(OBJ) main.c 
	@echo "Creating all..."
	$(CC) $(OBJ) main.c -o queue_test $(CFLAGS)

%.o: %.c %.h
	@echo "Creating object files..."
	$(CC) -c $< -o $@ $(CFLAGS)
	
clean:
	@echo "Deleting object and binary files..."
	rm -rvf $(OBJ) queue_test