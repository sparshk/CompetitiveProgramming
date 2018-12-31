#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void createArray(string pat, ll m, ll temp[]){
	ll i=1,j=0;
	temp[0]=0;
	while(i<m){
		//cout<<i<<" "<<j<<endl; 
		if(pat[i]==pat[j]){
			temp[i]=j+1;
			j++;
			i++;
		}
		else{
			if(j!=0)
				j=temp[j-1];
			else{
				temp[i]=0;
				i++;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.txt","r",stdin);
	ll n;
	cin>>n;
	string a,b;
	cin>>a;
	cin>>b;
	b=b+b;
	//cout<<b;
	ll temp[n];
	createArray(a,n,temp);
	ll i=0,j=0;
	ll start;ll s;
	ll count=0;
	ll ma=0;
	while(i<(2*n)){
		//cout<<i<<" "<<j<<endl;
		if(b[i]==a[j]){
			if(count==0){
				s=i;
			}
			count++;
			i++;
			j++;
		}
		if(j==n){
			break;
		}
		else if(i<(2*n)&&b[i]!=a[j])
		{
			if(count>ma){
				ma=count;
				start=s;
			}
			if(j!=0){
				j=temp[j-1];
				count=j;
			}
			else{
				count=0;
				i++;
			}
		}
	}
	cout<<start<<endl;
}