#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Errors.h"
#include "Process.h"


// Global variables.
char pgm_help[]="   Sintax: \tProcess <seed>\n   Example: \tProcess 1111\n";


int main(int argc, char *argv[])
{
    char MsgError[200];

    /** Process parameters **/
    if (argc!=2)
    {
        sprintf(MsgError,"Error number of arguments (%d arguments passed, 1 required).\n%s", argc-1, pgm_help);
        Error(MsgError);
    }
    
    srand(atoi(argv[1])+100);

    int exec_time = process_execution();

    exit(exec_time);
}


int process_execution()
{
    char Msg[250];
    TProcessState status = Ready;
    int exec_time = 0, pending_time=0;

    while(1)
    {
        int run_time, wait_time;

        switch (status)
        {
            case Ready:
                print_status(status,0);
                status = Running;
                break;

            case Running:
                if (pending_time==0){
                    run_time = 1 + (rand() % DMaxBurstExecTime);
                    sprintf(Msg,"[Process %d] CPU Burst: %ds.\n",getpid(), run_time);
                    printMessage(Msg, COLOR_CYAN_B);
                }
                else
                    run_time = pending_time;

                // Considering maximun execution time (quantum)
                pending_time = run_time - DQuantum;
                if (pending_time<0)
                    pending_time = 0;
                else
                    run_time = DQuantum;

                print_status(status, run_time);
                sleep(run_time);
                exec_time += run_time;

                // Calculate next state
                if (pending_time>0)
                    status = Ready;
                else
                {
                    // Process finished
                    int r = (1 + (rand()%100));
                    if ( r <= DProcessFinishProbability)
                        status = Ended;
                    else 
                        status = Waiting;
                }
                break;


            case Waiting:
                wait_time = 1 + rand() % DMaxBurstWaitTime;
                sprintf(Msg,"[Process %d] E/S Burst: %ds.\n",getpid(), wait_time);
                printMessage(Msg, COLOR_CYAN_B);    
                print_status(status, wait_time);
                sleep(wait_time);
                exec_time += wait_time;
                status = Ready;
                break;

            case Ended:
                print_status(status, exec_time);
                return 0;
                break;
        }
    }
}


void print_status(TProcessState status, int time)
{
    char Msg[250];

    switch (status)
    {
        case Ready:
            sprintf(Msg,"[Process %d] Ready.\n",getpid());
            printMessage(Msg, COLOR_CYAN_B);
            break;

        case Running:
            sprintf(Msg,"[Process %d] Running for %ds.\n",getpid(), time);
            printMessage(Msg, COLOR_CYAN_B);
            break;

        case Waiting:
            sprintf(Msg,"[Process %d] Waiting for %ds.\n",getpid(), time);
            printMessage(Msg, COLOR_CYAN_B);
            break;

        case Ended:
            sprintf(Msg,"[Process %d] Ended (exec time: %ds).\n",getpid(), time);
            printMessage(Msg, COLOR_CYAN_B);
            break;
    }
}

