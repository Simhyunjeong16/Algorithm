#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    string s;
    int cnt = 0;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> s;
        
        char t;
        vector<char> v;
        for(char c : s){
            if(find(v.begin(), v.end(), c) == v.end()){
                v.push_back(c);
                t = c;
            }
            else if(t == c) continue;
            else {
                t = '-';
                break;//그룹 단어가 아니다
            }
        }

        if(t != '-') cnt++;
    }

    cout << cnt;
    return 0;
}
