#include <bits/stdc++.h>

using namespace std;

int main () {
	string input;
	int dial{50};
	int pass{0};
	// part 1
	while (1) {
		cin >> input;  
		if (input.compare("end") == 0) {
			cout << pass << "\n";
			break;
		}
		int value = stoi(input.substr(1, input.size() - 1));
		cout << "value: " << value << "\n";
		if (input[0] == 'L') {
			dial -= value;
			while (dial < 0) dial += 100;
			cout << "Test L: dial: " << dial << " pass: " << pass << "\n";
		} else if (input[0] == 'R') {
			dial += value;
			while (dial >= 100) dial -= 100;
			cout << "Test R: dial: " << dial << " pass: " << pass << "\n";
		}
		if (dial == 0) pass++;
	}
	// part 2
	dial = 50;
	pass = 0;
	while (1) {
		cin >> input;  
		if (input.compare("end") == 0) {
			cout << pass << "\n";
			break;
		}
		int value = stoi(input.substr(1, input.size() - 1));
		cout << "value: " << value << "\n";
		if (input[0] == 'L') {
			while (value--) {
				dial -= 1;
				if (dial < 0) dial += 100;
				if (dial == 0) pass++;
			}
			cout << "Test L: dial: " << dial << " pass: " << pass << "\n";
		} else if (input[0] == 'R') {
			
			while (value--) {
				dial += 1;
				if (dial > 99) dial -= 100;
				if (dial == 0) pass++;
			}
			cout << "Test R: dial: " << dial << " pass: " << pass << "\n";
		}
	}
}
