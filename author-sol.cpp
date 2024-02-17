#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void test_case(int& tc) {
	int n;
	cin >> n;
	ll a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	map<ll, ll> freq;
	ll max_freq = 0, cur = 0, ans = 0;
	bool found_wildcard = false;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			if (found_wildcard) {
				ans += max_freq;
			} else {
				ans += freq[0];
			}
			found_wildcard = true;
			max_freq = 0;
			freq.clear();
		}
		cur += a[i];
		max_freq = max(max_freq, ++freq[cur]);
	}
	if (found_wildcard) {
		ans += max_freq;
	} else {
		ans += freq[0];
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		test_case(tc);
	}
}
