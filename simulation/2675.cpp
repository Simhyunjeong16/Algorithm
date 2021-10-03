#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int r;
        string s;

        cin >> r >> s;

        for(char it : s){
            for(int i = 0; i < r; i++) cout << it;
        }

        cout << "\n";
    }
    
    return 0;
}
