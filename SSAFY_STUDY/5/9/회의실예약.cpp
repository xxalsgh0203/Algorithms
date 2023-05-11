#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int N, M;

int main() {
    cin >> N >> M;

    map<string, vector<pair<int, int>>> rooms; // 회의실 이름, 시작시간
    vector<string> room_names;
    map<string, vector<pair<int, int>>>::iterator it;

    for (int i = 0; i < N; i++) {
        string room_name;
        cin >> room_name;
        room_names.push_back(room_name);
    }

    sort(room_names.begin(), room_names.end());

    for (int i = 0; i < M; i++) {
        string room_name;
        int start_time, end_time;
        cin >> room_name >> start_time >> end_time;
        rooms[room_name].push_back(make_pair(start_time, end_time));
    }

    for (it = rooms.begin(); it != rooms.end(); it++)
        sort(it->second.begin(), it->second.end());

    // for (auto i : rooms) {
    //     sort(i.second.begin(), i.second.end());
    // }       -------> 이거 안됨!!

    int cnt = 0;

    for (auto i : rooms) {
        if (room_names[cnt] != i.first) {
            while (1) {
                cout << "Room " << room_names[cnt] << ":" << '\n';
                cout << "1 available:" << '\n';
                cout << "09-18" << '\n';
                cout << "-----" << '\n';
                cnt++;
                if (room_names[cnt] == i.first)
                    break;
            }
        }
        cout << "Room " << i.first << ":\n";
        vector<string> result;

        if (i.second[0].first != 9) {
            string temp = "09-" + to_string(i.second[0].first);
            result.push_back(temp);
        }

        for (int j = 0; j < i.second.size() - 1; j++) {
            if (i.second[j].second != i.second[j + 1].first) {
                string temp = to_string(i.second[j].second) + '-' + to_string(i.second[j + 1].first);
                result.push_back(temp);
            }
        }

        int size = i.second.size();

        if (i.second[size - 1].second != 18) {
            string temp = to_string(i.second[size - 1].second) + "-18";
            result.push_back(temp);
        }

        if (result.size() == 0) {
            cout << "Not available" << '\n';
        } else {
            cout << result.size() << " available:" << '\n';
            for (int k = 0; k < result.size(); k++) {
                cout << result[k] << '\n';
            }
        }

        if (i.first != rooms.rbegin()->first) { // rbegin : 마지막 원소
            cout << "-----" << '\n';
        }
        cnt++;
    }
}