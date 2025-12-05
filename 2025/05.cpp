#include <bits/stdc++.h> 

using namespace std;
using ll = long long;

void printIntervals(vector<pair<ll, ll>> &intervals) {
	for (auto &a : intervals) cout << a.first << "," << a.second << endl;
}

int compareIntervals(const pair<ll, ll> &a, const pair<ll, ll> &b) {
	if (a.second < b.first) return 0;
	else if (a.first < b.first) return 1;
	return 2;
}

ll part1(vector<pair<ll, ll>> &intervals, vector<ll> &ids) {
	ll fresh{0};
	for (const auto &id : ids) {
		for (const auto &interval : intervals) {
			if (id >= interval.first && id <= interval.second) {
				fresh++;
				break;
			}
		}
	}
	return fresh;
}

int main () {
	string input;
	vector<pair<ll, ll>> intervals;
	vector<pair<ll, ll>> mergedIntervals;
	vector<ll> ids;
	while (1) {
		cin >> input;
		if (!input.compare("merge")) {
			int n = intervals.size();
			while (n != 1) {
				pair<ll, ll> a = intervals[n - 2], b = intervals[n - 1];
				int flag = compareIntervals(a, b);
				if (flag) {
					intervals.pop_back();
					intervals.pop_back();
					if (flag == 1) {
						intervals.push_back({a.first, b.second});
					} else if (flag == 2) {
						intervals.push_back(b);
					}
				} else {
					mergedIntervals.push_back(b);
					intervals.pop_back();
				}
				n = intervals.size();
			}
			mergedIntervals.push_back(intervals.back());
			reverse(mergedIntervals.begin(), mergedIntervals.end());
			intervals.pop_back();
		}
		if (!input.compare("print")) {
			printIntervals(intervals);
			cout << "merged:\n";
			printIntervals(mergedIntervals);
		}
		if (!input.compare("input")) {
			while (1) {
				cin >> input;
				if (!input.compare("done")) break;
				ll a, b;
				int dash;
				for (int i = 0; i < (int) input.size(); i++) {
					if (input[i] == '-') dash = i;
				}
				a = stoi(input.substr(0, dash));
				b = stoi(input.substr(dash + 1, input.size() - dash - 1));
				intervals.push_back({a, b});
			}
		}
		sort(intervals.begin(), intervals.end());
		if (!input.compare("ids")) {
			while (1) {
				cin >> input;
				if (!input.compare("done")) break;
				ll x = stoll(input);
				ids.push_back(x);
			}
		}
		if (!input.compare("end")) {
			cout << "fresh ids: " << part1(mergedIntervals, ids) << endl;
			break;
		};
	}
}
