// Coin Change Problem 
// Given a set of coins and a value 'V'. Find the number of ways we can make change of 'V'.
// Input : n=3, coins=[1,2,3], V=5;
// Output: 5

// Recursion Process 
#include<iostream>
#include<vector>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ff first
#define ss second 
#define setBits(x) builtin_popcount(x)

int CoinChange(vi &a, int n, int x){
    if(x == 0){
        return 1;
    }
    if(x<0){
        return 0;
    }
    if(n<=0){
        return 0;
    }
    return CoinChange(a,n,x-a[n-1]) + CoinChange(a,n-1,x);
}
signed main(){
    int n;
    cin>>n;
    vi a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    int x;
    cin>>x;

    cout<<CoinChange(a,n,x);
    cout<<endl;
    return 0;
}

// Memorization 
#include<iostream>
#include<vector>
using namespace std;
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ff first
#define ss second 
#define setBits(x) builtin_popcount(x)
const int N = 1e3+2;
int dp[N][N];
int CoinChange(vi &a, int n, int x){
    if(x == 0){
        return 1;
    }
    if(x<0){
        return 0;
    }
    if(n<=0){
        return 0;
    }
    if(dp[n][x] != -1){
        return dp[n][x];
    }
    else{
        dp[n][x] = CoinChange(a,n,x-a[n-1]) + CoinChange(a,n-1,x);
    }
    return dp[n][x];
}
signed main(){
    rep(i,0,N){
        rep(j,0,N){
            dp[i][j] = -1;
        }
    }
    int n;
    cin>>n;
    vi a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    int x;
    cin>>x;

    cout<<CoinChange(a,n,x);
    cout<<endl;
    return 0;
}

// Tabulation 
#include<iostream>
#include<vector>
using namespace std;
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ff first
#define ss second 
#define setBits(x) builtin_popcount(x)
const int N = 1e3+2;
int dp[N];

signed main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    int x;
    cin>>x;

    vector<int> dp(x+1,0);
    dp[0] = 1;
    for(int i=0; i<n; i++){
        for(int j=a[i]; j<=x; j++){
            dp[j] += dp[j-a[i]];
        }
    }
    cout<<dp[x];
    cout<<endl;
    return 0;
}