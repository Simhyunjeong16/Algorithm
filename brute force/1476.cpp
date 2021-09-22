#include <iostream>

using namespace std;

int main(){
    int e, s, m;//최대범위: 15, 28, 19
    cin >> e >> s >> m;

    if(e == s && s == m){
        cout << e;
    }
    else if(e < s && s == m){
        cout << s;
    }   
    else{
        if(e == 15) e = 0;
        if(s == 28) s = 0;
        if(m == 19) m = 0;
        
        int year = 0;
        while(1){
            year++;
            if((year % 15 == e) && (year % 28 == s) && (year % 19 == m)){
                cout << year;
                break;
            }
        }
    }

    return 0;
}