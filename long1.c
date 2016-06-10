#include <stdio.h>
#include <string.h>
#define MAX 50    /* (10^MAX - 1) * (10^MAX - 1) 까지 계산됩니다. */
void main()
{
	char num[2][MAX+1], *ptr;
	unsigned char mul[MAX+MAX+2];
	int count, len[2], mul_len, i, j, k;
	  for ( count = 0; count < 2; )
		    {
				    printf ( "정수%d 입력(%d자리 이하) : ", count+1, MAX ); gets ( num[count] );
					    ptr = num[count];
						    while ( *ptr ) if ( *ptr < '0' || *ptr > '9' ) break; else ptr++;
							    if ( *ptr ) printf ( "다시 입력하세요.\n" ); else len[count++] = strlen(num[count]);
								  }
	    mul_len = len[0] + len[1]; /* 이게 마지막 자릿값입니다. 실제 길이는 이거보다 1 큼 */
		  memset ( mul, 0x00, mul_len+2 ); /* mul 배열 초기화.. */
		  	    for ( i = 0; i < len[0]; i++ )
					    for ( j = 0; j < len[1]; j++ ) /* 곱셈은.. 정수2부터 곱해짐.. */
						    {
								      k = mul_len-i-j; /* 뒷자리부터 연산.. 올림값 처리를 위해서.. */
									        mul[k] += (num[0][len[0]-i-1]-'0') * (num[1][len[1]-j-1]-'0'); /* 곱함 */
											      if ( mul[k] > 9 ) { mul[k-1] += (mul[k]/10); mul[k] %= 10; } /* 올림값 처리 */
												      }
			  for ( i = 0; i <= mul_len; i++ ) mul[i] += '0';  /* mul 배열을 문자화 */
			    for ( i = 0; mul[i] == '0'; ) 
				i++; /* 앞자리가 0 이면 출력에서 제외하기 위해서 */

				  printf ( "%s * %s\n= %s\n", num[0], num[1], &mul[i] );
		  		
			   	return ;
}


