#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc, char *argv[])
{
	srand(atoi(argv[1]));
	while(1)
	{
		char ohYeah[1];
		int slp = rand() % 30;
		printf("C: Sou %s e vou dormir por %d\n", argv[1], slp);
		sleep(slp);
		read(atoi(argv[2]), ohYeah, 1);
		printf("Sou %s, consumi %s\n",argv[1], ohYeah);
	}
}
