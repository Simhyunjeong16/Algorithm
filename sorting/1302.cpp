#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<string, int> x, pair<string, int> y){
    if(x.second == y.second){
        return x.first < y.first;
    }

    return x.second > y.second;
}

int main(){
    int n;
    string str;
    vector<pair<string, int>> v;

    cin >> n;

    while(n--){
        cin >> str;
        
        int i;
        for(i = 0; i < v.size(); i++){
            if(v[i].first == str){
                v[i].second += 1;
                break;
            }
        }
        
        if(i == v.size()){
            v.push_back({str, 1});
        }
    }

    sort(v.begin(), v.end(), comp);

    cout << v[0].first;
    return 0;
}
