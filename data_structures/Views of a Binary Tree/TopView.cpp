//Structure of binary tree

/*struct Node

{

    int data;

    struct Node* left;

    struct Node* right;

};*/

// function should print the topView of the binary tree

void topView(struct Node *root)

{

    queue < Node* > q;

    queue <int> loc;

    set <int> s;

    q.push(root);

    loc.push(0);

    while(!q.empty())

    {

        set <int > :: iterator sit;

        Node *node_n = q.front();

        q.pop();

        int node_val = node_n -> data;

        int location = loc.front();

        loc.pop();

        sit = find(s.begin(), s.end() , location);

        if(sit  == s.end())

        {

            cout<< node_val<<" ";

            s.insert(location);

        }

        if(node_n -> left != NULL)

        {

            q.push(node_n->left);

            loc.push(location - 1);

        }

        if(node_n -> right != NULL)

        {

            q.push(node_n->right);

            loc.push(location + 1);

        }

    }

    

}
