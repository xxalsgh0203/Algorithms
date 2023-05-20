int solution(vector<int> &A) {
    // Implement your solution here
    int cnt = 1;
    int result = 0;

    if (A[0] >= 0 && A[1] <= 0)
        cnt = 2;

    if (A[0] <= 0 && A[1] >= 0)
        cnt = 2;

    for (int i = 2; i < A.size(); i++) {
        if (A[i - 1] == 0) {
            if (A[i - 2] >= 0 && A[i] >= 0) {
                cnt++;
            } else if (A[i - 2] <= 0 && A[i] <= 0) {
                cnt++;
            } else {
                result = max(result, cnt);
                cnt = 1;
            }
        } else {
            if (A[i - 1] > 0 && A[i] < 0) {
                cnt++;

            } else if (A[i - 1] < 0 && A[i] > 0) {
                cnt++;

            }

            else if (A[i - 1] < 0 && A[i] < 0) {
                result = max(result, cnt);
                cnt = 1;
            }

            else if (A[i - 1] > 0 && A[i] > 0) {
                result = max(result, cnt);
                cnt = 1;
            }

            else if (A[i] == 0) {
                cnt++;
            }
        }
    }

    result = max(result, cnt);
    return result;
}