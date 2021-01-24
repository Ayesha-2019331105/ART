#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define maxn 200
ll arr[maxn],n;
void merge_sort(ll low, ll mid, ll high)
{
    ll i = low, j = mid+1, k = low;
    ll aux[maxn];
    while(i<=mid && j<=high)
    {
        if(arr[i]<arr[j])
            aux[k++] = arr[i++];
        else
            aux[k++] = arr[j++];
    }
    for(; i <= mid; i++)
    {
        aux[k++] = arr[i];
    }
    for(; j <= high; j++)
    {
        aux[k++] = arr[j];
    }
    for(i = low; i <= high; i++)
        arr[i] = aux[i];
}
void itrve_merge_sort(ll n)
{
    ll part,low,high,mid,i;
    for(part = 2; part <= n; part = part*2)
    {
        for(i = 0; i+part-1 <= n; i = i+part)
        {
            low = i;
            high = i+part-1;
            mid = (low+high)/2;
            merge_sort(low,mid,high);
        }
    }
    if(part/2 < n)
    {
        merge_sort(0,part/2,n);
    }
}
void recur_merge_sort(ll low, ll high)
{
    ll mid;
    if(low<high)
    {
        mid = (low+high)/2;
        recur_merge_sort(low,mid);
        recur_merge_sort(mid+1,high);
        merge_sort(low,mid,high);
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
    itrve_merge_sort(n);
    for(ll i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    arr[n-4] -= 2;
    recur_merge_sort(0,n-1);
    for(ll i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}
