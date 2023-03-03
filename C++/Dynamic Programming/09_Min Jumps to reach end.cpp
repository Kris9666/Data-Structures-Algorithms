// Minimum Jumps to reach end 
// Input : 11 
//         1 3 5 8 9 2 6 7 6 8 9 
// Output : 3


#include<iostream>
#include<vector>
#define vi vector<int>
#define rep(i,a,b) for(int i=a; i<b; i++)
using namespace std;
const int inf = 1e3+2; 
int main(){
    int n;
    cin>>n;
    vi a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    vi jumps(n,inf);
    jumps[0] = 0;
    rep(i,1,n){
        rep(j,0,i){
            if(i<=(j+a[j])){
                jumps[i] = min(jumps[i], jumps[j]+1);
            }
        }
    }
    cout<<jumps[n-1]<<endl;
    return 0;
}