#include <stdio.h>

int main()
{
	char input[10000] = {0,};
	char fir[100][100] = {0,}, sec[100] = {0,};
	int i, j, k, m;

	printf("수를 입력하세요 : ");
	gets(input);	
	printf("input:%s\n", input);
        
       for(i=0, j=0, k=0, m=0; input[i] != '\0'; i++){
         
 
            if((input[i] >= '0')&&(input[i] <= '9')){
               fir[j][k] = input[i];
               k++;
               if((input[i+1] < '0')&&(input[i+1] > '9')){
              fir[j][k] = '\0';
              j++;
              k = 0;
                 }
             }
            else if(input[i] != ' '){
               sec[m] = input[i];
               m++;
                }

            }
        sec[m] = '\0';
	printf("fir:%s\n", fir);
        printf("sec:%s\n", sec);
	printf("input:%s\n", input);
        
	return 0;
}
