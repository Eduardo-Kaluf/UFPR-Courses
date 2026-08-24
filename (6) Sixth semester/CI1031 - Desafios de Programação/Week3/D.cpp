#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll n, a, b, sum1, sum2, sum3, mmc;

	cin >> n >> a >> b;

	mmc = lcm(a, b);

	sum1 = (a * (n / a) * (n / a + 1)) / 2;
	sum2 = (b * (n / b) * (n / b + 1)) / 2;
	sum3 = (mmc * (n / mmc) * (n / mmc + 1)) / 2;

	cout << (n * (n + 1) / 2) - sum1 - sum2 + sum3;
}

