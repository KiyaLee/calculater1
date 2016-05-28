#include <stdio.h>
int main()
{
	char a[59], b[59], c;
	int N[59];
	int i = 0 , j;

	while((c == getchar()) != '\n'){
		scanf("%s", a);
		if (a[i] >= '0' && a[i] <= '9'){
			printf("%s", a);
			if (c <= '0' || c >='9')
				break;
	
		}
		else{
			return 0;
		}
	}
 return 0;
}

