// #include <iostream>
// #include <string>
// #include <algorithm>

// using namespace std;

// string ltrim(const string &);
// string rtrim(const string &);

// /*
//  * Complete the 'minCost' function below.
//  *
//  * The function is expected to return an INTEGER.
//  * The function accepts following parameters:
//  *  1. INTEGER rows
//  *  2. INTEGER cols
//  *  3. INTEGER initR
//  *  4. INTEGER initC
//  *  5. INTEGER finalR
//  *  6. INTEGER finalC
//  *  7. INTEGER_ARRAY costRows
//  *  8. INTEGER_ARRAY costCols
//  */


// int minCost(int rows, int cols, int initR, int initC, int finalR, int finalC, vector<int> costRows, vector<int> costCols) {
//     int dp[100001][100001] = {0};

//     for(int i=initR; i<=finalR; i++){
//         dp[i][initC] = dp[i-1][initC] + costRows[i];
//     }

//     for(int i=initC; i<=finalC; i++){
//         dp[initR][i] = dp[initR][i-1] + costCols[i];
//     }

//     for(int i=initR+1; i<=finalR; i++){
//         for(int j=initC+1; j<finalC; j++){
//             dp[i][j] = min(dp[i-1][j] + costRows[i], dp[i][j-1] + costCols[j]);
//         }
//     }

//     return dp[finalR][finalC];
// }

// int main()
// {
//     ofstream fout(getenv("OUTPUT_PATH"));

//     string rows_temp;
//     getline(cin, rows_temp);

//     int rows = stoi(ltrim(rtrim(rows_temp)));

//     string cols_temp;
//     getline(cin, cols_temp);

//     int cols = stoi(ltrim(rtrim(cols_temp)));

//     string initR_temp;
//     getline(cin, initR_temp);

//     int initR = stoi(ltrim(rtrim(initR_temp)));

//     string initC_temp;
//     getline(cin, initC_temp);

//     int initC = stoi(ltrim(rtrim(initC_temp)));

//     string finalR_temp;
//     getline(cin, finalR_temp);

//     int finalR = stoi(ltrim(rtrim(finalR_temp)));

//     string finalC_temp;
//     getline(cin, finalC_temp);

//     int finalC = stoi(ltrim(rtrim(finalC_temp)));

//     string costRows_count_temp;
//     getline(cin, costRows_count_temp);

//     int costRows_count = stoi(ltrim(rtrim(costRows_count_temp)));

//     vector<int> costRows(costRows_count);

//     for (int i = 0; i < costRows_count; i++) {
//         string costRows_item_temp;
//         getline(cin, costRows_item_temp);

//         int costRows_item = stoi(ltrim(rtrim(costRows_item_temp)));

//         costRows[i] = costRows_item;
//     }

//     string costCols_count_temp;
//     getline(cin, costCols_count_temp);

//     int costCols_count = stoi(ltrim(rtrim(costCols_count_temp)));

//     vector<int> costCols(costCols_count);

//     for (int i = 0; i < costCols_count; i++) {
//         string costCols_item_temp;
//         getline(cin, costCols_item_temp);

//         int costCols_item = stoi(ltrim(rtrim(costCols_item_temp)));

//         costCols[i] = costCols_item;
//     }

//     int result = minCost(rows, cols, initR, initC, finalR, finalC, costRows, costCols);

//     fout << result << "\n";

//     fout.close();

//     return 0;
// }

// string ltrim(const string &str) {
//     string s(str);

//     s.erase(
//         s.begin(),
//         find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
//     );

//     return s;
// }

// string rtrim(const string &str) {
//     string s(str);

//     s.erase(
//         find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
//         s.end()
//     );

//     return s;
// }


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int minCost(int rows, int cols, int initR, int initC, int finalR, int finalC, vector<int> costRows, vector<int> costCols) {
    int dp[100001][100001] = {0};

    for(int i=initR; i<=finalR; i++){
        dp[i][initC] = dp[i-1][initC] + costRows[i];
    }

    for(int i=initC; i<=finalC; i++){
        dp[initR][i] = dp[initR][i-1] + costCols[i];
    }

    for(int i=initR+1; i<=finalR; i++){
        for(int j=initC+1; j<finalC; j++){
            dp[i][j] = min(dp[i-1][j] + costRows[i], dp[i][j-1] + costCols[j]);
        }
    }

    return dp[finalR][finalC];
}

int main(){
    int rows, cols, initR, initC, finalR, finalC;
    vector<int> costRows;
    vector<int> costCols;
    cin >> rows >> cols >> initR >> initC >> finalR >> finalC;
    for(int i=0; i<rows-1; i++){
        cout << "row" << i << "를 입력하시오" << '\n';
        int temp;
        cin >> temp;
        costRows.push_back(temp);
    }
    for(int i=0; i<cols-1; i++){
        cout << "col" << i << "를 입력하시오" << '\n';
        int temp;
        cin >> temp;
        costCols.push_back(temp);
    }

    cout << minCost(rows, cols, initR, initC, finalR, finalC, costRows, costCols);

    return 0;
}