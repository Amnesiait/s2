
#ifndef ERRORS_HEADER
#define ERRORS_HEADER

#define DEBUG 0

// Types definitions:
typedef enum {TOk, TErrorGeneric, TErrorClientSimulation} TError, PtrError;

// Global variables
extern char MsgError[256];

// Colors codes
extern char *COLOR_BLACK;
extern char *COLOR_RED;
extern char *COLOR_RED_B;
extern char *COLOR_GREEN;
extern char *COLOR_GREEN_B;
extern char *COLOR_YELLOW;
extern char *COLOR_BLUE;
extern char *COLOR_BLUE_B;
extern char *COLOR_MAGENTA;
extern char *COLOR_CYAN;
extern char *COLOR_CYAN_B;
extern char *COLOR_RESET;


// Functions Prototypes
void Error(char *msg);
void printMessage(char *msg, char *color);
void print(char *msg);

#endif //ERRORS_HEADER
