CC = gcc
CFLAGS = -O3 -m64

PROGS = Scheduler_v4 Process_v4

MODULES = Messages.o Errors.o 
HEADERS = Scheduler_v4.h Process_v4.h Messages.h Errors.h

all: $(PROGS) run

Scheduler_v4: Scheduler_v4.c $(PROGS) $(MODULES)
	$(CC) $(CFLAGS) Scheduler_v4.c $(MODULES) -o Scheduler_v4 $(EXTRALIBS)

Process_v4: Process_v4.c $(MODULES)
	$(CC) $(CFLAGS) Process_v4.c $(MODULES) -o Process_v4 $(EXTRALIBS)

clean:
#	del /Q /S $(MODULES)
#	del /Q /S $(PROGS)
	rm -rf $(MODULES)
	rm -rf $(PROGS)

run:
	./Scheduler_v4 2
