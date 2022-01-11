// version 1

// #include <string>
// #include <vector>
// #include <algorithm>

// using namespace std;

// bool solution(vector<string> phone_book) {
//     bool answer = true;
//     sort(phone_book.begin(), phone_book.end());
//     for(int i=0; i<phone_book.size()-1; i++){
//         if(phone_book[i] == phone_book[i+1].substr(0, phone_book[i].size()))
//             return false;
//     }
//     return true;
// }

// version 2

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string, bool> hash_map;

    for(int i=0; i<phone_book.size(); i++){
        hash_map[phone_book[i]] = true;
    }

    for(int i=0; i<phone_book.size(); i++){
        string phonenumber = "";
        for(int j=0; j<phone_book[i].size(); j++){
            phonenumber += phone_book[i][j];
            if(hash_map[phonenumber]&& phonenumber != phone_book[i])
                return false;
        }
    }
    return true; 
}
