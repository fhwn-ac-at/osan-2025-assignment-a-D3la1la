#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <getopt.h>
#include <unistd.h>


int main(int argc, char *argv[]) 
{
	//cli_args const args = parse_command_line(argc, argv);
	//printf("i: %d, s: %s, b: %d\n", args.i, args.s, args.b);

	//Start a process: fork 
	//execlp("ls", "-l", NULL);
	
	int wstatus = 0;
pid_t const waited = wait(&wstatus);
printf("Wait returned %d, status is %d and %d\n", getpid(), waited, wstatus);


    return 0;
}