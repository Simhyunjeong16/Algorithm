#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long cnt = 0;//long long으로 해야 함!!
int n, s;
int arr[42];
vector<int> a;
vector<int> b;

void Calc_a(int idx, int sum){
    sum += arr[idx];

    if(idx == n/2) return;//노드 끝까지 간 경우 return

    if(sum == s) cnt++;

    a.push_back(sum);

    Calc_a(idx+1, sum - arr[idx]);
    Calc_a(idx+1, sum);
}

void Calc_b(int idx, int sum){
    sum += arr[idx];

    if(idx == n) return;//노드 끝까지 간 경우 return

    if(sum == s) cnt++;

    b.push_back(sum);

    Calc_b(idx+1, sum - arr[idx]);
    Calc_b(idx+1, sum);
}

int main(){
    
    cin >> n >> s;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    /* 배열을 반으로 나누는 계산 = A, B
        1. A의 부분집합의 합 중에서 s를 만들 수 있는 경우
        2. B의 부분집합의 합 중에서 s를 만들 수 있는 경우
        3. A와 B의 부분집합의 합 중에서 A+B로 s를 만들 수 있는 경우
    */

    //나눠논 각 배열에 대한 만들 수 있는 모든 부분집합의 합들을 미리 구해놓기
    Calc_a(0, 0);
    Calc_b(n/2, 0);

    //이분탐색을 위해서 정렬하기
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    //이분탐색을 이용해서 cnt 구하기
    for(int i = 0; i < a.size(); i++){

        int t = s - a[i];//a[i]로 s를 만들기 위해서는 s-a[i]가 존재해야 한다
        
        int low = lower_bound(b.begin(), b.end(), t) - b.begin();
        int upp = upper_bound(b.begin(), b.end(), t) - b.begin();

        cnt += (upp - low);//같은 값이 여러개가 존재할 수 있기 때문에, s-a[i]값 개수파악
    }

    cout << cnt;
    return 0;
}
