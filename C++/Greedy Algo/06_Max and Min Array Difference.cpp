// Max and MIn Array Difference
// Given an array A of n elements. You have to remove exactly n/2 elements from array A and 
// add it to another array (initially empty).
// Find the maximum and minimum value of differences between these two arrays.
// We define the difference between these two arrays as: Sigma abs(A[i] - B[i]). 
// Input : 4
//         12 -3 10 0
// Output : 5 25


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for (auto &i : a){
        cin>>i;
    }
    sort(a.begin(), a.end());
    long long mn = 0,mx=0;
    for (int i=0; i<n/2; i++){
        mx += (a[i+n/2] - a[i]);
        mn += (a[2*i+1] - a[2*i]);
    }
    cout<<mn<<" "<<mx;
    return 0;

}
