#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  int A,B; cin >> A >> B;
  string s; cin >> s;
  bool valid = true;
  for(int i = 0; i < A; i++) if(s[i] < '0' || s[i] > '9') valid = false;
  if(s[A] != '-') valid = false;
  for(int i = A+1; i < A+B; i++) if(s[i] < '0' || s[i] > '9') valid = false;
  if(valid) cout << "Yes";
  else cout << "No";
  
  return 0;
}