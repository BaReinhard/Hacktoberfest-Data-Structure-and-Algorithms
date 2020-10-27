// Vertical Order Traversal of a Binary Tree

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node* createNode(int data) {
    Node *newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode -> data = data;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}

Node* InsertNode(Node *root, int data) {
    if (root == NULL) {
        root = createNode(data);
        return root;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();

        if (temp -> left != NULL)
            q.push(temp -> left);
        else {
            temp -> left = createNode(data);
            return root;
        }

        if (temp -> right != NULL)
            q.push(temp -> right);
        else {
            temp -> right = createNode(data);
            return root;
        }
    }
}

void TraverseVerticalOrder(Node *root) {

    if (!root) {
        cout << "Tree is empty !\n";
        return;
    }

    map<int, vector<int> > hm;
    int column = 0;

    queue<pair<Node*, int> > q;
    q.push(make_pair(root, column));

    while (!q.empty()) {

        pair<Node*, int> temp = q.front();
        q.pop();

        Node* currNode = temp.first;
        column = temp.second;

        hm[column].emplace_back(currNode -> data);

        if (currNode -> left)
            q.push(make_pair(currNode -> left, column - 1));
        if (currNode -> right)
            q.push(make_pair(currNode -> right, column + 1));
    }

    map<int, vector<int> > :: iterator it;
    for (it = hm.begin(); it != hm.end(); ++it) {
        for (int i = 0; i < it->second.size(); ++i)
            cout << it->second[i] << ' ';
        cout << '\n';
    }
}

int main()
{
    Node *root = NULL;

    root = InsertNode(root, 1);
    root = InsertNode(root, 2);
    root = InsertNode(root, 3);
    root = InsertNode(root, 4);
    root = InsertNode(root, 5);
    root = InsertNode(root, 6);
    root = InsertNode(root, 7);

    cout << "Vertical Order Traversal : \n";
    TraverseVerticalOrder(root);
    cout << endl;

    return 0;
}