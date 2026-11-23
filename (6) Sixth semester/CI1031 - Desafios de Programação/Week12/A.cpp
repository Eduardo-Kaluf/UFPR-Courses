#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main () {
	cin.tie(0)->sync_with_stdio(0);

	string s;

	cin >> s;

	int n = s.size();
	vector v(n, 0);
	for (int i = 1; i < n; ++i) {
		int k = v[i-1];

		while (k > 0 && s[i] != s[k])
			k = v[k-1];

		if (s[i] == s[k])
			k++;

		v[i] = k;
	}

	int i = n - 1;
	vector<int> ans;
	while (v[i] != 0) {
		ans.push_back(v[i]);
		i = v[i] - 1;
	}

	reverse(ans.begin(), ans.end());

	for (int j = 0; j < (int) ans.size(); ++j)
		cout << ans[j] << " ";
}

