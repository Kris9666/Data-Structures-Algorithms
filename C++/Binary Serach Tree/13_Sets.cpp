// Set

// For Ordered set 
#include<iostream>
#include<set>
using namespace std;
int main(){
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    for (auto i : s){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<s.size();
    cout<<endl;
    s.erase(2);
    for (auto i : s){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}

// For Unordered set 
#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(3);
    for (auto i : s){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<s.size();
    cout<<endl;
    s.erase(3);
    for (auto i : s){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
