#include <iostream>
#include <string>

using namespace std;

int main(){
    
    int t;
    cin >> t;

    while(t--){
        string s;
        int jumsu = 0;
        int t = 1;

        cin >> s;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'O'){
                jumsu += t;
                t++;
            }
            else{//'X'
                t = 1;
            }
        }

        cout << jumsu << "\n";
    }

    return 0;
}
