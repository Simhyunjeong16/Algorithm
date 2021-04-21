#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int n;
    string str;
    map<string, int> m;
    int big = 0;

    cin >> n;

    while(n--){
        cin >> str;
        m[str]++;
    }

    for(auto it = m.begin(); it != m.end(); it++){
        big = max(big, it->second);
    }

    for(auto it = m.begin(); it != m.end(); it++){
        if(big == it->second){//key값으로 이미 정렬되어 있다.
            cout << it->first;
            return 0;
        }
    }

}
