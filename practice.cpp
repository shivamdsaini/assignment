#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define endl "\n"
#define f(i,n) for(ll i=0;i<n;i++)
#define fa(i,a,n) for(ll i=a;i<n;i++)

vector<vector<ll>>v;
ll cap,glb;

ll powerLL(ll x, ll n)
{
   ll result = 1;
   while (n) {
      if (n & 1)
          result = result * x;
      n = n / 2;
      x = x * x;
   }
   return result;
}

string DtoB(int num)
{
    string str;
    while(num)
    {
        if(num & 1)
            str+='1';
        else
            str+='0';
        num>>=1;
    }   
    return str;
}

void split(ll x)
{
    ll sum=0,y=v.size();
    vector<ll>w;
    w.pb(v[x][0]+powerLL(2,v[x][1]));
    v[x][1]++;
    w.pb(v[x][1]);
    v.pb(w);
    w.clear();
    f(i,v[x].size())
    {
        w.pb(v[x][i]);
    }
    v[x].clear();
    v[x].pb(w[0]);
    v[x].pb(w[1]);
    for(ll i=2;i<w.size();i++)
    {
        sum=0;
        for(ll j=0;j<w[1];j++)
        {
            sum=sum+(w[i]&powerLL(2,j));
        }
        if(sum==w[0])
        {
            v[x].pb(w[i]);
            continue;
        }
        v[y].pb(w[i]);
    }
    w.clear();
    if(v[x].size()>cap+2)
    {
        split(x);
    }
    if(v[y].size()>cap+2)
    {
        split(y);
    }
    
}

void display( )
{
    ll sum=glb;
    f(i,v.size())
    {
        sum=max(sum,v[i][1]);
    }
    cout<<sum<<endl<<v.size()<<endl;
    f(i,v.size())
    {
        cout<<v[i].size()-2<<" "<<v[i][1]<<"\n";
    }
    cout<<endl;
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll x,y,sum;
    cin>>glb>>cap;
    vector<ll>w;
    f(i,powerLL(2,glb))
    {
        w.pb(i);
        w.pb(glb);
        v.pb(w);
        w.clear();
    }
    
    while(1)
    {
        cin>>x;
        if(x==6)break;
        
        if(x==5)display();
    
        if(x==4)
        {
            bool flag = false;
            cin>>y;
            f(i,v.size())
            {
                auto it=v[i].begin();
                ++it;
                ++it;
                while(it!=v[i].end())
                {
                    if(*it==y)
                    {
                        v[i].erase(it);
                        flag = true;
                        break;
                    }
                    ++it;
                }
                if(flag)
                {
                    break;
                }
            }
        }
        if(x==3)
        {
            cin>>y;
            bool flag = false;
            f(i,v.size())
            {
                fa(j,2,v[i].size())
                {
                    if(v[i][j]==y)
                    {
                        flag = true;
                        break;
                    }
                }
                if(flag)
                {
                    break;
                }
            }
        }
        if(x==2)
        {
            cin>>y;
            f(i,v.size())
            {
               int sum=0;
                f(j,v[i][1])
                {
                    sum=sum+(y&powerLL(2,j));
                }
                if(sum==v[i][0])
                {
                    v[i].pb(y);
                    if(v[i].size()>cap+2)
                    {
                        split(i);
                    }
                    break; 
                }
            }
        }
    }
}