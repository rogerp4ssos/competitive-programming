// g++ -std=c++17 -O2 -Wall c.cpp
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;

#define all(v) v.begin(), v.end()
#define INF INT_MAX
#define MAX_N 112345
#define MOD ((int)1e9+7)
#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];

    // represents end of a word and its magic power
    ll end_of_word;
}TrieNode;

// returns new trie node
TrieNode* getNode(void) {
    TrieNode* new_node = new TrieNode;

    new_node->end_of_word = 0;

    for (int i=0; i<ALPHABET_SIZE; ++i)
        new_node->children[i] = NULL;

    return new_node;
}

void insert(TrieNode* root, string key, ll power) {
    TrieNode* crawl_node = root;

    for (int i=0; i<(int)key.size(); ++i) {
        int index = key[i]-'a';
        if (!crawl_node->children[index])
            crawl_node->children[index] = getNode();

        crawl_node = crawl_node->children[index];
    }

    // mark last node
    crawl_node->end_of_word = power;
}

void dfs_trie(TrieNode* node, ll path_power, ll* ans) {

    bool leaf = true; 
    for (int i=0; i<ALPHABET_SIZE; ++i) {
        if (node->children[i] != NULL) {
            ll new_power = path_power + node->children[i]->end_of_word;
            dfs_trie(node->children[i], new_power, ans);
            leaf = false;
        }
    }

    if (leaf)
        *ans = max(*ans, path_power);
}

void solve() {
    int n;
    cin >> n;

    TrieNode* root = getNode();

    ll p;
    string w;
    while (n--) {
        cin >> w >> p;

        insert(root, w, p);
    }

    ll ans = 0;
    dfs_trie(root, 0, &ans);

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}