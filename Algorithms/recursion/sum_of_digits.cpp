#include <bits/stdc++.h>
using namespace std;

int sumDigits(int n) {
    if(n % 10 == n) return n;
    return (n % 10) + sumDigits(n/10);
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
    // freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	return 0;
}
