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
                }
            else if(input[i] != ' '){
               sec[m] = input[i];
               m++;
                }

          if((input[i]<'0')&&(input[i]>'9')){ 
            fir[j][k] = '\0';
             j++;
             k = 0;
            }
}
	printf("fir:%s\n", fir[0]);
	printf("input:%s\n", input);

	return 0;
}
