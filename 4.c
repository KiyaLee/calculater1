#include <stdio.h>
#include <stdlib.h>

void Clear(char input[]);

int main()
{
	char A[9][1000];
	char input[10000] = {0,};
	char fir[100][100] = {0,}, sec[100] = {0,};
	int i, j, k, m;
	
	while(1){
		printf("수를 입력하세요 : ");
		gets(input);	
		printf("input:%s\n", input);

	for(i=0, j=0, k=0, m=0; input[i] != '\0'; i++){

		if((input[i] >= '0')&&(input[i] <= '9')||(input[i] == '.')){
			fir[j][k] = input[i];
			k++;
      	  if((input[i+1] != '.') && (input[i+1] < '0')||(input[i+1] > '9')){										// 띄어쓰기 있을 때 널문자
				fir[j][k] = '\0';
			    j++;
		        k = 0;
	            } 
	    }
		else if(input[0] == 'c' && input[1] == 'l' && input[2] == 'e' && input[3] == 'a' && input[4] == 'r')		// clear 명령
			system("clear");
		else if(input[0] == 'e' && input[1] == 'n' && input[2] == 'd')												// end 명령
			exit(-1);	
		else if(input[i] != ' ' && input[i] != '.' && (input[i] != '+' && input[i] != '-' && input[i] != '/' && input[i] != '*' && input[i] != '%')){																												 // error 일때 조건
			printf("error");
			return 0;
		}
		else if(input[i] != ' ' && input[i] != '.' && (input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*' || input[i] == '%')){																												 // 기호를 sec배열에 저장 
			    sec[m] = input[i];
				m++;
          		}
		}
		sec[m] = '\0';
	}	
		return 0;
		}

	



