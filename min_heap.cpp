#include<bits/stdc++.h>
using namespace std;

#define maxn 1e10
#define ll long long
#define pb push_back
#define inf 99999999
struct heap
{
    int data;
    heap* parent;
    heap* left;
    heap* right;
};
struct heap* root = NULL;
heap* place_to_insrt()
{
    queue<heap*>q;
    q.push(root);
    heap* temp = new heap();
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        if(temp->left && temp->right)
        {
            q.push(temp->left);
            q.push(temp->right);
        }
        else
            break;
    }
    //else
        return temp;
}
void check(heap* p)
{
    if(p->parent == NULL)
        return;
    if(p->parent->data > p->data)
    {
        swap(p->parent->data,p->data);
        check(p->parent);
    }
}
void add(heap* p, int k)
{
    p = new heap();
    if(root == NULL)
    {
        p->data = k;
        p->left=p->parent=p->right=NULL;
        root = p;
        return;
    }
    heap* node = place_to_insrt();
    if(!node->left)
    {
        p->data = k;
        p->parent = node;
        p->left=p->right=NULL;
        node->left = p;
    }
    else
    {
        p->data = k;
        p->parent = node;
        p->left=p->right=NULL;
        node->right = p;
    }
    check(p);
}
heap* reinst()
{
    queue<heap*>q;
    q.push(root);
    heap* temp;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        if(temp->left)
        {
            q.push(temp->left);
        }
        if(temp->right)
        {
            q.push(temp->right);
        }
    }
    return temp;
}
void delcheck(heap* node)
{
    heap* hi = node;
    if(node->left && node->left->data < hi->data)
    {
        hi = node->left;
    }
    if(node->right && node->right->data < hi->data)
    {
        hi = node->right;
    }
    if(hi != node)
    {
        swap(hi->data,node->data);
        delcheck(hi);
    }
}
queue<int>min_sort;
void del()
{
    if(root == NULL)
    {
        cout << "Heap is empty!!\n";
        return;
    }
    heap* node = reinst();
    if(node == root)
    {
        min_sort.push(node->data);
        delete node;
        root = NULL;
        return;
    }
    swap(root->data,node->data);
    heap* pr = node->parent;
    if(pr->left == node)
    {
        min_sort.push(node->data);
        delete node;
        pr->left = NULL;
    }
    else
    {
        min_sort.push(node->data);
        delete node;
        pr->right = NULL;
    }
    delcheck(root);
}
void levelorder(heap* p)
{
    queue<heap*>q;
    q.push(p);
    cout << p->data << "\n";
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
        cout << "\n";
    }
}
int main()
{
    add(root,5);
    add(root,10);
    add(root,30);
    add(root,20);
    add(root,35);
    add(root,40);
    add(root,15);
    levelorder(root);
    while(root != NULL)
        del();
    cout << "Heap sort :\n";
    while(!min_sort.empty())
    {
        cout << min_sort.front() << " ";
        min_sort.pop();
    }
    cout << "\n";
    return 0;
}
