#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

// g++ prefix_sum.cpp -o a && time ./a < input.txt > output.txt

void BF()
{
	int N;
	cin>>N;
	int arr[N];
	for(int i=0;i<N;i++)
		cin>>arr[i];

	int Q;
	cin>>Q;
	while(Q--)
	{
		int l,r;
		cin>>l>>r;

		int res = 0;
		for(int a = l; a <= r; a++)
			res+=arr[a];
		cout<<res<<endl;
	}
}

void ps_1()
{
	int N;
	cin>>N;
	int arr[N];int pref[N];
	for(int i=0;i<N;i++)
	{
		cin>>arr[i];
		if(i == 0)pref[0] = arr[0];
		else
			pref[i] = pref[i-1] + arr[i];
	}

	int Q;
	cin>>Q;
	while(Q--)
	{
		int l,r;
		cin>>l>>r;

		int res = pref[r];
		if(l - 1 >= 0)
		{
			res -= pref[l-1];
		}
		cout<<res<<endl;
	}
}

void ps_2
{
	int N, l ,r, Q;
	cin>>N;
	int arr[N], pref[N], prefi[N];
	cin>>arr[0];
	pref[0] = arr[0] = prefi[0];
	for(int i=1; i< N; i++)
	{
		cin>>arr[i];
		pref[i] = pref[i - 1] + arr[i];
		prefi[i] = prefi[i-1] + (arr[i] * i);
	}

	cin>>Q;
	while(Q--)
	{
		cin>>l>>r;
		int t1 = prefi[r], t2 = pref[r];
		if(l >= 0)
		{
			t1 -= prefi[l - 1];
			t2 -= pref[l - 1];
		}
		cout<<t1-t2<<endl;
	}
}

void solve()
{

}

int main()
{
	solve();
	// return 0;
}
