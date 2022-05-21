#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void permuteSTR(string &s, int i = 0) {
    if(i == s.size() - 1) {
        cout<< s <<endl;
        return;
    }
    for(int j = i; j < s.size(); j++) {
        swap(s[i],s[j]);
        permuteSTR(s, i + 1);
        swap(s[i],s[j]);
    }
}

void altPermute(string s) {
    sort(s.begin(), s.end());
    cout<<s<<endl;
    while(next_permutation(s.begin(), s.end())) {
        cout << s << endl;
    }
}

void solve() {
    string s = "ABC";
    permuteSTR(s);
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
