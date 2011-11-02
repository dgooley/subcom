#include "include/client.h"

int main(int argc, char *argv[])
{
	int i;

	// Client Initialization
	signal(SIGINT, sigint_handler);

	// Process args
	for (i = 1; i < argc; i++)
	{
		if (argv[i][0] == '-' && strnlen(argv[i], 3) == 2)
		{
			switch (argv[i][1])
			{
				case 's': // Specify server
					server();
					break;
				case 'l': // Local game
					local();
					break;
				case 'L': // Logging
					logging();
					break;
				default:  // Help
					help(argv[0]);
			}
		}
		else
		{
			// Help
			help(argv[0]);
		}
	}

	/*
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
	*/

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

void help(char *name)
{
	printf("Sub Commander Client v%s\n", VERSION);

	if (name)
	{
		printf("usage: %s [flags (args)]\n", name);
		printf("\t-s address port\t: Connect to server at specified ");
		printf("address and port\n\t-l\t\t: Start local game\n");
		printf("\t-L\t\t: Enable logging\n\t-h\t\t: Display this ");
		printf("message\n");
	}

	exit(0);
}

void logging()
{
	printf("logging\n");
}

void server()
{
	printf("server\n");
}

void local()
{
	printf("local\n");
}
