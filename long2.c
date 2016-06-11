#include<stdio.h>
#include<string.h>
int main()
{
		char a[100],b[100];
		int c,d,e,f,g[100],h[100],i[100]={0},j,k;
		printf("정수1 입력(20자리 이하)? ");
		scanf("%s",a);
		c=strlen(a);
		for(e=0;e<c;e++)
			g[c-e]=a[e]-'0';
		printf("정수2 입력(20자리 이하)? ");
		scanf("%s",b);
		d=strlen(b);
	
		for(e=0;e<d;e++)
			h[d-e]=b[e]-'0';
		for(e=1;e<=c;e++)
		{
			for(f=1;f<=d;f++)
			{
				i[e+f-1]+=g[e]*h[f];
				if(i[e+f-1]>=10)
				{
					i[e+f]+=i[e+f-1]/10;
					i[e+f-1]%=10;
				}
			}
		}
		printf("%s * %s =\n",a,b);
		for(e=99;e>=1;e--)
			if(i[e]!=0) break;
		for(e=e;e>=1;e--)
			printf("%d",i[e]);
		printf("\n");
		return 0;
}
