#include <stdlib.h>

void display_exit(char dis[10]);

void display_exit(char dis[10])
{
  scanf("%s", &dis[10]);
  if(dis=='end')
    system("exit");
}
