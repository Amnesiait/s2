CC = gcc
CFLAGS = -O3 -m64

PROGS = Scheduler_v2 Process_v2

MODULES = Errors.o
HEADERS = Process.h Errors.h

all: $(PROGS) run

Scheduler_v2: Scheduler_v2.c $(PROGS) $(MODULES)
	$(CC) $(CFLAGS) Scheduler_v2.c $(MODULES) -o Scheduler_v2 $(EXTRALIBS)

Process_v2: Process_v2.c $(MODULES)
	$(CC) $(CFLAGS) Process_v2.c $(MODULES) -o Process_v2 $(EXTRALIBS)

clean:
#	del /Q /S $(MODULES)
#	del /Q /S $(PROGS)
	rm -rf $(MODULES)
	rm -rf $(PROGS)

run:
	./Scheduler_v2 2
