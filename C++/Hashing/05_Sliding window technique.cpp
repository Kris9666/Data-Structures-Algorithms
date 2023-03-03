// Sliding window technique 
// You are given an array with n elements, calculate the minimum sum of k, consecutive elements.
// 8 3
// -2 10 1 3 2 -1 4 5

// 9 14 6 4 5 8 
// 4
#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ff first
#define ss second 
#define setBits(x) builtin_popcount(x)

signed main(){
    int n,k;
    cin>>n>>k;

    vi a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    int s = 0, ans = INT_MAX;
    rep(i,0,k){
        s += a[i];
    }
    cout<<s<<" ";
    ans = min(ans, s);
    rep(i,1,n-k+1){
        s -= a[i-1];
        s += a[i+k-1];
        ans = min(ans,s);
        cout<<s<<" ";
    }
    cout<<endl;
    cout<<ans<<endl;
    return 0;
}