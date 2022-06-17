#include <bits/stdc++.h>
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define pq priority_queue
using namespace std;
typedef long long ll;
// typedef __int128_t bgl;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
// range of int values -2*10^9 <= int <= 2*10^9 (32 bits)
// range of long long values -2 * 10^18 <= ll <= 2 * 10^18 (64 bits)
// g++ -std=c++14 -O2 -Wall test.cpp -o main
int z;
template<class T>
bool check(T i) { return i && 1;}

// Lower Bound => Find first value >= X.
int LB(int x, int l, int r, vi &A) {
    int ans = -1,mid;
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

int itBS(int x, int l, int r, vi &A) {
    int mid;
    while(l <= r) {
        mid = l + (r-l)/2;
        if(A[mid] == x) {
            return mid;
        } else if(A[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

template<class T>
int BS(vector<T> &arr,int l, int r, T x)
{
    if(l <= r)
    {
        int mid = l + (r - l)/2;
        if(arr[mid] == x)
            return mid;
        else if(arr[mid] > x)
            return BS(arr, l, mid - 1, x);
        else
            return BS(arr, mid + 1, r, x);
    }
    return -1;
}

int BS2(vi &arr, int x)
{
    int l = 0, n = arr.size();
    for(int b = n/2; b >= 1; b/=2) {
        while(l+b < n && arr[l+b] <= x) l += b;
    }
    if(arr[l] == x) return l;
    return -1;
}

bool f(int x)
{
    return x & 1;
}

int BSf()
{
    // finding the smallest solution
    int x = -1;
    for(int b = z; b >= 1; b/=2){
        while(!f(x+b)) x+=b;
    }
    if(f(x+1))return x+1;
    return -1;
}

int BSm()
{
    // f(x) < f(x+1), se x < k
    // f(x) >= f(x+1), s x >= k
    // finding the maximum value for which f(x) < f(x+1)
    // in a monotonic funcion
    int x = -1;
    for(int b = z; b>=1; b/=2){
        while(f(x+b) < f(x+b+1)) x+= b;
    }
    if(f(x+1)) return x+1;
    return -1;

}

double BSD(double l, double h, int maxIt)
// essa busca binária tem uma quantidade máxima de iterações devido à imprecisão do double
{
    for(int i = 0; i<maxIt; i++)
    {
        double mid = (l + h)/2.0;
        if(check(mid))
            l = mid;
        else
            h = mid;
    }
    return l;
}

template<class T>
T dnq(int left, int right)
{
    if(left == right)
        return unitarySolution(left);
    
    int mid = (left+right)/2;
    // calcula a solução da parte esquerda e depois da parte direita
    T leftSolution = dnq(left, mid);
    T rightSolution = dnq(mid + 1, right);

    return composeSolutions(leftSolution, rightSolution, left, right);
}

void solve()
{
	
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	// freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);

	solve();
	return 0;
}
