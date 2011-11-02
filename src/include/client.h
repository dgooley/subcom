#include <stdlib.h>
#include <stdio.h>

#include <signal.h>

#include <pthread.h>

#include <ncurses.h>


/*
 * Definitions
 */
#define VERSION (const char*)("0.1")

/*
 * Catch SIGINT so ncurses doesn't print an ugly error message
 */
void sigint_handler(int sig);

/*
 * Print Help text and exit
 */
void help(char *name);

/*
 * Print version and exit
 */
void version(char *name);

void logging();

void server();

void local();
