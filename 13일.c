#include <stdio.h>
#include <string.h>
#define stod(X) (X==0? 0: X-'0')

char input[10000] = {0,};
char fir[100][100] = {0,}, sec[100] = {0,}, an[100][100] = {0,};

void reverse(char *arr, int len); // 계산하기 전 배열에 있는 수 뒤집는 함수

void reverse(char *arr, int len){
	char temp;
	int i;
	for(i=0; i<len/2; i++){
		temp=arr[i];
		arr[i]=arr[len-1-i];
		arr[len-1-i]=temp;
	}
}

void plus(int n);
void plus(int n)
{
	
	int i, up = 0;
	int len;
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

	if(an[0][len] == '0') an[0][len] = 0;
	reverse(an[0], strlen(an[0]));
}

void minus(int n);
void minus(int n)
{
	int i, down=0;
	int len;
	int ten = 10;
	
	if( strlen(fir[n]) > strlen(fir[n+1]) )
		len = strlen(fir[n]);
	else len = strlen(fir[n+1]);

	reverse(fir[n], strlen(fir[n]));
	reverse(fir[n+1], strlen(fir[n+1]));

	for(i=0; i<=len; i++){
		
		if(stod(fir[n][i]) - stod(fir[n+1][i]) >= 0){
			an[n][i] = (stod(fir[n][i]) - stod(fir[n+1][i]) ) + '0';
				if((stod(fir[n][i]) - stod(fir[n+1][i]) + down) < 0)
					down=-1;
				else
					down=0;
			}
		else{
		an[n][i] = ( 10 + (stod(fir[n][i]) - stod(fir[n+1][i]))) + '0';
				if((10 + stod(fir[n][i]) - stod(fir[n+1][i]) + down) < 0)
					down=-1;
				else
					down=0;
		    }
	//	an[n][len+1] = '\0';
	}
	if(an[0][len] == '0') an[0][len] = 0;
	reverse(an[0], strlen(an[0]));
}

int main()
{
	int i, j, k, m;
	int s = 0;

	printf("수를 입력하세요 : ");
	gets(input);	
	printf("input:%s\n", input);
        
    for(i=0, j=0, k=0, m=0; input[i] != '\0'; i++){
		if((input[i] >= '0')&&(input[i] <= '9')||(input[i] == '.')){
			fir[j][k] = input[i];
			k++;
				if((input[i+1] != '.')&&(input[i+1] < '0')||(input[i+1] > '9')){
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

	
	if (sec[s] == '+') plus(s);
	printf("an : %s\n\n\n", an[0]);
	
	if (sec[s] == '-') minus(s);
	printf("an : %s\n\n\n", an[0]);
	return ;
}