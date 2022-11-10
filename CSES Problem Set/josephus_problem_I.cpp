// g++ -std=c++17 -O2 -Wall josephus_problem_I.cpp
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll;
typedef tuple<int,int,int> tiii;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define INF INT_MAX
#define MAX_N 112345
#define MOD ((int)1e9+7)

typedef struct listNode{
    int val;
    listNode *next;
} listNode;

listNode* create_node(int v) {
    listNode* new_node = new listNode;

    new_node->val = v;
    new_node->next = new_node;
    return new_node;
}

void push_front(int v, listNode* last) {
    listNode* new_node = create_node(v);

    new_node->next = last->next;
    last->next = new_node;
}

void delete_next(listNode* node, listNode** last) {
    if (node->next == (*last))
        (*last) = node;

    listNode* to_delete = node->next;
    node->next = node->next->next;

    delete to_delete;
}
  
void solve() {
    int n;
    cin >> n;

    listNode* last = create_node(n);

    for (int i=n-1; i>=1; --i)
        push_front(i, last);
    
    listNode *node = last->next;

    while (node->next != node) {
        cout << node->next->val << ' ';
        
        delete_next(node, &last);

        node = node->next;
    }
    cout << node->val << '\n';
    delete node;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}