#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
  int fd[2];
  char buf[25];
  pipe(fd);
  int pid = fork();
  
  if (pid == 0)
  {
    int n = read(fd[0], buf, sizeof(buf));
    write(1, buf, n); 
    close(fd[0]); 
  }
  else
  {

    write(fd[1], "Medhat\n", 7);
    close(fd[1]); 
  }
  
  exit(0);
}

