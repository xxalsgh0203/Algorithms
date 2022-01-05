#include <iostream>
#include <queue>

using namespace std;
priority_queue<int, vector<int>, greater<int> > max_heap;
priority_queue<int> min_heap;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	for(int i=0; i<N; i++){
		int temp;
		cin >> temp;
		if(max_heap.size() == min_heap.size()){
			min_heap.push(temp);
		}
		else
		{
			max_heap.push(temp);
		}

		if(!min_heap.empty() && !max_heap.empty() && min_heap.top()>max_heap.top()){
			int temp1 = min_heap.top();
			int temp2 = max_heap.top();
			min_heap.pop();
			max_heap.pop();
			min_heap.push(temp2);
			max_heap.push(temp1);
		}
		
		cout << min_heap.top() << '\n';
	}

	return 0;
}