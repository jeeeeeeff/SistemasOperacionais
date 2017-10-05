#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/types.h>

int i = 0;
pthread_mutex_t isso[5];

void *processo(void* x)
{
      int id = (int)x;
      pthread_mutex_lock(&isso[id]);
      printf("-----------------------------Lock : %d------------------------------\n", id);
      int p;
      for(p = 1;p < 201; p++)
            printf("%d ", p+(id*200));
      printf("\n----------------------------Unlock--------------------------------\n");
      pthread_mutex_unlock(&isso[id]);
      if(i != 5) pthread_mutex_unlock(&isso[id+1]);
}

int main(void)
{
      int x;
      pthread_t tid[5];
      for(x = 0; x < 5; x++)
      {
            pthread_mutex_init(&isso[x],NULL);
            pthread_mutex_lock(&isso[x]);
      }
      for(x = 0; x < 5; x++) pthread_create(&tid[x], NULL, processo, (void*)x);
      pthread_mutex_unlock(&isso[0]);

      for(x = 0; x < 5; x++) pthread_join(tid[x], NULL);

}
