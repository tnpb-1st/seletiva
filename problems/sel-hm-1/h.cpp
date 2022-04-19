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

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, d, q;
    cin>>n>>q;
    assert(n <= 100000 && n >= 1 && q>=1 && q<= 100);
    vector<int> v(n+1);
    for (int i = 0; i < n; i++) {
        cin>>v[i];
        assert(v[i] >= 0 && v[i] < 1000000);
    }
    while(q--) {
        int ans = 0;
        deque<int> deq;
        cin>>d;
        assert(d >= 1 && d <= n);
        for(int i =0; i < d; i++) {
            if(deq.empty()) {
                deq.push_front(i);
                continue;
            }
            while (1) {
                if (deq.empty()) {
                    deq.push_front(i);
                    break;
                }
                if (v[deq.front()] < v[i]) {
                    deq.pop_front();
                }
                else {
                    deq.push_front(i);
                    break;
                }
            }
        }
        ans = v[deq.back()];
        for(int i = d; i < n; i++) {
            while (!deq.empty() && deq.back() <= i-d) {
                deq.pop_back();
            }
            while (1) {
                if (deq.empty()) {
                    deq.push_front(i);
                    break;
                }
                if (v[deq.front()] < v[i]) {
                    deq.pop_front();
                }
                else {
                    deq.push_front(i);
                    break;
                }
            }
            ans = min(ans, v[deq.back()]);
        }
        cout<<ans<<endl;
    }
    return 0;
}