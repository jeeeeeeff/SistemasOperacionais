#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/types.h>

int qtde = 0;
pthread_mutex_t mut;
sem_t msg, prupru;
void *pombo(void)
{
      while(1)
      {
            sem_wait(&prupru);
            pthread_mutex_lock(&mut);
            puts("^(0.0)^ Levando mensagens ^(0.0)^");
            int i;
            for(i = 0; i < 20; i++) sem_post(&msg);
            qtde = 0;
            pthread_mutex_unlock(&mut);
            sleep(15);
            puts("^(0.0)^ Voltando ao sono ZzZzZzZzZ ^(0.0)^");

      }
}

void* postit(void* x)
{
      int i = (int)x;
      while(1)
      {
            sem_wait(&msg);
            pthread_mutex_lock(&mut);
            if(qtde == 19)
            {
                  sem_post(&prupru);
            }

            qtde++;
            int asd = rand() % 10;
            printf("Colando mensagem, qtde: %d TID: %d, vou dormir por %d\n", qtde, i, asd);
            pthread_mutex_unlock(&mut);
            sleep(asd);
      }
}

int main(int argc, char *argv[])
{
      int x = atoi(argv[1]),i;
      pthread_t tid[x+1], p;
      pthread_mutex_init(&mut, NULL);
      sem_init(&msg, 0 ,20);
      sem_init(&prupru, 0 ,0);
      //sem_wait(&prupru);
      pthread_create(&p, NULL, pombo, (void*)0);
      for(i = 0; i < x; i++) pthread_create(&tid[i], NULL, postit, (void*)i);
      for(;;);
}
