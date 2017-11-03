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
		int slp = rand() % 30;
		printf("P: Sou %s e dormirei por %d\n", argv[1], slp);
		sleep(slp);
		char ohYeah[1];
		ohYeah[0] = (rand() % 25) + 65;
		printf("Sou %s, produzi %s\n", argv[1], ohYeah);
		write(atoi(argv[2]), ohYeah, 1);
	}
}
