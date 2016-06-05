#include <stdio.h>

int main()
{
	char input[100] = {0,};
	char fir[100] = {0,}, sec[100] = {0,};
	int i;

	printf("수를 입력하세요 : ");
	gets(input);	
	printf("input:%s\n", input);

	for(i=0; input[i] != '\0'; i++){
		if(input[i] == ' ')
			input[i] == '\0';
		else fir[i] = input[i];
	}

	printf("fir:%s\n", fir);
	printf("input:%s\n", input);

	return 0;
}
