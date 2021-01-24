#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define maxn 2000
ll arr[maxn],n;
void seletion_sort()
{
    ll k,j;
    for(ll i = 0; i < n-1; i++)
    {
        for(j=k=i; j < n; j++)
        {
            if(arr[j]<arr[k])
                k=j;
        }
        swap(arr[i],arr[k]);
    }
}
int main()
{
    puts("Enter the number of elements.");
    cin >> n;
    puts("Enter the elements of the to be sorted.");
    for(ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    seletion_sort();
    for(ll i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}
