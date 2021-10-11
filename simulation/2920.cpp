#include <iostream>

using namespace std;

int main(){
    int res[8];
    int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int d[8] = {8, 7, 6, 5, 4, 3, 2, 1};

    for(int i = 0; i < 8; i++){
        cin >> res[i];
    }

    int x, y;
    for(x = 0; x < 8; x++){
        if(a[x] != res[x]) break;
    }

    if(x == 8) {
        cout << "ascending";
    }
    else{
        for(y = 0; y < 8; y++){
            if(d[y] != res[y]) break;
        }        
        if(y == 8) cout << "descending";
        else cout << "mixed";
    }

    return 0;
}