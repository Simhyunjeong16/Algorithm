#include <iostream>

using namespace std;

int main(){
    
    int a[501];
    int h, w;
    int answer = 0;

    cin >> h >> w;
    
    for(int i = 0; i < w; i++){
        cin >> a[i];
    }

    for(int i = 1; i < w-1; i++){//1부터 w바로 앞칸 까지
        for(int j = h - a[i]; j > 0; j--){//빗방울

            //열의 좌우로 해당 열(i)+빗방울이랑 같거나 더 높은 벽이 있으면 가능
            
            //왼쪽 계산
            bool left_chk = false;
            for(int x = 0; x < i; x++){
                if(a[x] >= j + a[i]){
                    left_chk = true;
                    break;
                }
            }

            //오른쪽 계산
            bool right_chk = false;
            for(int x = i+1; x < w; x++){
                if(a[x] >= j + a[i]){
                    right_chk = true;
                    break;
                }
            }

            if(left_chk && right_chk){
                answer += j;
                // cout << "i = " << i << ", j = " << j << endl;
                break;//최대 높이니까 break
            }
        }

    }

    cout << answer;

    return 0;
}