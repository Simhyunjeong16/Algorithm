#include <iostream>
#include <string>

using namespace std;

int main(){
    char x;
    string str;

    while(cin >> x){
        if(x == '#') break;

        int cnt = 0;
        getline(cin, str);
        
        for(char it : str){
            if(tolower(it) == x) cnt++;
        }

        cout << x << " " << cnt << "\n";
    }

    return 0;
}
