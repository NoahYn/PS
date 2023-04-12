#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	int mul;
	int result[10] = { 0, };
	cin >> a >> b >> c;

	mul = a * b * c;
	while (mul != 0) {
		result[(mul % 10)]++;
		mul /= 10;
	}

	for (int i = 0; i < 10; i++) {
		cout << result[i] << "\n";
	}

	return 0;
}