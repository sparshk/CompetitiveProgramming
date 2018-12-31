#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    if(k > n)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    int kk,now;
    kk = n;
    now = 1;
    priority_queue<int>p_q;
    while(kk)
    {
        if(kk & 1)
            p_q.push(now);
        kk>>=1;
        now<<=1;
    }
    if(p_q.size() > k)
    {
        printf("NO");
        return 0;
    }
    cout<<"YES"<<endl;
    while(p_q.size() != k)
    {
        int x = p_q.top();
        p_q.pop();
        p_q.push(x/2);
        p_q.push(x/2);
    }

    while(!p_q.empty())
    {
        int x = p_q.top();
        cout<<x<<" ";
        p_q.pop();
    }
    return 0;
}