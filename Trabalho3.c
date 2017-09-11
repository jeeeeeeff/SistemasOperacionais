#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <inttypes.h>
#include <math.h>

#define bilhao 1200000000

double result[16];
int tam = 0;
void* threads_aqui(void *ale)
{
      int i, cod = (int)ale;
      result[cod] = 0;

      for(i = cod*tam; i < (cod*tam + tam); i++)
      {
            if(i % 2)
                  result[cod] += (-1.0)/(2.0*i + 1.0);
            else
                  result[cod] += 1.0/(2.0*i + 1.0);

      }
      return (void*)0;
}

int main(int argc, char *argv[])
{

      if(argc > 1)
      {
            int x = atoi(argv[1]),i;
            tam = bilhao / x;
            pthread_t id[x];
            for(i = 0; i < x; i++)
            {
                  pthread_create(&id[i], NULL, threads_aqui, (void*)i);
            }
            double final = 0;
            for(i = 0; i < x; i++)
            {
                  pthread_join(id[i], NULL);
                  final += result[i];
            }

            printf("Resultado %.20f\n", final*4);
            exit(0);
      }

}
