#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void subsetsString(string &s, string cur="", int i = 0) {
    if(i == s.size()) {
        cout<<cur<<endl;
        return;
    }
    subsetsString(s, cur, i+1);
    subsetsString(s, cur + s[i], i+1);
}

void solve() {
    string s = "123ABCDEF";
    subsetsString(s);
}

int main()
{
	time_t start, end;
	time(&start);
	cin.tie(0);
	ios::sync_with_stdio(0);
    solve();
    // freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	time(&end);
	cout << endl << fixed << (double) end-start << setprecision(3)<<endl;
	return 0;
}
