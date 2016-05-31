#include <stdio.h>
#include <string.h>

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
	int len, i, j, up = 0;
	printf(" 1 = ");
	scanf("%s", a[0]);

	printf("2 = ");
	scanf("%s", a[1]);

	if(strlen(a[0]) > strlen(a[1])){
		len = strlen(a[0]);
	}
	else len = strlen(a[1]);

	reverse(a[0], strlen(a[0]));
	reverse(a[1], strlen(a[1]));

	return 0;
}
