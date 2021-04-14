#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    string str;
    vector<string> v;
    vector<string> ans;
    
    cin >> n >> m;//듣도 못한 사람의 수 N, 보도 못한 사람의 수 M

    for(int i = 0; i < n; i++){
        cin >> str;
        v.push_back(str);
    }

    sort(v.begin(), v.end());//정렬이 되어 있다는 가정하에

    for(int i = 0; i < m; i++){
        cin >> str;

        //binary_search: 검색해주는 함수로서 찾는 값이 존재하면 True, 아니면 False를 리턴
        if(binary_search(v.begin(), v.end(), str)){//듣보잡
            ans.push_back(str);
        }
    }

    sort(ans.begin(), ans.end());
   
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << "\n";
    }

    return 0;
}
