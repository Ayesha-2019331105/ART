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
    if(p->parent->data < p->data)
    {
        swap(p->parent->data,p->data);
        check(p->parent);
    }
}
stack<heap*>heapi;
void add(heap* p, int k)
{
    p = new heap();
    if(root == NULL)
    {
        p->data = k;
        p->left=p->parent=p->right=NULL;
        root = p;
        heapi.push(p);
        return;
    }
    heap* node = place_to_insrt();
    if(!node->left)
    {
        p->data = k;
        p->parent = node;
        p->left=p->right=NULL;
        node->left = p;
        heapi.push(p);
    }
    else
    {
        p->data = k;
        p->parent = node;
        p->left=p->right=NULL;
        node->right = p;
        heapi.push(p);
    }
    //heapi.push(p);
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
    if(node->left && node->left->data > hi->data)
    {
        hi = node->left;
    }
    if(node->right && node->right->data > hi->data)
    {
        hi = node->right;
    }
    if(hi != node)
    {
        swap(hi->data,node->data);
        delcheck(hi);
    }
}
queue<int>ssort;
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
        ssort.push(node->data);
        delete node;
        root = NULL;
        return;
    }
    swap(root->data,node->data);
    heap* pr = node->parent;
    if(pr->left == node)
    {
        ssort.push(node->data);
        delete node;
        pr->left = NULL;
    }
    else
    {
        ssort.push(node->data);
        delete node;
        pr->right = NULL;
    }
    delcheck(root);
}
void heapify(heap* p)
{
    if(p == NULL)
    {
        cout << "\nHeap is empty!!\n";
        return;
    }
    if(!p->left && !p->right)
    {
        return;
    }
    while(p != NULL)
    {
        int q = p->data;
        int l = 0, r = 0;
        if(p->left != NULL)
            l = p->left->data;
        if(p->right != NULL)
            r = p->right->data;
        if(l > q &&  l > r)
        {
            swap(p->left->data,p->data);
            p = p->left;
        }
        else if(r > q &&  r > l)
        {
            swap(p->right->data,p->data);
            p = p->right;
        }
        else
        {
            break;
        }
    }
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
    int n,cnt,x,str;
    cout << "Enter the number of query : ";
    cin >> n;
    cout << "\nOptions :\n1.insert\n2.delete\n3.heapify\n4.heap sort";
    while(n--)
    {
        cout << "\nTry any option.\n";
        cin >> str;
        if(str == 1)
        {
            cout << "\nNode number : ";
            cin >> cnt;
            while(cnt--)
            {
                cin >> x;
                add(root,x);
            }
            cout << "\nThe max_heap---->\n";
            levelorder(root);
        }
        if(str == 2)
        {
            cout << "\nNumber of nodes to delete: ";
            cin >> cnt;
            while(cnt-- && root != NULL)
            {
                del();
                heapi.pop();
            }
            if(cnt == x)
            {
                cout << "\nHeap is empty.\n";
            }
            else
            {
                cout << "\nAfter deletion.\n";
                levelorder(root);
            }
        }
        if(str == 4)
        {
            cout << "\nHeap sort :\n";
            while(!ssort.empty())
            {
                cout << ssort.front() << " ";
                ssort.pop();
            }
        }
        if(str == 3)
        {
            while(!heapi.empty())
            {
                heapify(heapi.top());
                heapi.pop();
            }
            cout << "\nUsing heapify.\n";
            levelorder(root);
            cout << "\n";
        }
    }
    return 0;
}
