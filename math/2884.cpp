#include <iostream>

using namespace std;

int main(){
    int h, m;
    cin >> h >> m;

    if(m >= 45){
        cout << h << " " << m-45;
    }
    else{
        int t = 45 - m;
        
        if(h == 0){
            cout << 23 << " " << 60-t;
        }
        else{
            cout << h-1 << " " << 60-t;
        }
    }

    return 0;
}
