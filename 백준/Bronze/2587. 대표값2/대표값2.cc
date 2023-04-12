#include <iostream>
using namespace std;

int main() {
    const int SIZE = 5;
    int num[SIZE];
    int sum = 0;
    int temp;
    for (int i=0; i<SIZE; i++) {
        cin >> num[i];
        sum += num[i];
    } 
    for (int k=0; k<SIZE; k++) {
    for (int i=0; i<SIZE - 1; i++) {
        if (num[i] > num[i+1]) {
            temp = num[i];
            num[i] = num[i+1];
            num[i+1] = temp;
        }
    }
    }
    cout << sum/SIZE << endl;
    cout << num[SIZE/2] << endl;
    return 0;
}