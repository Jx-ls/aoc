#include <bits/stdc++.h>

using namespace std;

void printSpace(vector<string> &space) {
	for (auto &line : space) cout << line << endl;
}


int part1(vector<string> &space) {
	int count{0};
	for (int i = 0; i < (int) space[0].size(); i++) {
		if (space[0][i] == 'S') {
			space[1][i] = '|';
			break;
		}
	}
	for (int i = 2; i < (int) space.size(); i+= 2) {
		for (int j = 0; j < (int) space[0].size(); j++) {
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
	}
	return count;
}

long long part2(vector<string> &space) {
	long long count{0};
	vector<long long> nums((int) space[0].size(), 0);
	for (int i = 0; i < (int) space[0].size(); i++) {
		if (space[0][i] == 'S') {
			space[1][i] = '|';
			nums[i] = 1;
			break;
		}
	}
	for (int i = 2; i < (int) space.size(); i+= 2) {
		for (int j = 0; j < (int) space[0].size(); j++) {
			if (space[i][j] == '^') {
				if (nums[j] != 0) { 
					space[i][j-1] = space[i-1][j];
					nums[j-1] += nums[j];
					space[i][j+1] = space[i-1][j];
					nums[j+1] += nums[j];
					space[i+1][j-1] = space[i][j-1];
					space[i+1][j+1] = space[i][j+1];
				}
				nums[j] = 0;
			}
			else if (space[i-1][j] != '.') {
				space[i][j] = space[i-1][j];
				space[i+1][j] = space[i][j];
			}
		}
	}
	for (auto &num : nums) {
		count += num;
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
		vector<string> space2 = space;
		if (!input.compare("solve")) {
			cout << part1(space) << endl << part2(space2) << endl;
		}
	}
}
