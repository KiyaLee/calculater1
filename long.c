#include <stdio.h>
#include <string.h>
int main()
{
		char input[10000] = {0,};
		char fir[100][100] = {0,}, sec[100] = {0,};
		unsigned char llen[102];
		int i, j, k, m, a;
		int count[100]={0,}, con[100]={0,};
		int len;

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
		

	
			con[count[i++]]=strlen(input[count[i]]);
			len=con[0]+con[1];
			memset(llen,0x00,len+2);

		
			for(i=0;i <con[0];i++)
			{		for(j=0;j<con[1];j++)
			
				{
					a=len-i-j;
					llen[k] += (input[0][con[0]-i-1]-'0')*(input[1][len[1]-j-1]-'0');
				if (llen[k]>9)
				{
					llen[k-1] += (llen[k]/10);
					llen[k] %=10;
				}}
				for (i=0; i<= llen[k]; i++)
				{	llen[i]+='0';}
				
				for(i=0;llen[i]=='0';)
				{i++;}

		printf("곱셈?: %s\n", llen[i]);
				
				}








	printf("%s\n", fir[2]);
	printf("%c\n", sec[0]);
	printf("%c\n", sec[1]);
	printf("%c\n", sec[2]);
		
	return 0;
}















