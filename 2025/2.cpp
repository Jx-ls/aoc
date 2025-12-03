#include <bits/stdc++.h>

using namespace std;

int isInvalidp1(long long k) {
	regex r("^([0-9]+)\\1$");
	if (regex_match(to_string(k), r)) return 1;
	return 0;
}
int isInvalidp2(long long k) {
	regex r("^([0-9]+)\\1+$");
	if (regex_match(to_string(k), r)) return 1;
	return 0;
}
int main () {
	string input;
	long long firstID, lastID, sum1{0}, sum2{0};
	while (1) {
		cin >> firstID;
		cin.ignore(1, '-');
		cin >> lastID;
		cin.ignore(1, ',');
		cout << "firstID: " << firstID << " lastID: " << lastID << "\n";
		for (long long k = firstID; k <= lastID; k++) {
			if (isInvalidp1(k) == 1) {
				sum1 += k;
				cout << k << " ";
			}
			if (isInvalidp2(k) == 1) {
				sum2 += k;
				cout << k << " ";
			}
		}
		cout << " sum1: " << sum1 << " sum2: " << sum2 << "\n";
	}
}
