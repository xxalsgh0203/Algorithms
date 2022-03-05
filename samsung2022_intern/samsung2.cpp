#include <iostream>
#include <string.h>
#define MAX 9
int arr[MAX];
int visited[MAX];
int min_dist=987654321;

using namespace std;

void calc_min(int N, int distance, int rem, int pindex, int NumOfCars, int ins, int g_or_d)
{
	if(NumOfCars==N)
	{
		if(min_dist>distance)
		{
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
				calc_min(N,distance+(k>pindex ? k-pindex:pindex-k), rem-1, k, NumOfCars+1, 0, 0);
				// 휘발유 주유소로 이동
				calc_min(N, distance+(k>pindex ? k-pindex:pindex-k), 2, k, NumOfCars+1, 1, 0);
				// 디젤 주유소로 이동
				calc_min(N, distance+(k>pindex ? k-pindex:pindex-k), 2, k, NumOfCars+1, 2, 0);
				visited[k]=0;
			}
		}
	}

	if(ins==0 && g_or_d==1){
		for(int k=N;k>=1;k--){
			if(!visited[k] && arr[k]==2)
			{
				visited[k]=1;
				//go to next gas car
				calc_min(N, distance+(k>pindex ? k-pindex:pindex-k), rem-1, k, NumOfCars+1, 0, 1);
				//go to gas station
				calc_min(N, distance+(k>pindex ? k-pindex:pindex-k), 2, k, NumOfCars+1, 1, 1);
				//go to diesel station
				calc_min(N, distance+(k>pindex ? k-pindex:pindex-k), 2, k, NumOfCars+1, 2, 1);
				visited[k]=0;
			}
		}
	}

	if(ins==1)
	{
		//fill gas and recall  
		calc_min(N, distance+(pindex-0), 2, 0, NumOfCars, 0, 0);
	}
	if(ins==2)
	{
		//fill diesel and recall
		calc_min(N, distance+((N+1)-pindex) , 2, N+1, NumOfCars, 0, 1);
	}
}

int main(void)
{
	int T, test_case;
	int N;
	int i;

	cin >> T;
	for(test_case = 0; test_case < T; test_case++)
	{
		cin >> N; // 자동차 대수

		for(i=1;i<=N;i++)
		{
			cin >> arr[i];
		}

		calc_min(N,0,2,0,0,0,0);

		if(min_dist==987654321) // 모두 경유 인 경우
		{
			// 모두 경유인 경우, 경유 주유소로 가서 충전
			calc_min(N,N+1,2,N+1,0,0,1);
		}
        cout << "#" << test_case + 1 << " " << min_dist << '\n';

		min_dist=987654321; // 다음테스트케이스를 위해 초기화
	}
}