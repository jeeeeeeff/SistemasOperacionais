#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
	int pid = 0, i, aux;
	char letra = 'A';
	printf("%c:Nasci, PID:%d PPID: %d\n",letra, getpid(), getppid());
	pid = fork();
	if(!pid)
	{
		letra = 'B';
		printf("%c:Nasci, PID:%d PPID: %d\n",letra, getpid(), getppid());
		pid = fork();
		if(!pid)
		{
			letra = 'C';
			printf("%c:Nasci, PID:%d PPID: %d\n",letra, getpid(), getppid());
		}
		else
		{
			wait(&aux);
		}
	}
	else
	{
		letra = 'A';
		wait(&aux);
		pid = fork();
		if(!pid)
		{
			letra = 'D';
			printf("%c:Nasci, PID:%d PPID: %d\n", letra,getpid(), getppid());
			
			
		}
		else
		{
			wait(&aux);
			pid = fork();
			if(!pid)
			{
				letra = 'E';
				printf("%c:Nasci, PID:%d PPID: %d\n", letra,getpid(), getppid());
				pid = fork();
				if(!pid)
				{
					letra = 'F';
					printf("%c:Nasci, PID:%d PPID: %d\n", letra,getpid(), getppid());	
					pid = fork();
					if(!pid)
					{
						letra = 'G';
						printf("%c:Nasci, PID:%d PPID: %d\n", letra, getpid(), getppid());
					}
					else wait(&aux);
				}
				else
					wait(&aux);
			}
			else
			{
				wait(&aux);
			}
		}

	}
	
		
	printf("%c:Morri\n", letra);
	exit(0);
	
}
