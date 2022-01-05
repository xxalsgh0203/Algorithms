//N 키로그램 배달해야할때, 3키로 5키로 배달해야할때 몇봉지 배달해야하는가?
#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, i, j;
	int sum = 0;
	scanf("%d", &N);
	
	int * P = malloc(sizeof(int) * N);
	for(i=0; i<N; i++){
		scanf("%d", &P[i]);
	}
	
	int temp;
	for(i=0; i<N; i++){
		for(j=i+1; j<N; j++){
			if(P[j] < P[i]){
				temp = P[j];
				P[j] = P[i];
				P[i] = temp;
			}
		}
	}
	
	int * result = malloc(sizeof(int) * N); 
	for(i=0; i<N; i++){
		for(j=0; j<=i; j++){
			result[i] += P[j];  
		}
	}
	
	for(i=0; i<N; i++){
		sum += result[i];
	}
	
	printf("%d", sum);
}