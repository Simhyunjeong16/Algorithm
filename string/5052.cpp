#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;//전화번호의 수
        string s;
        vector<string> v;
        bool flag = true;

        cin >> n;

        for(int i = 0; i < n; i++){
            cin >> s;
            v.push_back(s);
        }
        
        sort(v.begin(), v.end());//사전순서대로 정렬

        for(int i = 0; i < n-1; i++){
            int cur = v[i].length();
            int nex = v[i+1].length();

            if(cur >= nex){
                continue;
            }

            if(v[i+1].substr(0, cur) == v[i]){
                cout << "NO" << endl;
                flag = false;
                break;
            }
        }

        if(flag) cout << "YES" << endl;
    }


    return 0;
}
