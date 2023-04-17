#include "RWObj.h"
#include "thread.h"

#define NWORKERS 10
static const int NOPS = 10;

void *readSome(void *rwObjPtr)
{
  int ii;
  RWObj *rwObj = (RWObj *)rwObjPtr;
  for(ii = 0; ii < NOPS; ii++){
    rwObj->read();
  }
  return NULL;
}

void *writeSome(void *rwObjPtr)
{
  int ii;
  RWObj *rwObj = (RWObj *)rwObjPtr;
  for(ii = 0; ii < NOPS; ii++){
    rwObj->write(ii);
  }
  return NULL;
}

int main(int argc, char **argv)
{
  int ii;

  RWObj *rwObj = new RWObj();
  thread_t rworkers[NWORKERS];
  thread_t wworkers[NWORKERS];

  for(ii = 0; ii < NWORKERS; ii++){
    thread_create_p(&rworkers[ii], readSome, rwObj);
    thread_create_p(&wworkers[ii], writeSome, rwObj);
  }

  for(ii = 0; ii < NWORKERS; ii++){
    thread_join(rworkers[ii]);
    thread_join(wworkers[ii]);
  }

}
