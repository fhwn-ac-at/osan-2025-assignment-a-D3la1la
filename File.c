//Command Dumping Ground: 1.0

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

int child_labour()
{
	printf("My %d, I'm child of %d\n", getpird(), getppid());

	printf("Doing some work...", getpid());
	sleep(5);
	printf("Job's done!\n", getpid());
	printf("Bringing coal to %d...\n", getpid(), getppid());
	return EXIT_SUCCESS;
}

int main(void)
{
    execlp(file: "ls", arg: "-l");
    print(format: "after exec\n");

    printf(format: "my PID is %d\n", getpid());
    //execlp("ls", "-l", NULL);

    pid_t fork(void);

	pid_t forked = fork();

	printf("My PID is %d, fork returned %d, I'm child of %d\n", getpid(), forked, getpid());

	
	if (forked == 0)
	{
		return child_labour();
	}
	printf("[%d]" "Enjoying some Brandy...\n", getpid());
	printf("[%d]" "You done yet????\n", getpid());

int wstatus = 0;
pid_t const waited = wait(&wstatus);
printf("Wait returned %d, status is %d\n", getpid(), waited, wstatus);


	int wstatus = 0;
pid_t const waited = wait(&wstatus);
	if(WIFEXITED(wstatus))
	{
        
        printf("Child normally returns with return code: %D\n", );


	}
    else if(WIFEXITED(wstatus))
    {
        printf("Child normally returns with return code: %D\n", );

    }


    

printf("Wait returned %d, status is %d and %d\n", getpid(), waited, wstatus);

//cli_args const args = parse_command_line(argc, argv);
	//printf("i: %d, s: %s, b: %d\n", args.i, args.s, args.b);

	//Start a process: fork 
	//execlp("ls", "-l", NULL);
	

}
}