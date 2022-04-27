#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define all(x) x.begin(),x.end()
#define pq priority_queue
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<bool> vbool;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
const int inf = 1e9;
const ll infl = 1e18;

const int ms = 2, sigma = 26;
/*
ms é a soma dos tamanhos das strings
sigma é o tamanho do alfabeto
int trie[ms][sigma], terminal[ms], z;
// z é a próxima label disponível para inserir


Principais aplicações de Trie:
1. Auto Complete
2. Spell Checkers
3. Longest Prefix Matching
String Search in O(L) time, L is size of string to be searched
*/

const int SIZE = 26;

struct node {
    int count = 0;
    bool end_of_word = false;
    node* ar[SIZE];
    node()
    {
        for(int i = 0; i < SIZE; i++)
            ar[i] = nullptr;
    }
    
};

class Trie {
node* root;
public:
    
    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        node* temp_root = root;
        for(int i =0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if(temp_root->ar[index] == nullptr) {
                temp_root->ar[index] = new node();
            }
            temp_root = temp_root->ar[index];
        }
        
        temp_root->end_of_word = true;
    }
    
    bool search(string word) {
        node* temp_root = root;
        for(int i =0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if(temp_root->ar[index] == nullptr) {
                return false;
            }
            temp_root = temp_root->ar[index];
        }
        
        return temp_root->end_of_word;
    }
    
    bool startsWith(string prefix) {
        node* temp_root = root;
        for(int i =0; i < prefix.size(); i++) {
            int index = prefix[i] - 'a';
            if(temp_root->ar[index] == nullptr) {
                return false;
            }
            temp_root = temp_root->ar[index];
        }
        // se não puder ser a palavra completa:
        // return !temp_root->end_of_Word
        return true;
    }
};
