#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

char vai = 0;

void trataControlC(int signum)
{
      printf("Foi\n");
      vai++;
      if(vai == 10)
      {
            printf("Really Exit? (y/n)?");
            alarm(5);
            //vai = getchar();
            scanf(" %c", &vai);
            if(vai == 'n' || vai == 'N')
            {
                  alarm(0);
                  vai = 0;
                  return;
            }
            exit(0);

      }
}

void trataControlZ(int signum)
{
      printf("Foi apertado CTRL + C %d vezes\n", vai);
      return;
}

int main(void)
{
      signal(SIGINT, trataControlC);
      signal(SIGTSTP, trataControlZ);
      for(;;);
}
