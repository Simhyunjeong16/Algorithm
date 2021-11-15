#include <iostream>
#include <set>

using namespace std;

int main(){
    int x, y;
    set<int> s;//중복제거

    for(int i = 0; i < 10; i++){
        cin >> x;
        
        y = x % 42;
        s.insert(y);
    }

    cout << s.size();
    return 0;
}
