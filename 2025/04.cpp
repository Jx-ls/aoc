#include <bits/stdc++.h>

using namespace std;

int kernelSum(vector<vector<int>> grid, int i, int j, int rows, int cols) {
	int i_begin = max(0, i - 1);
	int i_end = min(rows - 1, i + 1);
	int j_begin = max(0, j - 1);
	int j_end = min(cols - 1, j + 1);
	int sum{0};
	for (int i_n = i_begin; i_n <= i_end; i_n++) {
		for (int j_n = j_begin; j_n <= j_end; j_n++) {
			if (i_n == i && j_n == j) continue;
				sum += grid[i_n][j_n];
		}
	}
	return sum;
}

void printGrid(vector<vector<int>> grid) {
	for (auto &row : grid) {
		for (auto &val : row) {
			cout << val;
		}
		cout << "\n";
	}
}

int main () {
	string input;
	long long rolls{0};
	vector<vector<int>> grid;
	int row{0};
	while (1) {
		cin >> input;
		if (!input.compare("solve")) {
			printGrid(grid);
			int rows = grid.size();
			int cols = grid[0].size();
			vector<vector<int>> convolved_grid(rows, vector<int>(cols, 0));
			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					if (grid[i][j] == 0) continue;
					convolved_grid[i][j] = kernelSum(grid, i, j, rows, cols) < 4 ? 1 : 0;
					if (convolved_grid[i][j] == 1) rolls++;
				}
			}
			printGrid(convolved_grid);
		}
		if (!input.compare("end")) {
			cout << "Accessable: " << rolls << "\n";
			return 0;
		}
		grid.push_back(vector<int>{});
		for (auto &item : input) {
			item == '.' ? grid[row].push_back(0) : grid[row].push_back(1);
		}
		row++;
	}
}
