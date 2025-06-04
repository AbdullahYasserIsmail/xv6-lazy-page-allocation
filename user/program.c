#include "kernel/types.h"
#include "kernel/fcntl.h"
#include "user/user.h"



int main(int argc, char *argv[])
{
    if(argc != 2)
      printf("Failed! Please enter only the sleeping time.\n");

    else
    {
      int sleeping_time = atoi(argv[1]);
      sleep(sleeping_time);
    }
  exit(0);
}
