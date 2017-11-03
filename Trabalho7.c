#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

#define READ 0
#define WRITE 1

//Processo filho envia dados para o processo pai

int main(int argc, char *argv[])
{
	int n, fd[2];
	pid_t pid;
	if (pipe(fd)<0)
	{
		fprintf(stderr,"Erro no tubo\n");
		_exit(1);
	}
	char tbR[10], tbW[10],lul[10];
	sprintf(tbR, "%d", fd[READ]);
	sprintf(tbW, "%d", fd[WRITE]);
	
	for(n = 0; n < atoi(argv[1]); n++)
		if (fork()==0)
		{
			sprintf(lul, "%d", n);
			close(fd[READ]);
			execl("./prod", "Produtor", lul, tbW,NULL);
		} 
		
	
	for(n = 0; n < atoi(argv[2]) - 1; n++)
		if(fork() == 0)
		{	
			sprintf(lul, "%d", n);
			close(fd[WRITE]);
			execl("./cons", "Consumidor", lul ,tbR,NULL);
		}
		
	sprintf(lul, "%d", n);
	close(fd[WRITE]);
	execl("./cons", "Consumidor", lul ,tbR,NULL);

}
