// STL Heap 

#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;
// Making Micros to save time
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ff first
#define ss second 
#define setBits(x) builtin_popcount(x)

signed main(){
    priority_queue<int, vector<int> > pq;         //use it for maxheap
    pq.push(2);
    pq.push(3);
    pq.push(1);
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
    priority_queue<int, vector<int>, greater<int> > pqm;   //use it for minheap
    pqm.push(2);
    pqm.push(1);
    pqm.push(3);
    cout<<pqm.top()<<endl;
    pqm.pop();
    cout<<pqm.top()<<endl;
}