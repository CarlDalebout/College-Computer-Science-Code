#include <stdio.h>
#include "BarberShop.h"
#include "thread.h"

#define NCUST 10
#define SIMTIME 10

void *barberMain(void *bsPtr)
{
  BarberShop *bs = (BarberShop *)bsPtr;
  bs->barberDay();
  return NULL;
}

void *custMain(void *bsPtr)
{
  BarberShop *bs = (BarberShop *)bsPtr;
  while(1){
    bs->getHairCut();
    thread_sleep(1, 0);
  }
  return NULL;
}

void *clockMain(void *bsPtr)
{
  BarberShop *bs = (BarberShop *)bsPtr;
  thread_sleep(SIMTIME, 0);
  printf("CLOCK: Closing time\n");
  bs->clockRingsClosingTime();
  return NULL;
}


int main(int argc, char **argv)
{
  int ii;
  BarberShop *bs = new BarberShop();
  thread_t barber;
  thread_t customers[NCUST];
  thread_t clock;

  thread_create_p(&barber, barberMain, bs);
  thread_create_p(&clock, clockMain, bs);
  for(ii = 0; ii < NCUST; ii++){
    thread_create_p(&customers[ii], custMain, bs);
  }
  thread_join(barber);
}
