#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

vector<int> v;
// vector<int>::iterator iter;

int main(){
    int num;
    cin >> num;

    int cnt = 0, tmp = 0;

    v.push_back(INT_MIN);//우선 가장 최솟값을 넣어준다.

    for(int i=0; i<num; i++){
        cin >> tmp;

        if(v.back() < tmp){
            v.push_back(tmp);
            cnt++;
        }
        
        else{//자리 찾기
            //auto = 초기화 값에 따라 알아서 데이터 타입을 정해주는 키워드
            auto iter = lower_bound(v.begin(), v.end(), tmp);//시작과 끝에서 tmp 이상인 값을 찾고 최솟값의 위치 반환
            *iter = tmp;//it자리에 해당하는 값 tmp로 변경
        }


    }

    cout << cnt;

    return 0;
}