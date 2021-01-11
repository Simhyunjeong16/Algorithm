#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, x;
int avg = 0, mid = 0, f = 0, r = 0;//산술평균, 중앙값, 최빈값, 범위
vector<int> v;

bool cmp(pair<int, int> x, pair<int, int> y){
    if(x.second == y.second){
        return x.first < y.first;
    }
    return x.second > y.second;
}

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());

    if(n > 1) r = v.back()- v.front();//범위
    mid = v[n/2];//중앙값

    //산술평균
    for(int i = 0; i < n; i++){
        avg += v[i];
    }
    avg = round((float)avg / n);//반올림

    //최빈값
    vector<pair<int, int>> arr;
    for(int i = 0; i < n; i++){

        if(arr.empty()){//비어있으면
            arr.push_back(make_pair(v[i], 1));
        }
        else if(arr.back().first == v[i]){//존재하면(순서대로 하니까 가능)
            arr.back().second += 1;
        }
        else{//존재안하면
            arr.push_back(make_pair(v[i], 1));
        }
    }

    sort(arr.begin(), arr.end(), cmp);
    
    if(arr[0].second == arr[1].second) {
        f = arr[1].first;//여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력
    }
    else {
        f = arr[0].first;
    }


    cout << avg << "\n" << mid << "\n" << f << "\n" << r;
    return 0;
}
