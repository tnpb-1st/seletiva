#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
// g++ -std=c++14 main.cpp -o main && time ./main

void dfs(int i, vector<vector<int>> &res, vector<int> &subset, vector<int> &nums)
{
    if(i == nums.size())
    {
        res.push_back(subset);
        return;
    }
    subset.push_back(nums[i]);
    dfs(i+1, res, subset, nums);

    subset.pop_back();
    dfs(i+1, res, subset, nums);
}

vector<vector<int>> allSubsets(vector<int> &nums)
{
    vector<vector<int>> results;
    vector<int> subset;
    dfs(0, results, subset, nums);
    return results;
}

int main()
{
    vector<int> V = {1, 2, 3};
    vector<vector<int>> result = allSubsets(V);
    for(auto &vec: result)
    {
        cout << '{';
        for(int i = 0; i < vec.size(); i++)
        {
            if(i != vec.size() - 1)
                cout << vec[i]<<", ";
            else
                cout << vec[i]<< '}'<<endl;
        }
    }
	return 0;
}
