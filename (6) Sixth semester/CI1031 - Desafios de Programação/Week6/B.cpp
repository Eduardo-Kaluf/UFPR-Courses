#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main () {
	cin.tie(0)->sync_with_stdio(0);

	int n, m;

	cin >> n >> m;
	vector<vector<char>> v(n, vector<char>(m));
	vector<vector<int>> vis(n, vector<int>(m, 0));
	vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m, {-1, -1}));

	pair<int, int> st, ed;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			if (v[i][j] == 'A') {
				st = {i, j};
			}
			if (v[i][j] == 'B') {
				ed = {i, j};
			}
		}
	}

	queue<pair<int, int>> q;
	q.push(st);
	vis[st.first][st.second] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == ed.first && y == ed.second) break;

		for (auto [dx, dy, dir] : vector<tuple<int, int, char>>{{1, 0, 'D'}, {-1, 0, 'U'}, {0, 1, 'R'}, {0, -1, 'L'}}) {
			int nx = x + dx, ny = y + dy;
			if (nx >= 0 && ny >= 0 && nx < n && ny < m && (v[nx][ny] == 'B' || v[nx][ny] == '.') && !vis[nx][ny]) {
				q.push({nx, ny});
				par[nx][ny] = {x, y};
				vis[nx][ny] = 1;
			}
		}
	}

	if (!vis[ed.first][ed.second]) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		vector<char> ans;
		int x = ed.first, y = ed.second;

		while (x != st.first || y != st.second) {
			auto [a, b] = par[x][y];
			if (x > a) ans.push_back('D');
			else if (x < a) ans.push_back('U');
			else if (y > b) ans.push_back('R');
			else if (y < b) ans.push_back('L');
			x = a; y = b;
		}
		reverse(ans.begin(), ans.end());
		cout << ans.size() << endl;
		for (auto it : ans) cout << it;
		cout << endl;
	}
}

