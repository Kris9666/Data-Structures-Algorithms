// Count number of binary strings without consecutive 1s.
// Input : n=3
// Output : 5

#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> fib(n+2,0);
    fib[0]=1;
    fib[1]=1;
    for(int i=2; i<=n+1; i++){
        fib[i] = fib[i-1]+fib[i-2];
    }
    cout<<fib[n+1];
    cout<<endl;
    return 0;
}

