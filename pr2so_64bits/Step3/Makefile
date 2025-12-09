CC = gcc
CFLAGS = -O3 -m64

PROGS = Scheduler_v3 Process_v3

MODULES = Errors.o
HEADERS = Scheduler_v3.h Process_v3.h Errors.h

all: $(PROGS) run

Scheduler_v3: Scheduler_v3.c $(PROGS) $(MODULES)
	$(CC) $(CFLAGS) Scheduler_v3.c $(MODULES) -o Scheduler_v3 $(EXTRALIBS)

Process_v3: Process_v3.c $(MODULES)
	$(CC) $(CFLAGS) Process_v3.c $(MODULES) -o Process_v3 $(EXTRALIBS)

clean:
#	del /Q /S $(MODULES)
#	del /Q /S $(PROGS)
	rm -rf $(MODULES)
	rm -rf $(PROGS)

run:
	./Scheduler_v3 2
