typedef struct 
{
	int i;
	char const *s;
	bool b;
}cli_args;

cli_args parse_command_line(int const argc, char const * argv[])
{
	cli_args args = {.i = 0, .s = NULL, .b = false};

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
			case '?': printf(format: "Usage: %s -i <number> -s <string> -b\n", argv[0]);
				printf("Error!");
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


int main(void)
{
    execlp(file: "ls", arg: "-l");

}
}