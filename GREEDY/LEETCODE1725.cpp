#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution{
    public:
        int countGoodRectangles(vector<vector<int> > &rectangles){
            int maxv = 0; int count = 0;
            for(int i=0; i<rectangles.size(); i++){
                int mostlength = min(rectangles[i][0], rectangles[i][1]);
                if(maxv < mostlength){
                    maxv = mostlength;
                    count = 1;
                }
                else if(maxv == mostlength)
                    count++;
            }
            return count;
        }
};

int main(){
    vector <vector<int> > r1;
    vector <int> r2;

    int N; 
	cout << "Enter number of rectangles: ";
	cin >> N;
	for(int i=0; i<N; i++){
		cout << "Enter width and length of rectangle: ";
		int x, y;
		cin >> x >> y; 
		r2.push_back(x);
		r2.push_back(y);
		r1.push_back(r2);
		r2.clear();
	}

    Solution A;
    cout << A.countGoodRectangles(r1);

}