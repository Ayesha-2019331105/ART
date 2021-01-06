#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define maxn 199999

struct avl_node
{
    avl_node* left;
    avl_node* right;
    int data;
    int height;///for each node height of that sub-tree.
};
struct avl_node* root;///globally declaring root node.
int node_height(avl_node* p)///code to find the height of each node.
{
    int hl,hr;
    hl = p && p->left ? p->left->height : 0;///height of left sub-tree.
    hr = p && p->right ? p->right->height : 0;///height of right sub-tree.
    return hl>hr ? hl+1 : hr+1;///total height.
}
int BF(avl_node* p)///balance-factor of a node = height of left sub-tree - height of right sub-tree.
{
    int hl,hr;
    hl = p && p->left ? p->left->height : 0;
    hr = p && p->right ? p->right->height : 0;
    return hl-hr;
}
/**
            (p)                             (pl)
          /                                /    \
        /                                 /      \
      (pl)      ll-rotation  ---> (random)        (p)
    /   \                                        /
(random) (plr)                                 (plr)
*/
avl_node* LLRotation(avl_node* p)///clock-wise rotation.
{
    avl_node* pl = p->left;
    avl_node* plr = pl->right;
    pl->right = p;
    p->left = plr;
    p->height = node_height(p);
    pl->height = node_height(pl);
    if(root == p)
        root = pl;
    return pl;
}
/**
            (p)                             (pr)
              \                            /   \
               \                          /     \
               (pr)  rr-rotation---->  (p)      (random)
              /  \                      \
             /    \                      \
         (prl)   (random)               (prl)
*/
avl_node* RRRotation(avl_node* p)///anti-clockwise rotation.
{
    avl_node* pr = p->right;
    avl_node* prl = pr->left;
    pr->left = p;
    p->right = prl;
    p->height = node_height(p);
    pr->height = node_height(pr);
    if(root == p)
        root = pr;
    return pr;
}
/**
          (p)                              (plr)
         /                                 /    \
        /                                 /      \
      (pl)      lr-rotation  --->     (pl)        (p)
        \                                \        /
        (plr)                             \      /
         / \                             (left) (right)
        /   \
    (left) (right)
*/
avl_node* LRRotation(avl_node* p)
{
    avl_node* pl = p->left;
    avl_node* plr = pl->right;
    pl->right = plr->left;
    p->left = plr->right;
    plr->left = pl;
    plr->right = p;
    pl->height = node_height(pl);
    p->height = node_height(p);
    plr->height = node_height(plr);
    if(root==p)
        root = plr;
    return plr;
}
/**
            (p)                            (prl)
              \                            /   \
               \                          /     \
               (pr)  rl-rotation---->   (p)     (pr)
              /                           \      /
             /                             \    /
         (prl)                          (left) (right)
         /  \
        /    \
    (left)  (right)
*/
avl_node* RLRotation(avl_node* p)
{
    avl_node* pr = p->right;
    avl_node* prl = pr->left;
    pr->left = prl->right;
    p->right = prl->left;
    prl->right = pr;
    prl->left = p;
    pr->height = node_height(pr);
    p->height = node_height(p);
    prl->height = node_height(prl);
    if(root==p)
        root = prl;
    return prl;
}
avl_node* avl_insert(avl_node* p,int k)
{
    avl_node* t = NULL;
    if(p == NULL)
    {
        t = new avl_node();
        t->data = k;
        t->height = 1;
        t->left = t->right = NULL;
        return t;
    }
    ///the following code is same as searching.
    if(k < p->data)
    {
        p->left = avl_insert(p->left,k);
    }
    else if(k > p->data)
    {
        p->right = avl_insert(p->right,k);
    }
    ///end of searching for the position of given node,key.
    p->height = node_height(p);///hight.
    /// the code below actually for balancing the height of the tree after inserting given key.
    if(BF(p)==2 && BF(p->left)==1)
        return LLRotation(p);
    else if(BF(p)==2 && BF(p->left)==-1)
        return LRRotation(p);
    else if(BF(p)==-2 && BF(p->right)==-1)
        return RRRotation(p);
    else if(BF(p)==-2 && BF(p->right)==1)
        return RLRotation(p);
    ///now return the specific node after balancing.
    return p;
}
avl_node* update(avl_node* p)///this function updates the tree after certain deletion. their operations are same as balancing after inserting operation.
{
    if(BF(p)==2 && BF(p->left)==1)
        return LLRotation(p);
    else if(BF(p)==2 && BF(p->left)==-1)
        return LRRotation(p);
    else if(BF(p)==2 && BF(p->left)==0)
        return LLRotation(p);
    else if(BF(p)==-2 && BF(p->right)==-1)
        return RRRotation(p);
    else if(BF(p)==-2 && BF(p->right)==1)
        return RLRotation(p);
    else if(BF(p)==-2 && BF(p->right)==0)
        return RRRotation(p);
    return p;
}
avl_node* inpre(avl_node* p)///to find in-order predecessor.
{
    while(p->right != NULL)
        p = p->right;
    return p;
}
avl_node* insuc(avl_node* p)///to find in-order successor.
{
    while(p->left != NULL)
        p = p->left;
    return p;
}
avl_node* del_node(avl_node* p,int k)///to delete a certain node and balancing the tree.
{
    avl_node* q;
    if(p == NULL)
        return NULL;
    if(p->left == NULL && p->right == NULL)
    {
        if(p == root)
            root = p;
        delete(p);
        return NULL;
    }
    if(k < p->data)
        p->left = del_node(p->left,k);
    else if(k > p->data)
        p->right = del_node(p->right,k);
    else
    {
        if(node_height(p->left) > node_height(p->right))
        {
            q = inpre(p->left);
            p->data = q->data;
            p->left = del_node(p->left,q->data);
        }
        else
        {
            q = insuc(p->right);
            p->data = q->data;
            p->right = del_node(p->right,q->data);
        }
    }
    p = update(p);
    return p;
}
/// the code below is same as binary search tree.
void preorder(avl_node*p)
{
    stack <avl_node*> st;
    st.push(NULL);
    while(!st.empty())
    {
        if(p)
            cout << p->data << " " ;
        if(p->right)
            st.push(p->right);
        if(p->left)
        {
            p = p->left;
        }
        else
        {
            p = st.top();
            st.pop();
        }
    }
}
void levelorder(avl_node* p)
{
    queue<avl_node*>q;
    q.push(p);
    cout << p->data << " ";
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        if(p->left)
        {
            cout  << p->left->data << " ";
            q.push(p->left);
        }
        if(p->right)
        {
            cout  << p->right->data << " ";
            q.push(p->right);
        }
    }
}
void inorder(avl_node *p)/// it'll show elements in sorted order.
{
    if(p)
    {
        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
    }
}
avl_node *rsearch(int k)
{
    avl_node* p = root;
    while(p != NULL)
    {
        if(k == p->data)
            return p;
        else if(k < p->data)
            p = p->left;
        else
            p = p->right;
    }
    return NULL;
}
int main()
{
    int x;
    bool f = 1;
    while(1)
    {
        cout << "Insert : ";
        cin >> x;
        if(x)
        {
            if(f)
            {
                root = avl_insert(root,x);
                f = 0;
            }
            else
            avl_insert(root,x);
        }
        else
            break;
        cout << "\n";
    }
    cout << "\n";
    levelorder(root);
    cout << "\n";

    cout << "Delete : ";
    cin >> x;
    del_node(root,x);

    cout << "\n";
    levelorder(root);
    cout << "\n";
    cout << "Sorted : ";
    inorder(root);
    cout << "\n";
    cout << "Search : ";
    cin >> x;
    avl_node* t = rsearch(x);

    if(t != NULL)
        cout << x << " is found.\n";
    else
        cout << x << " is not found.\n";
    return 0;
}
