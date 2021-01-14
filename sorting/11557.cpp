#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){

        int n;
        string s;
        int l;
        vector<pair<int, string>> v;
        
        cin >> n;

        while(n--){
            cin >> s >> l;
            v.push_back(make_pair(l, s));
        }

        sort(v.begin(), v.end(), greater<pair<int, string>>());

        cout << v[0].second << endl;
    }
   
    return 0;
}
