#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://www.geeksforgeeks.org/dsa/longest-increasing-subsequence-dp-3/
// Modified
ll lengthOfLIS(vector<pair<ll, ll>>& arr) {

	ll n = arr.size();
	vector<ll> ans;

	// Initialize the answer vector with the
	// first element of arr
	ans.push_back(arr[0].second);

	for (ll i = 1; i < n; i++) {
		if (arr[i].second >= ans.back()) {

			// If the current number is greater
			// than the last element of the answer
			// vector, it means we have found a
			// longer increasing subsequence.
			// Hence, we append the current number
			// to the answer vector.
			ans.push_back(arr[i].second);
		}
		else {

			// If the current number is not
			// greater than the last element of
			// the answer vector, we perform
			// a binary search to find the smallest
			// element in the answer vector that
			// is greater than or equal to the
			// current number.

			// The lower_bound function returns
			// an iterator pointing to the first
			// element that is not less than
			// the current number.
			ll low = upper_bound(ans.begin(), ans.end(),
								  arr[i].second)
					  - ans.begin();

			// We update the element at the
			// found position with the current number.
			// By doing this, we are maintaining
			// a sorted order in the answer vector.
			ans[low] = arr[i].second;
		}
	}

	// The length of the answer vector
	// represents the length of the
	// longest increasing subsequence.
	return ans.size();
}

int main () {
	cin.tie(0)->sync_with_stdio(0);

	ll n;

	cin >> n;
	vector<pair<ll, ll>> vec(n);
	pair<ll, ll> p;
	for (ll i = 0; i < n; i++) {
		cin >> p.first >> p.second;
		vec[i] = p;
	}

	sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
		if (get<0>(a) != get<0>(b)) {
			return get<0>(a) < get<0>(b); // Sort by first value
		}
		return get<1>(a) < get<1>(b);     // Second value as a tiebraker tiebreaker tie nao sei
	});

	cout << lengthOfLIS(vec);
}
