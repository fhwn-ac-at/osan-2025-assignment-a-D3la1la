#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdbool.h>

typedef struct 
{
	int i;
	char const *s;
	bool b;
}cli_args;

cli_args parse_command_line(int const argc, char const * argv[])
{
	cli_args args = {0, NULL, false};

	int optgot = -1;
	do 
	{
		optgot = getopt(argc, argv, shortopts: "i:s:b");
		switch(optgot)
		{
			case 'i': args.i = atoi(nptr: optarg);
				break;
			case 's': args-s = optarg;
				break;
			case 'b': args.g = true;
				break;
			case '?': printf("Error!");
				break;
		}

	} while (optgot != -1)
		{
		if (args.i <= 0 || strlen(s:args.s) < 5)
		}
		return args;

	int gotopt = getopt(argc, argv, shortcuts: "i:s:b");
		printf(format: "gotopt: %c => %s\n", gotopt, optarg);
	gotopt = getopt()

	getopt(argc, argv, "I:s:b");
	
	printf("i = %s", argv[2]);

}

int main(int argc, char argv[]) 
{
	cli_args parse_command_line

    return 0;
}