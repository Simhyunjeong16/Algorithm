#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int leftHand = 10, rightHand = 12, leftDist, rightDist;
    
    for(int n : numbers){
        if(n == 1 || n == 4 || n == 7){//왼쪽 키패드
            answer += 'L';
            leftHand = n;
        }
        else if(n == 3 || n == 6 || n == 9){//오른쪽 키패드
            answer += 'R';
            rightHand = n;
        }
        else{//가운데 키패드
            if(n == 0) n = 11;//0을 11로 바꿔주기

            int leftTemp = abs(leftHand - n);
            int rightTemp = abs(rightHand - n);
            
            leftDist = (leftTemp / 3) + (leftTemp % 3);
            rightDist = (rightTemp / 3) + (rightTemp % 3);

            if(leftDist < rightDist){
                answer += 'L';
                leftHand = n;
            }
            else if(leftDist > rightDist){
                answer += 'R';
                rightHand = n;
            }
            else{
                if(hand == "right"){//오른손잡이
                    answer += 'R';
                    rightHand = n;
                }
                else{//왼손잡이
                    answer += 'L';
                    leftHand = n;
                }
            }
        }
    }
    
    
    return answer;
}