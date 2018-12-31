#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool isSuffix(string s1, string s2) 
{ 
    int n1 = s1.length(), n2 = s2.length(); 
    if (n1 > n2) 
      return false; 
    for (int i=0; i<n1; i++) 
       if (s1[n1 - i - 1] != s2[n2 - i - 1]) 
           return false; 
    return true; 
} 
bool isPrefix(string s1, string s2) 
{ 
    int n1 = s1.length(), n2 = s2.length(); 
    if (n1 > n2) 
      return false; 
    for (int i=0; i<n1; i++) 
       if (s1[i] != s2[i]) 
           return false; 
    return true; 
} 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("test.txt","r",stdin);
	ll n;
	cin>>n;
	vector<pair<string,int>> arr[110];
	string str[2*n-2];
	ll x=2*n-2;
	for(ll i=0;i<x;i++){
		cin>>str[i];

		//cout<<str[i]<<endl;
		arr[str[i].length()].push_back({str[i],i});
	}
	
		 string s[8];
		 s[0]=arr[1][0].first+arr[n-1][0].first;
		 s[1]=arr[1][0].first+arr[n-1][1].first;
		 s[2]=arr[1][1].first+arr[n-1][0].first;
		 s[3]=arr[1][1].first+arr[n-1][1].first;
		 s[4]=arr[n-1][0].first+arr[1][0].first;
		 s[5]=arr[n-1][0].first+arr[1][1].first;
		 s[6]=arr[n-1][1].first+arr[1][0].first;
		 s[7]=arr[n-1][1].first+arr[1][1].first;

	for(ll i=0;i<8;i++){
		char fin[2*n-2+1];
		bool flag=true;
		vector<pair<string,ll>> v;
		ll cs=0,cp=0;
		for(ll j=1;j<n;j++){
			if(isPrefix(arr[j][0].first,s[i])==true&&isSuffix(arr[j][0].first,s[i])==false){
			    
				fin[arr[j][0].second]='P';
				fin[arr[j][1].second]='S';
				cp+=1;
				cs+=1;
			}
			else if(isSuffix(arr[j][0].first,s[i])==true&&isPrefix(arr[j][0].first,s[i])==false){
				fin[arr[j][0].second]='S';
				fin[arr[j][1].second]='P';
				cs+=1;
				cp+=1;
			}
			else if(isPrefix(arr[j][0].first,s[i])==true&&isSuffix(arr[j][0].first,s[i])==true){
			    if(isPrefix(arr[j][1].first,s[i])==true&&isSuffix(arr[j][1].first,s[i])==false)
			    {
			    	fin[arr[j][1].second]='P';
			    	fin[arr[j][0].second]='S';
			    	cs+=1;
			    	cp+=1;
			    }
			    else if(isPrefix(arr[j][1].first,s[i])==false&&isSuffix(arr[j][1].first,s[i])==true)
			    {
			    	fin[arr[j][1].second]='S';
			    	fin[arr[j][0].second]='P';
			    	cs+=1;
			    	cp+=1;
			    }
			    else if(isPrefix(arr[j][1].first,s[i])==true&&isSuffix(arr[j][1].first,s[i])==true)
			    {
			    	fin[arr[j][1].second]='P';
			    	fin[arr[j][0].second]='S';
			    	cs+=1;
			    	cp+=1;
			    }
			    else if(isPrefix(arr[j][1].first,s[i])==false&&isSuffix(arr[j][1].first,s[i])==false)
			    {
			    	flag=false;
			    	break;
			    }

			    
			}
			else{
				flag=false;
				break;
			}

		}
		if(flag==true)
		{
			for(ll i=0;i<x;i++)
				cout<<fin[i];
			cout<<endl;
			break;
		}
		
	}

}