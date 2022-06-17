#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k;
	cin >> n;
	int A[n];

	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	int P[n] = {};
	P[0] = A[0];

	for(int i = 1; i < n; i++)
	{
		P[i] = P[i - 1] + A[i];
	}

	cin >> k;

	int mx, curr;
	curr = mx = P[k - 1];

	for(int i = k; i < n; i++)
	{
		curr = P[i] - P[i - k];
		mx = max(curr, mx);
	}


	cout << mx << "\n";
	
	return 0;
}