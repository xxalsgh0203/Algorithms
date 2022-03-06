#include <iostream>
#include <string.h>
#define MAX 9

using namespace std;

int arr[MAX];
int visited[MAX];
int min_dist=987654321;
int N;

void calMin(int distance, int rem, int pindex, int fueled_car, int ins, int g_or_d)
{
	if(fueled_car==N){ // 모두 주유 되었을 때
		if(min_dist>distance){
			min_dist=distance;
		}
		return;
	}

	if(rem<=0) return;

	if(ins==0 && g_or_d==0){
		for(int k=1;k<=N;k++){
			if(!visited[k] && arr[k]==1){
				visited[k]=1;
				// 다음 휘발류 차량으로 이동
				calMin(distance+(k>pindex ? k-pindex:pindex-k), rem-1, k, fueled_car+1, 0, 0);
				// 휘발유 주유소로 이동
				calMin(distance+(k>pindex ? k-pindex:pindex-k), 2, k, fueled_car+1, 1, 0);
				// 디젤 주유소로 이동
				calMin(distance+(k>pindex ? k-pindex:pindex-k), 2, k, fueled_car+1, 2, 0);
				visited[k]=0;
			}
		}
	}

	if(ins==0 && g_or_d==1){
		for(int k=N; k>=1; k--){
			if(!visited[k] && arr[k]==2){
				visited[k]=1;
				// 다음 휘발유 차량으로 이동
				calMin(distance+(k>pindex ? k-pindex:pindex-k), rem-1, k, fueled_car+1, 0, 1);
				// 휘발류 주유소로 이동
				calMin(distance+(k>pindex ? k-pindex:pindex-k), 2, k, fueled_car+1, 1, 1);
				// 경유 주유소로 이동
				calMin(distance+(k>pindex ? k-pindex:pindex-k), 2, k, fueled_car+1, 2, 1);
				visited[k]=0;
			}
		}
	}

	if(ins==1){
		//fill gas and recall  
		calMin(distance+(pindex-0), 2, 0, fueled_car, 0, 0);
	}
	if(ins==2){
		//fill diesel and recall
		calMin(distance+((N+1)-pindex) , 2, N+1, fueled_car, 0, 1);
	}
}

int main(void){
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case < T; test_case++)
	{
		cin >> N; // 자동차 대수

		for(int i=1; i<=N; i++){
			cin >> arr[i];
		}

		calMin(0,2,0,0,0,0);

		if(min_dist==987654321) // 모두 경유 인 경우
		{
			// 모두 경유인 경우, 경유 주유소로 가서 충전
			calMin(N+1,2,N+1,0,0,1);
		}
        cout << "#" << test_case + 1 << " " << min_dist << '\n';

		min_dist=987654321; // 다음테스트케이스를 위해 초기화
	}
}