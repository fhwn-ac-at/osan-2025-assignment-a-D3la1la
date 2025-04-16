CC = clang
CFLAGS += -Wall -Wextra -Werror --std=c17
LDFLAGS = -lrt

# Targets
pfusch: ventilator.o worker.o
	$(CC) $(CFLAGS) ventilator.o worker.o -o pfusch $(LDFLAGS)

# Compile ventilator.c into ventilator.o
ventilator.o: ventilator.c
	$(CC) $(CFLAGS) -c ventilator.c -o ventilator.o

# Compile worker.c into worker.o
worker.o: worker.c
	$(CC) $(CFLAGS) -c worker.c -o worker.o

# Clean up compiled files
clean:
	rm -f pfusch ventilator.o worker.o

.PHONY: clean
