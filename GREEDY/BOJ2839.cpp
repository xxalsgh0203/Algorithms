//N 키로그램 배달해야할때, 3키로 5키로 배달해야할때 몇봉지 배달해야하는가?
#include <stdio.h>

int main(){
	int N, div;
	int result = 0;
	scanf("%d", &N);
	
	while(1){
		if(N % 5 == 0){
			div = N / 5;
			result += div;
			break;
		}
		N -= 3;
		result++;
	}
	
	if(N < 0)
		printf("-1");
	else
		printf("%d", result);
}