#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    int cnt = 0;

    cin >> str;

    for(auto it : str){
        if(it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u'){
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}
