#include <iostream>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

bool comp(string x, string y){

    if(x.length() == y.length())
        return x < y;

    return x.length() < y.length();
}

int main(){

    int n;
    string m;
    set<string, decltype(comp)*> s(comp);

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> m;
        s.insert(m);
    }

    for(auto it = s.begin(); it != s.end(); it++){
        cout << *it << "\n";
    }

    return 0;
}