#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  printf("==================== Page Table at Start ====================\n");
  vmprint();
  
  int n_pages = 3;
  int page_size = 4096;
  
  char *mem = sbrk(n_pages * page_size);
  printf("==================== Page Table after sbrk() ====================\n");
  vmprint();
  
  mem[0] = 'A';
  printf("==================== Page Table after changing the first element (page 1) ====================\n");
  vmprint();
  
  mem[1] = 'B';
  printf("==================== Page Table after changing the second element (page 1) ====================\n");
  vmprint();
  
  
  mem[4096] = 'C';
  printf("==================== Page Table after changing the first element (page 2) ====================\n");
  vmprint();
  
  
  mem[4096 * 2] = 'D';
  printf("==================== Page Table after changing the first element (page 3) ====================\n");
  vmprint();
  
  
  mem[4096 * 3 - 1] = 'E';
  printf("==================== Page Table after changing the last element (page 3) ====================\n");
  vmprint();
  exit(0);
} 
