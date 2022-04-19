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

void solve()
{
    int t;
    cin >> t;
    deque<int> dq;
    int front = 1, back = 0;
    while(t--)
    {
        string s;
        int N;
        cin >> s;
        if(s == "toFront")
        {
            cin >> N;
            if(front)
                dq.push_front(N);
            else
                dq.pb(N);
        }else if(s == "push_back")
        {
            cin >> N;
            if(!back)
                dq.pb(N);
            else
                dq.push_front(N);
        }else if(s!="reverse" && dq.empty())
        {
            cout<<"No job for Ada?"<<endl;
        }else if(s == "back")
        {
            if(!back)
            {
                cout << dq.back()<<endl;
                dq.pop_back();
            }
            else
            {
                cout << dq.front()<<endl;
                dq.pop_front();
            }
        }else if(s == "front")
        {
            if(!front)
            {
                cout << dq.back()<<endl;
                dq.pop_back();
            }
            else
            {
                cout << dq.front()<<endl;
                dq.pop_front();
            }
        }else
        {
            front = !front;
            back = !back;
        }
    }
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