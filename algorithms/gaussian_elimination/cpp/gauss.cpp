#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<
int ,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>pbd_set;
typedef pair<int,int> ii;
typedef pair<ii,int> pii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<pii> vpii;
typedef long long int ll;
typedef unsigned long long int ull;

#define mi 1000000007
#define rep(i,a,b) for(i=a;i<b;i++)
#define repv(i,a,b) for(i=b-1;i>=a;i--)
#define pr(arr,n) rep(i,0,n) cout<<arr[i]<<" "; cout<<endl;
#define pr1(arr,n) rep(i,1,n+1) cout<<arr[i]<<" "; cout<<endl;
#define inf INT_MAX
#define gc getchar_unlocked
#define PB push_back
#define MP make_pair
#define fi first
#define se second
#define SET(a,b) memset(a,b,sizeof(a))
#define MAX 500005
#define gu getchar
#define pu putchar
#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define TRACE

#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif

int mult(int x,int y)
{
  ll ans,x1=(ll)x,y1=(ll)y;
  ans=(x1*y1)%mi;
  return (int)ans;
}
int gcd(int a,int b) { return b==0 ? a : gcd (b,a%b);}
int lcm(int a,int b) { return a*(b/gcd(a,b));}

ll pow1(ll a,ll b)
{
  ll ans=1;
  while(b>0)
    {
      if(b&1) ans=(ans*a)%mi;	
      a=(a*a)%mi; b>>=1;
    }	
  return ans;
}
//solve returns no. of solutions and stores in ans array if solution exists
namespace Gauss
{
  const int mxc=1005;
  const double EPS=1e-9;
  double ans[mxc],row[mxc];
  int solve(double a[][mxc],int rows,int cols)
  {
    int n=rows,m=cols,i,j;
    rep(i,0,m)
      row[i]=-1;
    rows=cols=0;
    while(rows<n && cols<m)
      {
	int curr=rows;
	rep(i,rows,n)
	  if(abs(a[i][cols])>abs(a[curr][cols]))
	    curr=i;
	if(abs(a[curr][cols])<EPS)
	  {
	    cols++;
	    continue;
	  }
	rep(i,col,m+1)
	  swap(a[curr][i],a[rows][i]);
	row[cols]=rows;
	rep(i,0,n)
	  {
	    if(i==rows) continue;
	    double tmp=a[i][cols]/a[curr][cols];
	    rep(j,cols,m+1)
	      a[i][j]-=a[rows][j]*tmp;
	  }
	rows++; cols++;
      }
    rep(i,0,m)
      {
	if(row[i]!=-1)
	  ans[i]=a[row[i]][m]/a[row[i]][i];
	else
	  ans[i]=0;
      }
    rep(i,0,n)
      {
	double sum=0;
	rep(j,0,m)
	  sum+=ans[j]*a[i][j];
	if(abs(sum-a[i][m])>EPS)
	  return 0;
      }
    rep(i,0,m)
      if(row[i]==-1)
	return inf;
    return 1;
  }
};
int main()
{
  
  return 0;
}
