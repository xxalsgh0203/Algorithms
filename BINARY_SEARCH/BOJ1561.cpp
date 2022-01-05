#include<algorithm>
#include<iostream>
using namespace std;

int N, M; // N명의 아이들, M 가지의 놀이기구
int rides[10001];
const long MAX = 2000000000;

int binarySearch(){
	long result;
	long left = 0;
	long right = MAX * 30; // N최대 * 소요시간 최대 30분
	while(left <= right){ // left, right, middle 은 시간을 나타냄
		long long middle = (left + right) / 2;
		long begin = 0, end = M; // begin = middle분이 되기 전까지 탄 아이들의 수 end = middle분까지 탄 아이들의 수
		for(int i=0; i<M; i++){	// middle분까지 탄 아이들의 수 계산
			end += middle/rides[i];
		}
		begin = end;
		for(int i=0; i<M; i++){	// middle분이 되기 전까지 탄 아이들의 수
			if(middle % rides[i] == 0)
				begin -= 1;
		}
		begin += 1; 

		if(N < begin){	// 이분탐색
			right = middle - 1;
		}
		else if(N > end){ // 이분탐색
			left = middle + 1;
		}
		else{
			for(int i=0; i<M; i++){
				if(middle % rides[i] == 0){
					if(N == begin){
						result = i + 1;
						return result;
					}
					begin += 1;
				}
			}
		}
	}

	return result;
}

int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> N >> M;
	for(int i=0; i<M; i++){
		cin >> rides[i];
	}

	if(N <= M){
		cout << N;
		return 0;
	}

	cout << binarySearch();
}