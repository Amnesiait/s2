#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <unistd.h>

// Constants definition
#define DMaxBurstExecTime 4
#define DMaxBurstWaitTime 4
#define DProcessFinishProbability 70
#define DQuantum 3

// Types definition
enum EProcessState { Ready, Running, Waiting, Ended };
typedef enum EProcessState TProcessState, *PtrProcessState;

// Functions prototypes
int process_execution();
void print_status(TProcessState status, int time);