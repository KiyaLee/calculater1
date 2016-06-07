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
         
 
            if((input[i] >= '0')&&(input[i] <= '9')||(input[i] == '.')){
               fir[j][k] = input[i];
               k++;
               if((input[i+1] < '0')||(input[i+1] > '9')){
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
// 배열에 잘 들어갔당 이건 확인하는것들
	printf("fir:%c\n", fir[0][0]);
        printf("fir:%c\n", fir[1][1]);
        printf("sec:%c\n", sec[0]);
        printf("sec2:%c\n", sec[1]);
	printf("input:%s\n", input);
	printf("%d\n", fir[1][0] + fir[1][1]);        
        printf("%s %s %s %s\n", fir[0], fir[1], fir[2], fir[3]);
	printf("%s %s %s\n", sec[0], sec[1], sec[2]);
	return 0;
}
