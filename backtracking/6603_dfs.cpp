#include <iostream>
#include <vector>

using namespace std;

int k, s;
vector<int> v;
vector<int> r;

void dfs(int cnt, int start){

    if(cnt == 6){
        for(int res : r){
            cout << res << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = start; i < k; i++){
        r.push_back(v[i]);
        dfs(cnt+1, i+1);
        r.pop_back();
    }
}


int main(){

    while(1){
        cin >> k;

        if(k == 0) break;

        for(int i=0; i<k; i++){
            cin >> s;
            v.push_back(s);
        }

        dfs(0, 0);
        cout << "\n";
        v.clear();
    }


    return 0;
}