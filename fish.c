#include <stdio.h>

int main(void)
{
	int year, month;
	int total[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int lyear, day, a, i;

	FILE *yo;
	yo = fopen("year.ln", "r");

	fscanf(yo,"%d", &year);
	
	
	if ((year)%4==0)
		if((year)%100!=0|| (year)%400==0)	
			total[2]=29;

	lyear=year-1;
	day = (lyear+(lyear/4)-(lyear/100)+(lyear/400)+1)%7;

	printf("\n\n");

	for(month=1 ; month<=12; month++){
		printf("\n     %d년\n", year);
		printf("\n 일 월 화 수 목 금 토");
			for(i=-day; i<total[month];i++)
			{
			if((i+day)%7 == 0)
				printf("\n");
			if(i<0)
				printf("   ");
			else
				printf("%3d",i+1);
			}
	}

	
	fclose(yo);

	return 0;
}
