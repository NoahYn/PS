#include <iostream>

using namespace std;

int main() {
    int num[9];
    int sum = 0;
    int temp;
    int diff;
    for (int i = 0; i < 9; i++) {
        cin >> num[i];
        sum += num[i];
    }
    diff = sum - 100;
    for (int i = 0; i < 8; i++) {
        for (int k = i + 1; k < 9; k++) {
            if (num[i] + num[k] == diff) {
                num[i] = 0;
                num[k] = 0;
                diff = -1;
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int k = 0; k < 8; k++) {
            if (num[k] > num[k + 1]) {
                temp = num[k];
                num[k] = num[k + 1];
                num[k + 1] = temp;
            }
        }
    }
    cout << endl;

    for (int i = 2; i < 9; i++)
        cout << num[i] << endl;
    return 0;
}