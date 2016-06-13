#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define stod(X) (X==0? 0: X-'0')

char input[10000] = {0,};
char fir[100][100] = {0,}, sec[100] = {0,}, an[100][100] = {0,};

int Point(char fir[100][100], int j);
void reverse(char *arr, int len); // 계산하기 전 배열에 있는 수 뒤집는 함수
char Pick(char fir[100][100], int j);
void Clear();
void End();
void Error();
void Size(char fir[100][100], int j );
void Plus(int n);

void mult(){
	
	int c,d,e,f,g[100],h[100],l[100]={0,},j,k;		
	
	c=strlen(fir[0]);
	
	for(e=0;e-c;e++)
		g[c-e]=fir[0][e]-'0';
	
		d=strlen(fir[1]);
	
	for(e=0;e<d;e++)
		h[d-e]=fir[1][e]-'0';
	
	for(e=1;e<=c;e++)
	{
		for(f=1;f<=d;f++)
		{
			l[e+f-1]+=g[e]*h[f];
			if(l[e+f-1]>=10)
			{
				l[e+f]+=l[e+f-1]/10;
				l[e+f-1]%=10;
			}		
		}
	}
	for(e=99;e>=1;e--)
		if(l[e]!=0) break;
	for(e=e;e>=1;e--)
		printf("%d",l[e]);
	printf("\n");

	return ;
}
int main()
{
	char n;
	int i, j, k, m;
	int u[100] = {0,};//소숫점에씀
    int s = 0, a;	
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
				if (Pick(fir, j-1) == 'p'){																//50자리, 소수점9자리 넘어가면 error
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
		for(a = 0; a < j; a++){
			u[a] = Point(fir,a);
       printf("%d\n", u[a]);
	  
		}

		
		if (sec[s] == '+')
			Plus(s);
			printf("답: %s\n", an[0]);
	
		if (sec[s]=='*')
			mult();
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

char Pick(char fir[100][100], int m){   	//50자리, 소수점 9자리가 넘어가는지 판별하는 함수
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


void reverse(char *arr, int len){
	char temp;
	int i;
	for(i=0; i<len/2; i++){
		temp=arr[i];
		arr[i]=arr[len-1-i];
		arr[len-1-i]=temp;
	}
}

void Plus(int n)
{	
	int i, up = 0;
	int len;
	char a[100][100] = {0,};
	
	a[n][100] = fir[n][100];
					a[n+1][100] = fir[n+1][100];
				if( strlen(fir[n]) > strlen(fir[n+1]) )
					len = strlen(fir[n]);
				else len = strlen(fir[n+1]);
					reverse(fir[n], strlen(fir[n]));
					reverse(fir[n+1], strlen(fir[n+1]));
				for(i=0; i<=len; i++){
					an[n][i] = (stod(fir[n][i]) + stod(fir[n+1][i]) + up ) % 10 + '0';
					if((stod(fir[n][i]) + stod(fir[n+1][i]) + up) > 9)
						up=1;
					else
						up=0;
					an[n][len+1] = '\0';
					}
					
					if(an[0][len] == '0') 
						an[0][len] = 0;
						reverse(an[0], strlen(an[0]));
					}
					
int Point(char fir[100][100], int j)
{
	int l, i = 0, n, count[100];
	int dot;
	while((fir[j][i] >= '0')&&(fir[j][i]<='9')){
    	 i++;
        }
	count[j] = i;
	while(fir[j][i] != '\0'){
			
     	i++;
     	}
	dot = i - count[j] - 1;
if(dot == -1)	
	dot = 0;
	return dot;
  }	
