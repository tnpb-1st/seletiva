#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void subSetSum(vector<int> &A, int sum, int cur_sum=0,string cur="",int index=0) {
    if(cur_sum != sum && index == A.size() || cur_sum > sum) return;
    else if (cur_sum == sum) {
        if(sum == 0) cout << 0;
        else cout << cur;
    }
    else {
        subSetSum(A, sum, cur_sum, cur, index + 1);
        subSetSum(A, sum, cur_sum + A[index], cur + to_string(A[index]) + ' ', index + 1);
    }
}

void solve() {
    vector<int> Arr = {10, 20, 15};
    subSetSum(Arr, 0);
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
