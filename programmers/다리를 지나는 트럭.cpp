#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> q;
    int time = 0;
    int sum = 0;
    int i = 0;//index
    
    while(1){
        time++;

        //트럭 도착 -> pop
        if(q.size() == bridge_length){
            sum -= q.front();
            q.pop();
        }

        if(sum + truck_weights[i] <= weight){

            if(i == truck_weights.size()-1){//마지막 트럭이라면
                time += bridge_length;
                break;
            }

            q.push(truck_weights[i]);
            sum += truck_weights[i];
            i++;
        }
        
        //트럭의 무게 > 다리의 무게 -> 0 삽입하여 트럭이 도착할 수 있게 만듬
        else{
            q.push(0);
        }
    }
    

    return time;
}