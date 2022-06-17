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
    while(cin >> t && t)
    {
        queue<int> Q;
        stack<int> S;
        pq<int> PQ;
        bool is_Q,is_S,is_PQ;
        string s_q, s_s, s_pq, correct;
        correct = s_q = s_s = s_pq = "";
        int op, val;
        for(int i = 0; i < t; i++)
        {
            cin >> op >> val;
            if(op == 1)
            {
                Q.push(val);
                S.push(val);
                PQ.push(val);
            }
            else
            {
                correct += val;
                if(!Q.empty())
                {
                    s_q += Q.front();
                    Q.pop();
                }
                if(!PQ.empty())
                {
                    s_pq += PQ.top();
                    PQ.pop();
                }
                if(!S.empty())
                {
                    s_s += S.top();
                    S.pop();
                }
            }
        }
        bool isQ, isS, isPQ;
        isQ = isS = isPQ = false;
        if(correct == s_pq)
            isPQ = true;
        if(correct == s_q) 
            isQ = true;
        if(correct == s_s) 
            isS = true;

        if((isPQ && isQ)||(isPQ && isS)||(isQ && isS))
            cout<<"not sure"<<endl;
        else if(isPQ)
            cout<<"priority queue"<<endl;
        else if(isQ)
            cout<<"queue"<<endl;
        else if(isS)
            cout << "stack"<<endl;
        else
            cout<<"impossible"<<endl;
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