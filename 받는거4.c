#include <stdio.h>
#include <string.h>
#define stod(X) (X==0? 0: X-'0')

char input[10000] = {0,};
char fir[100][100] = {0,}, sec[100] = {0,};

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
	int len;
	char a[100][100] = {0,};
	a[n][100] = fir[n][100];
	a[n+1][100] = fir[n+1][100];
	if( strlen(a[n]) > strlen(a[n+1]) )
		len = strlen(a[n]);
	else len = strlen(a[n+1]);

	reverse(a[n], strlen(a[n]));
	reverse(a[n+1], strlen(a[n+1]));

	char an[100][100];
	int i, up = 0;
	for(i=0; i<len; i++){
		an[n][i] = (stod(a[n][i] + stod(a[n+1][i])+up)%10+'0';
		if((stod(a[n][i]) + stod(a[n+1][i]) + up) > 9)
			up=1;
		else up=0;
	}
}

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

	int s = 0;
	if (sec[s] == '+') plus(s);

// 배열에 잘 들어갔당 이건 확인하는것들
	printf("fir:%c\n", fir[0][0]);
    printf("fir:%c\n", fir[1][1]);	
    printf("sec:%c\n", sec[0]);
    printf("sec2:%c\n", sec[1]);
	printf("input:%s\n", input);
	printf("%d\n", fir[1][0] + fir[1][1]);        
    printf("%s %s %s %s\n", fir[0], fir[1], fir[2], fir[3]);
	printf("%c %c %c\n", sec[0], sec[1], sec[2]);
	return 0;
}