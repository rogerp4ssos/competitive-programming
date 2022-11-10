// g++ -std=c++17 -O2 -Wall josephus_problem_II.cpp
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


typedef struct skipListNode {
    int val;
    int top_lvl;

    int* jump_sz;
    skipListNode** next;
}Node;


int n, k, MAX_LVL;


int find_lvl(int val) {
    for (int lvl=MAX_LVL; lvl>=0; --lvl)
        if ( !(val&((1<<lvl)-1)) ) // val%(1<<lvl) == 0
            return lvl;

    return 0;
}

Node* create_node(int val, int top_lvl) {
    Node* new_node = new Node;

    new_node->val = val;
    new_node->top_lvl = top_lvl;    
    new_node->jump_sz = new int[MAX_LVL+1];
    new_node->next = new Node*[MAX_LVL+1];

    for (int lvl=0; lvl<=top_lvl; ++lvl) { // circular
        new_node->jump_sz[lvl] = 0;
        new_node->next[lvl] = new_node;
    }

    return new_node;
}

void push_back(int val, Node* header) {
    Node* curr = header;

    Node** to_update = new Node*[MAX_LVL+1];

    // marking the nodes to be possibly updated
    for (int lvl=MAX_LVL; lvl >= 0; --lvl) {
        while (curr->next[lvl] != header) // end of circular list
            curr = curr->next[lvl];

        to_update[lvl] = curr;
    }

    int new_lvl = find_lvl(val);
    Node* new_node = create_node(val, new_lvl);

    for (int lvl=0; lvl<=new_lvl; ++lvl) {
        new_node->next[lvl] = to_update[lvl]->next[lvl];
        to_update[lvl]->next[lvl] = new_node;

        new_node->jump_sz[lvl] = 1+(n-1-val);
        to_update[lvl]->jump_sz[lvl] = 1<<lvl;
    }
}

Node* advance(Node* curr, int steps) {
    while (steps) {
        for (int lvl=curr->top_lvl; lvl>=0; --lvl) {
            if (steps >= curr->jump_sz[lvl]) {
                steps-=curr->jump_sz[lvl];
                curr = curr->next[lvl];
                break;
            }
        }
    }

    return curr;
}

Node* remove(Node** header, Node* to_delete) {
    if (to_delete == *header) { // change header if it will be removed
        Node* new_header = (*header)->next[0];

        // adds the connections that the new header does not have
        for (int lvl=new_header->top_lvl+1; lvl<=MAX_LVL; ++lvl) {
            new_header->next[lvl] = (*header)->next[lvl];
            new_header->jump_sz[lvl] = (*header)->jump_sz[lvl]-1;
        }
        // connects the old header fully to the new one
        for (int lvl=0; lvl<=MAX_LVL; ++lvl) {
            (*header)->next[lvl] = new_header;
            (*header)->jump_sz[lvl] = 1;
        }

        new_header->top_lvl = MAX_LVL;
        *header = new_header;
    }

    Node** to_update = new Node*[MAX_LVL+1];

    Node* curr = (*header);
    for (int lvl=MAX_LVL; lvl>=0; --lvl) {
        while ( curr->next[lvl] != *header and curr->next[lvl] != to_delete and
                !(curr->val < to_delete->val and curr->next[lvl]->val >= to_delete->val) ) {
            curr = curr->next[lvl];
        }

        --curr->jump_sz[lvl]; // discounts the node to be deleted from the next jump
        to_update[lvl] = curr;
    }
    --n;

    // updates the nodes that connect the node to be removed
    for (int lvl=0; lvl<=to_delete->top_lvl; ++lvl) {
        to_update[lvl]->jump_sz[lvl] += (to_delete->jump_sz[lvl]);
        to_update[lvl]->jump_sz[lvl]%=n;

        to_update[lvl]->next[lvl] = to_delete->next[lvl];
    }

    // deletes levels containing only one node
    while (MAX_LVL>0 and (*header)->jump_sz[MAX_LVL] == 0) {
        --MAX_LVL;
        --(*header)->top_lvl;
    }

    curr = to_delete->next[0];

    delete to_delete->next;
    delete to_delete->jump_sz;
    delete to_delete;

    return curr; // returns the next value
}

void solve() {
    cin >> n >> k;

    if (n == 1 or k == 0) {
        for (int i=1; i<=n; ++i) 
            cout << i << ' ';
        cout << '\n';
        return;
    }

    MAX_LVL = int(ceil(log2(n)))-1;
    Node* header = create_node(0, MAX_LVL);

    for (int i=1; i<n; ++i)
        push_back(i, header);

    Node *curr = header;
    while (curr->next[0] != curr) {
        curr = advance(curr, k%n);
        
        cout << curr->val+1 << ' ';

        curr = remove(&header, curr);
    }
    cout << curr->val+1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();

    return 0;
}