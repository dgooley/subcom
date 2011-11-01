#include "include/main.h"

int main(int arrgc, char *argv[])
{
	char ch;

	signal(SIGINT, sigint_handler);

	// ncurses initialization
	initscr();
	cbreak(); // Generate signal on ^C. Switch to raw() later.
	noecho(); // Don't echo characters
	keypad(stdscr, TRUE);

	printw("> ");
	for(;;)
	{
		ch = getch();
		printw("%c",ch);
	}

	refresh();
	getch();
	endwin();

	return 0;
}

void sigint_handler(int sig)
{
	signal(sig, SIG_IGN);
	printw("\nReceived SIGINT, quitting.");
	refresh();
	endwin();
	exit(0);
}
