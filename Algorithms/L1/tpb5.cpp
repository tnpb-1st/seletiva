/*
Given N elements, an Array of N elements and integer k. Find the maximum sum
subarray, of size k
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
	return 0;
	int n, k;
	cin >> n;
	int A[n];
	for(int i=0; i < n; i++)
		cin >> A[i];

	cin >> k;
	int cur, mx;
	mx = cur = 0;


	for(int i=0; i < k; i++)
	{
		cur += A[i];
	}

	mx = cur;

	for( int i = 1; i + k - 1 < n; i++)
	{
		cur = cur + A[i + k - 1] - A[i - 1];
		mx = max(cur, mx);
	}

	cout << mx << "\n";
	return 0;

}