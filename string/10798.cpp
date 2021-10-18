#include <iostream>
#include <string>

using namespace std;

int main(){
    string v[5];

    for(int i = 0; i < 5; i++){
        cin >> v[i];
    }

    for(int j = 0; j < 15; j++){//최대 15개의 글자이기 때문에
        for(int i = 0; i < 5; i++){//5줄
            if(j < v[i].size()){
                cout << v[i][j];
            }
        }
    }
    
    return 0;
}
