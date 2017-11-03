#include "defs.h"

int main(int argc, char *argv[])
{
    char id[10], nro[10];
    int smid = shmget(123456789, 1024, IPC_CREAT|SHM_R|SHM_W);
    //somente pra iniciar
    //sems *las = shmat(smid, 0, 0);
    //init(las);
    sprintf(id, "%d", smid);
    int i, x = atoi(argv[1]);

    for(i = 0; i < atoi(argv[1]); i++)
    {
        
        sprintf(nro, "%d", i);
        if(fork() > 0)
            execl("./prod", "", id, nro, NULL);
    }

    for(i = 0; i < atoi(argv[2]) - 1; i++)
    {
        sprintf(nro, "%d", i);
        if(fork() > 0)
            execl("./cons", "", id, nro, NULL);
    }
        
    sprintf(nro, "%d", i);
    execl("./cons", "", id, nro, NULL);
}
