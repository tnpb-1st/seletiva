#include <bits/stdc++.h>
using namespace std;

/*
Problem: Find leftmost element K in an sorted array using BS
*/

bool foo(int i, int N = 4)
{
	return (i == N);
}

int leftMost(vector<int> &A)
{
	int l = 0, mid, r = A.size();

	while(l < r)
	{
		mid = l + (r - l)/2;
		
		if(foo(A[mid]))
			r = mid;
		else
			l = mid + 1;
	}
}

bool foo2(int i, int N = 25)
{
	return (i * i <= N);
}

int rightMost(vector<int> &A)
{
	int l = 0, mid, r = A.size() - 1;
	int last = 0;
	while (l <= r)
	{
		mid = (l + (r - l)/2);

		if(foo2(A[mid])){
			last = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	return last;
}

int main()
{
	// freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	return 0;
}