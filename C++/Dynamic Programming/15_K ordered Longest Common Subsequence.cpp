// K ordered LCS 
// Input : 5 5 1
//         1 2 3 4 5
//         5 3 1 4 2
// Output : 3


// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// #define rep(i,a,b) for(int i=a; i<b; i++)
// int n,m,k;
// vector<int> a,b;
// int Solve(int i, int j, int k){
//     if(i==n || j==m){
//         return 0;
//     }
//     int c1(0), c2(0), c3(0);
//     if(a[i] == b[j]){
//         c1 = 1+Solve(i+1,j+1,k);
//     }
//     if(k>0){
//         c2 = 1 + Solve(i+1,j+1,k-1);
//     }
//     else{
//         c3 = max(Solve(i+1,j,k), Solve(i,j+1,k));
//     }
//     return max({c1,c2,c3});
// }
// int main(){
//     cin>>n>>m>>k;
//     a = vector<int>(n);
//     b = vector<int>(m);
//     rep(i,0,n){
//         cin>>a[i];
//     }
//     rep(j,0,m){
//         cin>>b[j];
//     }
//     cout<<Solve(0,0,k);
// }


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int dp[2005][2005][7];
#define rep(i,a,b) for(int i=a; i<b; i++)
int n,m,k;
vector<int> a,b;
int Solve(int i, int j, int k){
    if(i==n || j==m){
        return 0;
    }
    if(dp[i][j][k] != -1){
        return dp[i][j][k];
    }
    int c1(0), c2(0), c3(0);
    if(a[i] == b[j]){
        c1 = 1+Solve(i+1,j+1,k);
    }
    if(k>0){
        c2 = 1 + Solve(i+1,j+1,k-1);
    }
    else{
        c3 = max(Solve(i+1,j,k), Solve(i,j+1,k));
    }
    return dp[i][j][k] = max({c1,c2,c3});
}
int main(){
    rep(i,0,2005){
        rep(j,0,2005){
            rep(k,0,7){
                dp[i][j][k]=-1;
            }
        }
    }
    cin>>n>>m>>k;
    a = vector<int>(n);
    b = vector<int>(m);
    rep(i,0,n){
        cin>>a[i];
    }
    rep(j,0,m){
        cin>>b[j];
    }
    cout<<Solve(0,0,k);
}