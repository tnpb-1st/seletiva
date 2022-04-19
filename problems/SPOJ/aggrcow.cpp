#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define pq priority_queue
#define inf 0xfffffff
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<bool> vbool;
typedef pair<int,int> pii;
vector<ll> A;

struct Node {
	ll left, right, dist;
	Node(ll l, ll r) {
		left = l, right = r;
	}
	void calcDiff(ll* A) {
		dist = abs(A[left] - A[right]);
	}
};
struct mycomparison
{
	bool operator() (Node &a, Node &b) {
			return a.dist < b.dist;
	}
};


int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int t, N, C;
	cin >> t;
	while(t--) {
		cin >> N >> C;
		ll A[N];
		for(int i = 0; i < N; i++) {
			cin >> A[i];
		}
		sort(A, A+N);
		pq<Node, vector<Node>, mycomparison> mypq;
		Node tmp = Node(0, N-1);
		C-=2;
		tmp.calcDiff(A);
		mypq.emplace(tmp);
		ll ans = tmp.dist;
		while(C > 0) {
			tmp = mypq.top();mypq.pop();
			ll mid = tmp.left + (tmp.right - tmp.left)/2;
			Node op1(tmp.left, mid),op2(mid, tmp.right);
			op1.calcDiff(A);op2.calcDiff(A);
			ans = min(ans, min(op1.dist,op2.dist));
			mypq.emplace(op1);mypq.emplace(op2);
			C--;
		}
		cout<<ans<<endl;
	}

	return 0;
}