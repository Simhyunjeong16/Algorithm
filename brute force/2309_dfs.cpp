#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int a[9];
bool chk[9];
vector<int> v;
bool flag = false;


void dfs(int cnt){

    if(cnt == 7){
        int result = 0;

        for(int i=0; i<9; i++){
            if(chk[i] == true){
                result += a[i];
                v.push_back(a[i]);

            }
        }
        
        
        if(result == 100 && flag == false) {//정답을 찾았다!

            sort(v.begin(), v.end());

            for(int i=0; i<v.size(); i++)
                cout << v[i] << "\n";
            
            flag = true;
        }

        v.clear();

        return;
    }


    for(int i=0; i<9; i++){
        if(chk[i] == true) continue;
        chk[i] = true;
        dfs(cnt+1);
        chk[i] = false;

    }


}



int main(){

    for(int i=0; i<9; i++){
        cin >> a[i];
    }

    dfs(0);

    return 0;
}