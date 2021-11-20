#include <iostream>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;

    while (t--)
    {
        string str;
        cin >> str;
        
        if(str.size() == 1){
            cout << str << str << endl;
        }
        else if(str.size() == 2){
            cout << str << endl;
        }
        else{
            cout << str[0] << str[str.size()-1] << endl;
        }

    }

    return 0;
}
