#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int>& A, int &N)
{
	int arr_size = A.size();
	for(int i = 0; i < arr_size; i++) if(A[i] == N) return i;

	return -1;
}

int binarySearch(vector<int>& A, int &N)
{
	int arr_size = A.size();
	int l = 0, mid, r = arr_size - 1;

	while(l <= r)
	{
		mid = l + (r - l)/2;
		if(A[mid] == N) return mid;
		else if(A[mid] < N) l = mid + 1;
		else r = mid - 1;
	}
	return -1;
}

int main()
{
	return 0;
}