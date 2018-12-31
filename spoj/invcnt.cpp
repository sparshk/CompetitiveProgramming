#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll cnt;
void merge(ll arr[], ll l, ll m, ll r) //geeksforgeeks
{ 
    ll i, j, k; 
    ll n1 = m - l + 1; 
    ll n2 =  r - m; 
  	ll x=l;
    /* create temp arrays */
    ll L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back llo arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
            cnt+=(n1-i);
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(ll arr[], ll l, ll r) //geeksforgeeks
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        ll m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
  
/* UTILITY FUNCTIONS */
/* Function to prll an array */
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.txt","r",stdin);
	ll t;
	cin>>t;
	while(t-->0){
		cnt=0;
		ll n;
		cin>>n;
		ll arr[n];
		for(ll i=0;i<n;i++)
			cin>>arr[i];
		mergeSort(arr,0,n-1);
		cout<<cnt<<endl;
 
 
 
 
	}
} 