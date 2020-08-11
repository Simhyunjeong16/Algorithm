#include <iostream>
#include <list>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    list<int> lst;

    for(int i = 1; i <= n; i++){
        lst.push_back(i);
    }

    cout << "<";

    while(!lst.empty()){
        
        for(int i = 0; i < k-1; i++){
            lst.push_back(lst.front());
            lst.pop_front();
        }

        cout << lst.front();
        lst.pop_front();

        if(!lst.empty()) cout << ", ";
    }
    

    cout << ">";
    return 0;
}