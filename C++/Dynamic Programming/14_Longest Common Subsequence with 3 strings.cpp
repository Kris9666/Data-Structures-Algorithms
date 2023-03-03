// Longest Common Subsequence (LCS) with 3 strings 
// Input : apna
//         collegeap
//         annnp
// Output : 2

// Recursion 
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int LCS(string &s1, string &s2, string &s3, int i, int j, int k){
//     if(i==0 || j==0 || k==0){
//         return 0;
//     }
//     if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]){
//         return 1 + LCS(s1,s2,s3,i-1,j-1,k-1);
//     }
//     int l = LCS(s1,s2,s3,i-1,j,k);
//     int r = LCS(s1,s2,s3,i,j-1,k);
//     int p = LCS(s1,s2,s3,i,j,k-1);
//     return max({l,r,p});
// }
// int main(){
//     string s1; cin>>s1;
//     string s2; cin>>s2;
//     string s3; cin>>s3;
//     cout<<LCS(s1,s2,s3, s1.size(), s2.size(), s3.size());
//     return 0;
// }

// Memorization
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i,a,b) for(int i=a; i<b; i++)
int dp[200][200][200];
int LCS(string &s1, string &s2, string &s3, int i, int j, int k){
    if(i==0 || j==0 || k==0){
        return 0;
    }
    if(dp[i][j][k] != -1){
        return dp[i][j][k];
    }
    if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]){
        return dp[i][j][k] = 1 + LCS(s1,s2,s3,i-1,j-1,k-1);
    }
    int l = LCS(s1,s2,s3,i-1,j,k);
    int r = LCS(s1,s2,s3,i,j-1,k);
    int p = LCS(s1,s2,s3,i,j,k-1);
    return dp[i][j][k] = max({l,r,p});
}
int main(){
    rep(i,0,200){
        rep(j,0,200){
            rep(k,0,200){
                dp[i][j][k] = -1;
            }
        }
    }
    string s1; cin>>s1;
    string s2; cin>>s2;
    string s3; cin>>s3;
    cout<<LCS(s1,s2,s3, s1.size(), s2.size(), s3.size());
}