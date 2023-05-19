#include <iostream>
#include <list>

#define endl "\n"
using namespace std;

int N;
int PW_N;

list<int> List;

void Input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        List.push_back(a);
    }
    cin >> PW_N;
    for (int i = 0; i < PW_N; i++) {
        char command;
        cin >> command;
        if (command == 'I') {
            int x;
            cin >> x;
            int N;
            cin >> N;
            list<int> PW;

            for (int j = 0; j < N; j++) {
                int a;
                cin >> a;
                PW.push_back(a);
            }

            list<int>::iterator it = List.begin();
            for (int i = 0; i < x; i++)
                it++;
            List.splice(it, PW);
        } else {
            int x;
            cin >> x;
            int N;
            cin >> N;
            list<int>::iterator Start = List.begin();
            list<int>::iterator End;
            for (int i = 0; i < x; i++)
                Start++;
            End = Start;
            for (int i = 0; i < N; i++)
                End++;
            List.erase(Start, End);
        }
    }
}

void Solve() {
    int Tc = 10;
    for (int T = 1; T <= Tc; T++) {
        List.clear();
        Input();

        cout << "#" << T << " ";
        for (int i = 0; i < 10; i++) {
            cout << List.front() << " ";
            List.pop_front();
        }
        cout << endl;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("Input.txt", "r", stdin);
    Solve();

    return 0;
}
