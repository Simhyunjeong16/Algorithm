#include <iostream>

using namespace std;

int main(){
    bool a[31] = { false };
    
    for(int i = 0; i < 28; i++){
        int student;
        cin >> student;
        a[student] = true;
    }


    for(int i = 1; i <= 30; i++){
        if(!a[i]) cout << i << "\n";
    }

    return 0;
}