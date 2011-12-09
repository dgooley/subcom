#include "include/server.h" 

int main(int argc, char *argv[])
{
	int i;

	for (i = 1; i < argc; i++)
	{
		if (argv[i][0] == '-' && strnlen(argv[i], 3) == 2)
		{
			switch(argv[i][1])
			{
				case 't':
					break;
				default:
					help();
			}
		}
		else
		{
			help();
		}
	}

	return 0;
}

void help()
{
	printf("Help!\n");
	exit(0);
}
