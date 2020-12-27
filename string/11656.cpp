#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string s;
    vector<string> v;

    cin >> s;

    for(int i = 0; i < s.size(); i++){
        string x = s.substr(i, s.size()-i);//문자열 시작 위치, 그 위치로 부터 문자 몇개를 추출할것인지
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }

    return 0;
}
