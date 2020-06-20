#include <iostream>
#include <set>

using namespace std;

int main(){

    int n, x;
    cin >> n;

    set<int> s;//기본형이 오름차순
    for(int i=0; i<n; i++){
        cin >> x;
        s.insert(x);
    }
    

    for(auto it = s.begin(); it != s.end(); it++){
        cout << *it << " ";
    }

    return 0;
}