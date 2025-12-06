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


long long part2(vector<string> &input) {
	int n = (int) input.size() - 1;
	int length = (int) input[0].size();
	int flag = 0; // implies add
	long long result{0}, total{0};
	for (int i = 0; i < length; i++) {
		if (!(input[n][i] == ' ')) {
			cout << result << endl;
			total += result;
			if (input[n][i] == '+') {
				flag = 0;
				result = 0;
			}
			if (input[n][i] == '*') {
				flag = 1;
				result = 1;
			}
		}
		vector<char> x;
		for (int j = 0; j < n; j++) {
			x.push_back(input[j][i]);
		}
		string s(x.begin(), x.end());
		s.erase(remove(s.begin(), s.end(), ' '), s.end());
		int num = 0;
		if (!s.empty()) num = stoi(s);
		cout << num << " ";
		if (flag == 0) result += num;
		else {
			if (num != 0) result *= num;
		}
	}
	cout << result << endl;
	total += result;
	return total;
} 


int main () {
	string input;
	vector<vector<int>> numbers;
	vector<string> input_2;
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
		if (!input.compare("input2")) {
			cin.ignore();
			while (1) {
				string line;
				getline(cin, line);
				if (!line.compare("done")) break;
				input_2.push_back(line);
			}
			cout << "recieved all inputs 2";
			cout << input_2[1].size() << endl;;
		}
		if (!input.compare("solve")) {
			cout << part2(input_2) << endl;
		}
	}
}
