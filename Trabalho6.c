#include "defs.h"

int main(int argc, char *argv[])
{
    char id[10];
    int smid = shmget(123456789, 1024, IPC_CREAT|SHM_R|SHM_W);
    //somente pra iniciar
    sems *las = shmat(smid, 0, 0);
    init(las);
    sprintf(id, "%d", smid);
    printf("%d\n", atoi(argv[1]));
    int i, x = atoi(argv[1]);

    for(i = 0; i < x; i++)
        if(fork() > 0)
        {
            execl("./prod", id, NULL);
            puts("Fazendo os caras cons");
            sleep(10);
        }

    /*for(i = 0; i < atoi(argv[2]) - 1; i++)
        if(fork() > 0)
        {
            execl("./cons", id, NULL);
            puts("Fazendo os caras prod");
        }

    execl("./cons", id, NULL);*/
}
