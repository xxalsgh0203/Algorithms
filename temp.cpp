#include <iostream>
#include <cstdlib>

using namespace std;

int getSum (int val, int dist = 1)
{
   // Implement function
   int total = 0;
   if(dist == 1 && val % 2 == 0){
       return val;
   }
   else if(dist == 1 && val % 2 != 0){
       return 0;
   }
   else if(dist != 0 && val % 2 == 0){
       return total = val + getSum(val-1, dist-1);
   }
   else if(dist !=0 && val % 2 != 0){
       return total = getSum(val-1, dist-1);
   }

   return -1;
}


int main ( int argc, char **argv )
{
    int startval=0, startdist=1;

    if ( argc == 2 ) {
        startval = std::atoi(argv[1]);
    }
    if (argc == 3 ) {
        startval = std::atoi(argv[1]);
        startdist = std::atoi (argv[2]);
    }

    int sum = getSum(startval, startdist);
    cout << "Input start value was " << startval << " Distance " << startdist << " Sum : " << sum << endl;

    return 0;
}