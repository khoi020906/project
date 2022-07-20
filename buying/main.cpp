#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define ll long long
#define ld long double
#define mp make_pair
#define FE freopen
#define in stdin
#define en cout<<"\n"
#define out stdout
#define bit(x) (1<<x);
#define getbit(x,pos) ((x<<pos)&1)
#define all(x) x.begin(),x.end()

using namespace std;

template<typename T1, typename T2> bool mini(T1 &a, T2 b) {if(a>b) a=b; else return 0; return 1;}
template<typename T1, typename T2> bool maxi(T1 &a, T2 b) {if(a<b) a=b; else return 0; return 1;}
template<typename T1> T1 abs(T1 a) {if(a<0) a*=-1; return a;}

int const N=2e5+7;
int const MAX=1e9+696969;
int const base=31;
ll const oo =1e18+696969;
ll dp[450][450]; int vis[400][400],n,a[3000],b[3000],c[3000];
typedef pair<int,int> ii;
typedef vector<ii> vii;



void open()
{
	FE("buying.inp","r",in);
	FE("buying.out","w",out);
}
long long f(int i, int cnt2, int cnt3)
{
    if (i>n) return 0;
    if (vis[cnt2][cnt3]) return dp[cnt2][cnt3];
    long long res=oo;
    vis[cnt2][cnt3]=1;
    res=min(res,f(i+1,cnt2,cnt3)+a[i]);
    res=min(res,f(i+1,cnt2+1,cnt3)+b[i]-cnt2);
    res=min(res,f(i+1,cnt2,cnt3+1)+c[i]-cnt3);
    return dp[cnt2][cnt3]=res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//open();
	cin>>n;
	for (int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
    }
    cout<<f(1,0,0);
	return 0;
}
