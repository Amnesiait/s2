#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "Errors.h"
#include "Process.h"


// Global variables.
char pgm_help[]="   Sintax: \tScheduler <n_processes>\n   Example: \tScheduler 5\n";


int main(int argc, char *argv[])
{
    char MsgError[200], Msg[200];
    int pid;

    /** Process box parameters **/
    if (argc!=2)
    {
        sprintf(MsgError,"Error number of arguments (%d arguments passed, 1 required).\n%s", argc-1, pgm_help);
        Error(MsgError);
    }
    int nprocesses = atoi(argv[1]);

    sprintf(Msg,"[Scheduler] Executed with %d processes.\n", nprocesses);
    print(Msg);
    
    exit(0);
}
