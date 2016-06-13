#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char minus(char fir[100][100], int j);
void Clear();
void End();
void Error();
void Size(char fir[100][100], int j );
int main()
{
	char A[9][1000];
	char input[10000] = {0,};
	char fir[100][100] = {0,}, sec[100] = {0,};
	char n;
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
				if (minus(fir, j-1) == 'p'){																	//50자리, 소수점9자리 넘어가면 error
					Error();
					return 0;
	            } 
		  }	   
	    }
		else if(input[0] == 'c' && input[1] == 'l' && input[2] == 'e' && input[3] == 'a' && input[4] == 'r')		// clear 명령
			Clear();
		else if(input[0] == 'e' && input[1] == 'n' && input[2] == 'd')												// end 명령
			End();	
		

		else if(input[i] != ' ' && input[i] != '.' && (input[i] != '+' && input[i] != '-' && input[i] != '/' && input[i] != '*' && input[i] != '%')){																									 // error 일때 조건
			Error();
			return 0;
		}
		else if(input[i] != ' ' && input[i] != '.' && (input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*' || input[i] == '%')){																												 // 기호를 sec배열에 저장 
			    sec[m] = input[i];
				m++;
          		}
		}
		sec[m] = '\0';
	// Size(fir, j);
	}	
		return 0;
		}

void Clear(){
	system("clear");
}	

void End(){
	exit(-1);
}

void Error(){
	printf("error");
}

char minus(char fir[100][100], int m){
int i , count[100];  
char y = 'o', n = 'p';
  for(int j = 0; j-1 <= m; j++){
	i = 0;	  
	while((fir[j][i] >= '0')&&(fir[j][i]<='9')){
    	 i++;
        }
	count[j] = i;
	if(i > 50){
  		return n;
       	  }
	while(fir[j][i] != '\0'){
     	i++;
     	}
	if((i-count[j])>10){
  		return n;
    }
}
}
void Size(char fir[100][100], int j)
{
	int a[100];
	for (int i = 0; i < j; i++){
		for (int k = 0; fir[i][k] != '.'; k++){
		a[i] = strlen(fir[i]);
		printf("%d", a[i]);
	}
	}
}
