#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){

    int n, b;//10진법 수, 변환해야하는 진법
    string s = "";
    cin >> n >> b;
    
    map<int, char> m;
    char c = 'A';

    for(int i = 10; i <= 35; i++){
        m.insert({i, c});
        c++;
    }

    while(n > 0){

        int t = n % b;
        
        if(b > 10 && t >= 10 && t <= 35) s = m[t] + s;
        else s = to_string(t) + s;
        
        n /= b;
    }

    cout << s;
    return 0;
}