#include <iostream>
#include <string>
#include <map>

using namespace std;

int cnt = 0;
string t;
map<string, int> m;//map은 key값을 기준으로 자동 오름차순 정렬

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(getline(cin, t)){
        //if(t == "0") break;
        m[t]++;
        cnt++;
    }

    cout << fixed;
    cout.precision(4);//출력시 소수점 4째자리까지 나오며, 반올림됨.
    
    for(auto it = m.begin(); it != m.end(); it++){
        cout << it->first << ' ' << (it->second)*100/(double)cnt << "\n";
    }

    return 0;
}
