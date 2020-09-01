#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){

    int n;
    int answer = 0;
    int alphabet[26] = {0};
    vector<int> a;
    string s;
    
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> s;

        for(int j = 0; j < s.length(); j++){//'A' = 65이니까 0이 A라서 -65를 한다.
            alphabet[s[j] - 65] += (int)pow(10, s.length()-1-j);
        }
    }

    for(int i = 0; i < 26; i++){//존재하는 알파벳을 담기
        if(alphabet[i] > 0) a.push_back(alphabet[i]);
    }

    sort(a.begin(), a.end(), greater<int>());//내림차순 정렬

    int num = 9;
    for(int i = 0; i < a.size(); i++){
        answer += a[i] * num;
        num--;
    }

    cout << answer;

    return 0;
}
