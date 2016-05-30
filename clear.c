#include <stdlib.h>

void display_clear(char dis[10]);

void display_clear(char dis[10])
{
  scanf("%s", &dis[10]);
  if(dis=='clear')
    system("clear");
}
