#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;//상한액
    long long sum = 0;
    
    sort(budgets.begin(), budgets.end());
    
    for(int i = 0; i < budgets.size(); i++)
            sum += budgets[i];
    
    if(sum <= M) return budgets[budgets.size()-1];
    
    int start = 0;
    int end = budgets[budgets.size()-1]-1;
    int mid;

    while(start <= end){
        sum = 0;
        mid = (start + end) / 2;

        for(int i = 0; i < budgets.size(); i++){
            if(budgets[i] <= mid) sum += budgets[i];
            else sum += mid;
        }
        
        if(sum > M){
            end = mid - 1;
        }
        else{//sum <= M
            answer = max(answer, mid);
            start = mid + 1;
        }
        
    }
    
    
    return answer;
}