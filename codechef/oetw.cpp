#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.txt","r",stdin);
	ll t;
	cin>>t;
	while(t-->0){
		ll n;
		cin>>n;
		ll arr[n];
		ll sum=0;
		ll c1=0,c2=0;
		for(ll i=0;i<n;i++)
		{
			cin>>arr[i];
			sum+=arr[i];
			if(arr[i]==1)
				c1+=1;
			else
				c2+=1;
		}
		if(c2==0){
			cout<<sum<<endl;
			continue;
		}
		if(c1==0){
			cout<<(sum/2)<<endl;
			continue;
		}
		c1=0;
		c2=0;
		if(arr[0]==1||arr[n-1]==1)
			cout<<sum<<endl;
		else{
			ll i=0,j=n-1;
			bool flag=true;
			for(;i<=j;i++,j--){
				if(arr[i]==1)
					break;
				if(arr[j]==1){
					flag=false;
					break;
				}
			}
			if(flag==true)
				cout<<sum-i<<endl;
			else
				cout<<sum-(n-j-1)<<endl;
		}
	}
}