#include <stdio.h>
#include <string.h>
#define stod(X) (X==0? 0: X-'0')

void reverse(char *arr, int len){
	char temp;
	int i;
	for(i=0; i<len/2; i++){
		temp=arr[i];
		arr[i]=arr[len-1-i];
		arr[len-1-i]=temp;
	}
}

int main(){
	char a[3][102] = {0};
	char b[100] = {0};
	int len, i, j, up = 0;
	/*
	printf(" 1 = ");
	scanf("%s", a[0]);

	printf(" 2 = ");
	scanf("%s", a[1]);
	*/
	printf("Go : ");
	scanf("%s %c %s", &a[0], &b[0], &a[1]);
	printf("%s %c %s\n", a[0], b[0], a[1]);
	if(strlen(a[0]) > strlen(a[1])){
		len = strlen(a[0]);
	}
	else len = strlen(a[1]);

	reverse(a[0], strlen(a[0]));
	reverse(a[1], strlen(a[1]));

	for(i=0; i<len; i++){
		a[2][i]=(stod(a[0][i]) + stod(a[1][i])+up)%10+'0';
		if((stod(a[0][i]) + stod(a[1][i])+up)>9)
			up = 1;
		else up = 0;
	}

	if(a[2][len] == '0')
		a[2][len] = 0;
	reverse(a[2], strlen(a[2]));
	printf("aa + bb = %s\n", a[2]);
	
	return 0;
}
