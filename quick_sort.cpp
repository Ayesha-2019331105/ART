#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define maxn 2000000
ll arr[maxn];
ll part(ll low, ll high)
{
    ll pivot = arr[low];
    ll i = low, j = high;
    do
    {
        do
        {
            i++;
        }while(arr[i] <= pivot);
        do
        {
            j--;
        }
        while(arr[j] > pivot);
        if(i < j)
            swap(arr[i],arr[j]);
    }while(i < j);
    swap(arr[low], arr[j]);
    return j;
}
void quick_sort(ll low, ll high)
{
    ll j;
    if(low < high)
    {
        j = part(low,high);
        quick_sort(low,j);
        quick_sort(j+1,high);
    }
}
int main()
{
    puts("Enter the number of elements.");
    ll n;
    cin >> n;
    puts("Enter the elements of the to be sorted.");
    for(ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quick_sort(0,n);
    for(ll i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}
