#include <deque>
#include <iostream>
#include <vector>

using namespace std;

deque<int> naegu;
deque<bool> conveyer;

int N, K, step;

void rotate() {
    conveyer.push_front(conveyer.back());
    conveyer.pop_back();

    naegu.push_front(naegu.back());
    naegu.pop_back();
    conveyer[N - 1] = false;
}

void move() {
    for (int i = N - 2; i >= 0; i--) {
        if ((!conveyer[i + 1]) && (naegu[i + 1] > 0) && (conveyer[i])) {
            conveyer[i] = false;
            conveyer[i + 1] = true;
            naegu[i + 1]--;
        }
    }
    conveyer[N - 1] = false;
}

void put_robot() {
    if (!conveyer[0] && naegu[0] > 0) {
        conveyer[0] = true;
        naegu[0]--;
    }
}

int check() {
    int count_ = 0;
    for (int i = 0; i < 2 * N; i++) {
        if (naegu[i] == 0)
            count_++;
    }
    return count_;
}

int main() {
    step = 1;

    cin >> N >> K;
    for (int i = 0; i < 2 * N; i++) {
        int in;
        cin >> in;
        naegu.push_back(in);
        conveyer.push_back(false);
    }

    while (true) {
        rotate();
        move();
        put_robot();

        int c = check();
        if (c >= K) {
            cout << step << "\n";
            return 0;
        }
        step++;
    }

    return 0;
}