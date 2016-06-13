#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define stod(X) (X==0? 0: X-'0')

char input[10000] = {0,};
char va[100][100] = {0,}, fir[100][100] = {0,}, sec[100] = {0,}, an[100][100] = {0,};
int u[100] = {0,};//소수자리

int Point(char fir[100][100], int j);
void reverse(char *arr, int len); // 계산하기 전 배열에 있는 수 뒤집는 함수
char Pick(char fir[100][100], int j); 
void Clear();
void End();
void Error();
void Size(char fir[100][100], int j );
void Plus(int n);
void mult();
void minus(int n);

void minus(int n){
	int i=0, down;
	int len;
	if( strlen(fir[n]) > strlen(fir[n+1]))
		len = strlen(fir[n]);
	else len = strlen(fir[n+1]);

	reverse(fir[n], strlen(fir[n]));
	reverse(fir[n+1], strlen(fir[n+1]));
	
	for(i; i<=len; i++){
		if(stod(fir[n][i]) >= stod(fir[n+1][i])){
			an[n][i] = stod(fir[n][i]) - stod(fir[n+1][i]);
			down = 0;
		}
		else{
			down = 1;
			an[n][i] = ( (10 - down) + stod(fir[n][i]) - stod(fir[n+1][i]));
		}
	}
}
	
int main()
{
	FILE *Far;
	Far = fopen("variation", "w");
	char n;
	int i, j, k, m;
    int s = 0, a, c, d;	
	while(1){
		printf("수를 입력하세요 : ");
		gets(input);	
		printf("input:%s\n", input);
	
	if((input[0] <= 'z' && input[0] >= 'a') || (input[0] <= 'Z' && input[0] >= 'A')){
		if(input[1] == ' ' && input[2] == '=' && input[3] == ' '){
			for(int b = 4; input[b] != '\0'; b++){
				if((input[b] >= '0')&&(input[b] <= '9')||(input[b] == '.')){
				va[c][d] = input[b];
				d++;
      	  		if((input[b+1] != '.') && (input[b+1] < '0')||(input[b+1] > '9')){										// 띄어쓰기 있을 때 널문자
				va[c][d] = '\0';
			    c++;
		        d = 0;
				}
				}
			}
		}
		if(input[1] == ' ' && input[2] == '='){
			for(int b = 3; input[b] != '\0'; b++){
				if((input[b] >= '0')&&(input[b] <= '9')||(input[b] == '.')){
				va[c][d] = input[b];
				d++;
      	  		if((input[b+1] != '.') && (input[b+1] < '0')||(input[b+1] > '9')){										// 띄어쓰기 있을 때 널문자
				va[c][d] = '\0';
			    c++;
		        d = 0;
				}
				}
			}
		}
		if(input[1] == '=' && input[2] == ' '){
			for(int b = 3; input[b] != '\0'; b++){
				if((input[b] >= '0')&&(input[b] <= '9')||(input[b] == '.')){
				va[c][d] = input[b];
				d++;
      	  		if((input[b+1] != '.') && (input[b+1] < '0')||(input[b+1] > '9')){										// 띄어쓰기 있을 때 널문자
				va[c][d] = '\0';
			    c++;
		        d = 0;
				}
				}
			}
		}
		if(input[1] == '='){
			for(int b = 2; input[b] != '\0'; b++){
				if((input[b] >= '0')&&(input[b] <= '9')||(input[b] == '.')){
				va[c][d] = input[b];
				d++;
      	  		if((input[b+1] != '.') && (input[b+1] < '0')||(input[b+1] > '9')){										// 띄어쓰기 있을 때 널문자
				va[c][d] = '\0';
			    c++;
		        d = 0;
				}
				}
			}
		}
		fprintf(Far, "%s\n", va);
		fclose(Far);
	
	}
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
		

		else if(input[i] != ' ' && input[i] != '.' && (input[i] != '+' && input[i] != '-' && input[i] != '/' && input[i] != '*' && input[i] != '%') && (input[i] <= 'z' && input[i] >= 'a') || (input[i] <= 'Z' && input[i] >= 'A')){																	// error 일때 조건
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
	int on = 0, up, k = 0, ok = 0, ou = 0;
	int i = 0;
	int len, len_1, len_2;
	char in[100][100];
	char fl[100][100];
	int sublen = 0;
				


for( i = 0; input[i] != '\0'; i++){
	if(input[i] == '.'){
		on = 1;
	}
}
i = 0;

if( on == 1 ){
				int q;
				for(q=0; fir[n][q] != '\0'; q++){
					if(fir[n][q] == '.')
						ok = 1;
				}
				if( ok == 0){
					fir[n][q] = '.';
					fir[n][q+1] = '0';
					fir[n][q+2] = '\0';
				}
				int w;
				for(w=0; fir[n+1][w] != '\0'; w++){
					if(fir[n+1][w] == '.')
						ou = 1;
				}
				if( ou == 0){
					fir[n+1][w] = '.';
					fir[n+1][w+1] = '0';
					fir[n+1][w+2] = '\0';
				}


				for(k; fir[n][k] != '.'; k++){
					in[n][k] = fir[n][k];
				}	
				in[n][k] = '\0';
				for(i;fir[n][i] != '\0'; i++){
					fl[n][i] = fir[n][k+1];
					k++;
				}
				fl[n][i] = '\0';
				k=0; i=0;
				for(k; fir[n+1][k] != '.'; k++){
					in[n+1][k] = fir[n+1][k];
				}
				in[n+1][k] = '\0';
				for(i;fir[n+1][i] != '\0'; i++){
					fl[n+1][i] = fir[n+1][k+1];
					k++;;
				}
				fl[n+1][i] = '\0';



				if( strlen(in[n]) > strlen(in[n+1]) ) 
					len_1 = strlen(in[n]);
				else len_1 = strlen(in[n+1]);

				reverse(in[n], strlen(in[n]));	
				reverse(in[n+1], strlen(in[n+1]));

				for(i=0; i<=len_1; i++){
					an[n][i] = (stod(in[n][i]) + stod(in[n+1][i]) + up ) % 10 + '0'; 
					if((stod(in[n][i]) + stod(in[n+1][i]) + up) > 9)
						up=1;		
					else
						up=0;
				}
				if(strlen(fl[n]) > strlen(fl[n+1])){
					len_2 = strlen(fl[n]);
					sublen = strlen(fl[n]) - strlen(fl[n+1]);
					for(; sublen != 0; sublen--){
						fl[n+1][len_2 - sublen] = '0';	
							}		
					
				}
				else if(strlen(fl[n]) <= strlen(fl[n+1])){
						len_2 = strlen(fl[n+1]);
						sublen = strlen(fl[n+1]) - strlen(fl[n]);
						for(; sublen != 0; sublen--){
							fl[n][len_2-sublen] = '0';
						}
				}

				reverse(fl[n], strlen(fl[n]));
				reverse(fl[n+1], strlen(fl[n]));

				for(i=0; i<=len_2; i++){
					bn[n][i] = (stod(fl[n][i]) + stod(fl[n+1][i]) + up ) % 10 + '0';
					if((stod(fl[n][i]) + stod(fl[n+1][i]) + up) > 9)
						up = 1;
					else
						up = 0;
				}

					
					if(an[n][len_1] == '0') 
						an[n][len_1] = 0;
					if(bn[n][len_2] == '0')
						bn[n][len_2] = 0;

						reverse(an[n], strlen(an[n]));
						reverse(bn[n], strlen(bn[n]));
						printf("%s.%s\n", an[n],bn[n]);
}
else if(on == 0){
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

					printf("%s\n", an[n]);	
}
}