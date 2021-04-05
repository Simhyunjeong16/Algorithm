#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

    int n;
    int answer = 0;
    string str;
    vector<string> v;
    
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> str;
        v.push_back(str);
    }

    int sz = v[0].size();
    for(int i = 1; i < n; i++){

        vector<pair<char, bool>> res;
        for(int x = 0; x < sz; x++){
            res.push_back({v[0][x], false});
        }

        int cnt = 0;
        int word_size = v[i].size(); 

        for(int j = 0; j < word_size; j++){
            for(int k = 0; k < res.size(); k++){
                if(res[k].first == v[i][j] && !res[k].second){
                    res[k].second = true;
                    cnt++;
                    break;
                }
            }
        }
        
        
        if(sz == cnt && sz == word_size) answer++; //같은 구성
        
        else if(sz == cnt && sz+1 == word_size) answer++;//한문자를 더해서 같은 구성
        
        else if(sz-1 == cnt && sz-1 == word_size) answer++;//한문자를 빼서 같은 구성
        
        else if(sz-1 == cnt && sz-1 == word_size-1) answer++;//한문자를 다른 문자로 바꿔 같은 구성
        
    }

    cout << answer;
    return 0;
}
