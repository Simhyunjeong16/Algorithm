#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    
    int score;
    int sum = 0;
    vector<pair<int, int>> v;
    vector<int> ans;

    for(int i = 1; i <= 8; i++){
        cin >> score;
        v.push_back(make_pair(score, i));
    }

    sort(v.begin(), v.end(), greater<pair<int,int>>());

    for(int i = 0; i < 5; i++){
        sum += v[i].first;
        ans.push_back(v[i].second);
    }

    cout << sum << endl;
    
    sort(ans.begin(), ans.end());

    for(int i = 0; i < 5; i++){
        cout << ans[i] << " ";
    }
   
    return 0;
}
