#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct subject{//구조체
    string name;
    int korean, english, math;
};

bool cmp(subject x, subject y){

    if(x.korean == y.korean && x.english == y.english && x.math == y.math){//모든 점수가 같으면
        return x.name < y.name;//이름이 사전 순으로 증가하는 순서로
    }

    else if(x.korean == y.korean && x.english == y.english){//국어 점수와 영어 점수가 같으면
        return x.math > y.math;//수학 점수가 감소하는 순서로
    }

    else if(x.korean == y.korean){//국어 점수가 같으면
        return x.english < y.english;//영어 점수가 증가하는 순서로
    }

    return x.korean > y.korean;//국어 점수가 감소하는 순서로
}

int main(){
    int n;
    cin >> n;
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<subject> v(n);
    
    for(int i = 0; i < n; i++){
        cin >> v[i].name >> v[i].korean >> v[i].english >> v[i].math;
    }
    
    sort(v.begin(), v.end(), cmp);

    for (auto it : v){
        cout << it.name << "\n";
    }

    return 0;
}
