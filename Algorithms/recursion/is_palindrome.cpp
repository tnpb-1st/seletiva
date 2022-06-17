#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &s, int l, int r) {
    if(l >= r) return true;
    return (s[l] == s[r] && isPalindrome(s, l+1,r-1));
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
    // freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	return 0;
}
