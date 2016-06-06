#include <stdio.h>
#include <stdlib.h>
int main()
{
	char input[1000], mark[1000], num[100]; 
	int i, j, l; 
	int k = 0, m =0;
	
	for (j = 0, input[j]; input[j-1] = '\n'; j++){	// 개행문자가 쓰인다면 정지
		for(j; input[j-1] = ' '; j++){				// 띄어쓰기 전까지
			
			input[j] = getchar();	
			
			if(j == 60){							// . 포함해서 59자리를 받으면 그만
				input[j++] = '\0';
				break;
			}
		}
		if (input[j] != '+' || input[j] != ' ' || input[j] != '-' || input[j] != '/' || input[j] != '*'){	//띄어쓰기, 기호 x일때
			if (k == 0){							// 숫자 전체를 put배열에
				for (l = 0; l < j; l++){			
					put[k] = input[l];
					k++;
				}
			}
			else if (k != 0){
				l = l+3;

				for (l; l < j; l++){
					put[k] = input[l];
					k++;
				}
			}
		}
		else if (input[j] == '+' || input[j] == '-' || input[j] == '-' || input[j] == '/'){
			mark[m] = input[j]
			m++;
		}
		
