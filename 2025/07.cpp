#include <bits/stdc++.h>

using namespace std;

void printSpace(vector<string> &space) {
	for (auto &line : space) cout << line << endl;
}

int part1(vector<string> &space) {
	int length = (int) space[0].size();
	int lines = (int) space.size();
	int count{0};
	vector<int> beam(length, 0);
	for (int i = 0; i < length; i++) {
		if (space[0][i] == 'S') {
			space[1][i] = '|';
			break;
		}
	}
	printSpace(space);
	for (int i = 2; i < lines; i+= 2) {
		for (int j = 0; j < length; j++) {
			if (space[i][j] == '^') {
				if (space[i-1][j] == '|') {
					count++;
					space[i][j-1] = '|';
					space[i][j+1] = '|';
					space[i+1][j-1] = '|';
					space[i+1][j+1] = '|';
				}
			}
			else if (space[i-1][j] == '|') {
				space[i][j] = '|';
				space[i+1][j] = '|';
			}
		}
		printSpace(space);
	}
	return count;
}

int main () {
	string input;
	vector<string> space;
	while (1) {
		cin >> input;
		if (!input.compare("end")) break;
		if (!input.compare("input")) {
			string line;
			while(1) {
				cin >> line;
				if (!line.compare("done")) break;
				space.push_back(line);
			}
			cout << "recieved all inputs\n";
		}
		if (!input.compare("solve")) {
			cout << part1(space) << endl;
		}
	}
}
