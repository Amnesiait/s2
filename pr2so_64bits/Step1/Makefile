CC = gcc
CFLAGS = -O3 -m64

PROGS = Scheduler_v1 Process

MODULES = Errors.o
HEADERS = Process.h Errors.h

all: $(PROGS) run

Scheduler_v1: Scheduler_v1.c $(PROGS) $(MODULES)
	$(CC) $(CFLAGS) Scheduler_v1.c $(MODULES) -o Scheduler_v1 $(EXTRALIBS)

Process: Process.c $(MODULES)
	$(CC) $(CFLAGS) Process.c $(MODULES) -o Process $(EXTRALIBS)

clean:
#	del /Q /S $(MODULES)
#	del /Q /S $(PROGS)
	rm -rf $(MODULES)
	rm -rf $(PROGS)

run:
	./Scheduler_v1 2
