#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define pq priority_queue
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<bool> vbool;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
const int inf = 1e9;
const ll infl = 1e18;

int BS(int x, vi &A) {
    int l = 0, mid, r = A.size()-1;
    while(l <= r) {
        mid = l + (r-l)/2;
        if(A[mid] == x) return mid;
        else if(A[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

// find first occurrence of an element of value x
int firstInd(int x, vi &A) {
    int l = 0, mid, r = A.size()-1, ans = -1;
    while(l <= r) {
        mid = l + (r-l)/2;
        if(A[mid] >= x) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);

	
	return 0;
}
