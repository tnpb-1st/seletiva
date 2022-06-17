#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

template<class T>
vector<vector<T>> BuildAdjMtx(T V)
{
	vector<vector<T>> M(V);
	for(int i = 0; i < V; i++)
	{
		for(int j = 0; j < V
			; j++)
		{
			M[i].push_back(0);
		}
	}
	return M;
}

template<class T>
void addUnE(vector<vector<T>> &M, T v, T u)
{
	M[u - 1][v - 1] = 1;
	M[v - 1][u - 1] = 1;
}

int main()
{
	vector<vector<int>> V = BuildAdjMtx(8);
	for(auto &line: V)
	{
		for(auto &ele:line)
		{
			cout << ele << ' ';
		}
		cout<<endl;
	}
	return 0;
}