#include <iostream>
using namespace std;

class Node {
public:
    int left;
    int right;
};
class BinTree {
    Node* node;
    int size;
public:
    BinTree(int size) {
        this->size = size;
        node = new Node[size];
    }
    void init() {
        for (int v = 1; v <= size; v++) {
            char P, L, R;
            cin >> P >> L >> R;

            P -= 65;

            if (L == '.') this->node[P].left = -1;
            else this->node[P].left = L - 65;

            if (R == '.') this->node[P].right = -1;
            else this->node[P].right = R - 65;
        }
    }
    void preorder(int x) {
        if (x == -1) return;
        cout << (char)(x + 'A');
        preorder(this->node[x].left);
        preorder(this->node[x].right);
    }
    void inorder(int x) {
        if (x == -1) return;
        inorder(this->node[x].left);
        cout << (char)(x + 'A');
        inorder(this->node[x].right);
    }
    void postorder(int x) {
        if (x == -1) return;
        postorder(this->node[x].left);
        postorder(this->node[x].right);
        cout << (char)(x + 'A');
    }
};

/**************************************************/

int main() {
    int n;
    cin >> n;
    
    BinTree tree(n);

    tree.init();

    tree.preorder(0);
    cout << '\n';
    tree.inorder(0);
    cout << '\n';
    tree.postorder(0);
    cout << '\n';
    return 0;
}