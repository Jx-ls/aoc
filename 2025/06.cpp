#include <bits/stdc++.h> 

using namespace std;

void print (vector<vector<int>> &numbers) {
	for (auto &line : numbers) {
		for (auto &num : line) {
			cout << num << " ";
		}
		cout << endl;
	}
}

void transpose(vector<vector<int>> &numbers, vector<vector<int>> &numbers_t) {
	for (int i = 0; i < (int) numbers[0].size(); i++) {
		vector<int> temp;
		for (int j = 0; j < (int) numbers.size(); j++) {
			temp.push_back(numbers[j][i]);
		}
		numbers_t.push_back(temp);
	}
}

void weird(vector<vector<int>> &numbers_t, vector<vector<int>> &numbers_w) {
	vector<vector<vector<char>>> numbers_c;
	for (auto &line : numbers_t) {
		vector<vector<char>> temp;
		for (auto &num : line) {
			string s = to_string(num);
			vector<char> temp_num(s.begin(), s.end());
			while (temp_num.size() < 3) {
    			temp_num.push_back('0');
			}
			temp.push_back(temp_num);
		}
		numbers_c.push_back(temp);
	}
	for (auto &line : numbers_c) {
		vector<int> temp_line;
		for (int i = 0; i < 3; i++) {
			vector<char> temp;
			for (auto &num : line) {
				temp.push_back(num[i]);
			}
			string s(temp.begin(), temp.end());
			temp_line.push_back(stoi(s));
		}
		numbers_w.push_back(temp_line);
	}
	print(numbers_w);
}

long long part1(vector<vector<int>> &numbers, vector<char> &operators) {
	vector<vector<int>> numbers_t;
	transpose(numbers, numbers_t);
	long long result{0}, total{0};
	for (int i = 0; i < (int) operators.size(); i++) {
		if (operators[i] == '+') for (const auto &num : numbers_t[i]) result += num;
		if (operators[i] == '*') {
			result = 1;
			for (const auto &num : numbers_t[i]) {
				if (num == 0) continue;
				result *= num;
			}
		}
		total += result;
		result = 0;
	}
	return total;
}


long long part2(vector<vector<int>> &numbers, vector<char> &operators) {
	vector<vector<int>> numbers_t;
	transpose(numbers, numbers_t);
	vector<vector<int>> numbers_w;
	weird(numbers_t, numbers_w);
	long long result{0}, total{0};
	for (int i = 0; i < (int) operators.size(); i++) {
		if (operators[i] == '+') for (const auto &num : numbers_w[i]) result += num;
		if (operators[i] == '*') {
			result = 1;
			for (const auto &num : numbers_w[i]) result *= num;
		}
		total += result;
		result = 0;
	}
	return total;
}

int main () {
	string input;
	vector<vector<int>> numbers;
	vector<char> operators;
	while (1) {
		cin >> input;
		if (!input.compare("end")) break;
		if (!input.compare("print")) {
			print(numbers);
		}
		if (!input.compare("input")) {
			cin.ignore();
			while (1) {
				string line;
				vector<int> tempNumbers;
				getline(cin, line);
				stringstream nums(line);
				if (!line.compare("done")) break;
				int temp;
				while (nums >> temp) tempNumbers.push_back(temp);
				numbers.push_back(tempNumbers);
			}
			string line;
			getline(cin, line);
			stringstream ops(line);
			char temp;
			while (ops >> temp) operators.push_back(temp);
			cout << "recieved all the inputs\n";
		}
		if (!input.compare("solve")) {
			cout << part1(numbers, operators) << endl << part2(numbers, operators) << endl;
		}
	}
}
