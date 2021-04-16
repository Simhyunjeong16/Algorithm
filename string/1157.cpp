#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<char, int> x, pair<char, int> y){
    return x.second > y.second;
}

int main(){
    string str;
    vector<pair<char, int>> v;

    cin >> str;

    for(char it : str){
        it = towupper(it);//대문자로 변경
        int i = 0;
        
        for(i = 0; i < v.size(); i++){
            if(v[i].first == it){
                v[i].second += 1;
                break;
            }
        }

        if(i == v.size()) v.push_back({it, 1});
    }

    sort(v.begin(), v.end(), cmp);

    if(v[0].second != v[1].second) cout << v[0].first;
    else cout << '?';

    return 0;
}
