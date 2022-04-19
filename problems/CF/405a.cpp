#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
// range of int values -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)

void solve()
{
	int N, dif;
	cin >> N;
	vector<int> A(N);
	for(int i=0; i < N; i++)
		cin>>A[i];
	sort(A.begin(),A.end());

	for(int i = 0; i < N; i++)
		cout << A[i] << ' ';
	cout<<endl;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	solve();
	return 0;
}