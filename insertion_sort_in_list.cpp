#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define maxn 2000000
struct node
{
    ll data;
    node* next;
};
void sortedInsert(node** head_ref, node* new_node)
{
    node* cur;
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {
        cur = *head_ref;
        while (cur->next!=NULL &&
               cur->next->data < new_node->data)
        {
            cur = cur->next;
        }
        new_node->next = cur->next;
        cur->next = new_node;
    }
}
void insertion_sort_in_list(node** head_ref)
{
    node* sorted = NULL;
    node* cur = *head_ref;
    while(cur != NULL)
    {
        node *next = cur->next;
        sortedInsert(&sorted,cur);
        cur = next;
    }
    *head_ref = sorted;
}
void display(node *head_ref)
{
    node *temp = head_ref;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void push_in_list(node** head_ref, ll new_data)
{
    node* new_node = new node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;//cout << new_node->next->data << " ";
}
int main()
{
    node* h = NULL;
    puts("Enter the number of elements.");
    ll n;
    cin >> n;
    puts("Enter the elements of the to be sorted.");
    for(ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        push_in_list(&h,x);
    }
    insertion_sort_in_list(&h);
    display(h);
    cout << "\n";
    return 0;
}
/**
10
11
13
7
12
16
9
24
5
10
3
*/

