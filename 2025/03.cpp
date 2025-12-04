#include <bits/stdc++.h>

using namespace std;

int part1(string input) {	
	int n = input.size();
	vector<pair<int,int>> v;
	for (int i = 0; i < n; i++) v.push_back({input[i] - '0', i});
	sort(v.begin(), v.end(), [](auto &a, auto &b) {
		if (a.first != b.first)
			return a.first > b.first;
		return a.second < b.second;
	});
	int i, j, flag = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == j) continue;
			if (v[i].second < v[j].second) flag = 1;
	 		if (flag == 1) break;
		}
		if (flag == 1) break;
	}
	return (10 * v[i].first + v[j].first);
}

long long part2(string input) {
	int n = input.size();
	int start = 0, end = n - 12, max = 0;
	long long num = 0;
	for (int i = 0; i < 12; i++) {
		max = 0;
		for (int j = start; j <= end; j++) {
			if (input[j] - '0' > max) {
				max = input[j] - '0';
				start = j + 1;
			}
		}
		num = 10 * num + max;
		end++;
	}
	return num;
}

int main () {
	string input;
	long long sum1{0}, sum2{0};
	while (1) {
		cin >> input;
		if (!input.compare("end")) {
			cout << "part 1: "<< sum1 << " part 2: " << sum2 << "\n";
			return 0;
		}
		sum1 += part1(input);
		sum2 += part2(input);
	}
}
