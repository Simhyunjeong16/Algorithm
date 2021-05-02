#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string str;
    int n;
    vector<string> dir;
    string res = "";

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> str;
        dir.push_back(str);
    }

    res = dir[0];
    for(int i = 1; i < n; i++){
        for(int j = 0; j < res.size(); j++){
            if(res[j] != dir[i][j]){
                res[j] = '?';
            }
        }
    }

    cout << res;
    return 0;
}
