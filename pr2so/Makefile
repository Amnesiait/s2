CC = gcc
CFLAGS = -O3 -g

PROGS = Scheduler Process

MODULES = Errors.o
HEADERS = Process.h Errors.h

all: $(PROGS) run

Scheduler: Scheduler.c $(PROGS) $(MODULES)
	$(CC) $(CFLAGS) Scheduler.c $(MODULES) -o Scheduler $(EXTRALIBS)

Process: Process.c $(MODULES)
	$(CC) $(CFLAGS) Process.c $(MODULES) -o Process $(EXTRALIBS)

clean:
#	del /Q /S $(MODULES)
#	del /Q /S $(PROGS)
	rm -rf $(MODULES)
	rm -rf $(PROGS)

run:
	./Process 1
	./Process 2
