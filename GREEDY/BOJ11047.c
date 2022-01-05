#include <stdio.h>
#include <stdlib.h> // malloc(), calloc() 사용을 위한 헤더

int main(){
    int N, K; // N종류, 합 K원
    scanf("%d %d", &N, &K);

    int *money = malloc(sizeof(int)*N);
    for(int i=0; i<N; i++){
        scanf("%d", &money[i]); // 오름차순, 첫번째 돈 1원, 두번째 돈부터 money[i] 는 money[i-1] 의 배수. 그리디 사용가능
    }

    int count = 0;
    while(K>0){
        if(K/money[N-1] > 0){ 
            int num = K / money[N-1];
            count += num;
            K %= money[N-1];  
        }
        N--;  
    }

    printf("%d", count);
}