// Indian Coin Change 
// You are given an array of denomination and a value X. You need to find the minimum number
// of coins required to make value X.
// Input : 10 
//         1 2 5 10 20 50 100 200 500 2000
//         350
// Output : 3


#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<string>
#include<vector>
#include<stack>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ff first
#define ss second 
#define setBits(x) builtin_popcount(x)

signed main(){
    int n;
    cin>>n;

    vi a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    int x;
    cin>>x;
    sort(a.begin(), a.end(), greater<int>());
    int ans = 0;

    for (int i=0; i<n; i++){
        ans += x/a[i];
        x -= x/a[i] * a[i];
    }
    cout<<ans<<endl;


    return 0;
}