# 🖤 알고리즘 🖤

- **공부한 사이트** : 백준, 프로그래머스, 구름, 코딜리티
- **사용한 언어** : C++, Python
<br>

## Implementation (구현)
- 머릿속에 있는 알고리즘을 **소스코드**로 바꾸는 과정
<br>

## Simulation
- 문제에서 제시한 알고리즘을 한 단계씩 차례대로 직접 수행
<br>

## Brute force (완전 탐색)
- 가능한 모든 경우의 수를 탐색하면서, 요구조건에 충족되는 결과를 가져오는 방법
- 선형 구조를 전체적으로 탐색하는 **순차 탐색** <br>
  비선형 구조를 전체적으로 탐색하는 **DFS, BFS**
<br>

## BFS (넓이 우선 탐색)
- **Queue** 사용
  - FIFO
  - Queue: 방문한 노드들을 순서대로 push, pop할 수 있는 자료구조
- 루트노드에서 시작해서 인접한 노드를 먼저 탐색하는 방법
- 장) 최단 길이 경로 보장
- 단) 큐를 이용해 next 탐색 노드를 저장하기 때문에, 노드의 수가 많을 수록 <br>
      필요없는 노드들까지 저장해야 해서 큰 저장 공간이 필요하다
<br>

## DFS (깊이 우선 탐색)
- Stack or 재귀함수 구현
- 현재 지점에서 방문할 곳이 있으면 **재귀 호출**을 통해서 탐색하는 방법
- 장) 깊은 곳을 찾아야 할때 효과적.
- 단)
  - 모든 곳을 방문하기 때문에, 비효율적인 결과 나올 수 있음.
  - BFS에 비해서 느림.
  - 어떤 노드에 방문했는지 여부를 검사해야 함. (검사 X -> 무한루프 주의)
- 시간복잡도: O(N^2)
<br>

## Backtracking (백트래킹)
- 유망하지 않으면 배제를 하고, 부모노드로 되돌아가면서 풀이 시간 단축
- 가지치기(Purning)을 통해 효율 극대화 <br> 가능성이 없는 루트를 가지치기로 쳐내서 탐색하는 기법
<br>

## Union Find
- 그래프 알고리즘, 두 노드가 같은 그래프에 속하는지 판별하는 알고리즘
- 노드를 합치는 Union 연산과 루트 노드를 찾는 Find 연산
- ...
<br>

## Sorting
1. 버블 정렬
2. 선택 정렬
3. 삽입 정렬
4. 퀵 정렬
<br>

## heap
- **완전 이진 트리**의 일종, 우선순위 큐를 위해 만들어진 자료구조
- 장) 최대값, 최소값을 쉽게 알 수 있다.
- 시간복잡도 : O(nlog₂n)
<br>

## Topology Sort (위상 정렬)
- 정렬 알고리즘의 일종, **순서가 정해져 있는 일련의 작업을 차례대로 수행할 때** 사용하는 알고리즘
- 사이클이 없는 방향 그래프의 모든 노드를 순서대로 나열
<br>

## Binary search (이진 탐색)
- 데이터가 정렬되어 있는 배열(*오름차순*)에서 **특정한 값을** 찾아내는 알고리즘
- 처음 중간 값을 임의 값으로 선택하여, 그 값과 find하는 값의 크고 작음을 비교하는 방식으로 전개
- 장) 검색이 반복될 때마다, 목표값을 찾을 확률은 2배가 되므로 --> 속도 FAST
- 단) 정렬된 리스트에서만 사용 가능
<br>

## DP (Dynamic Programming, 동적 계획법)
- 모든 방법을 검토하여 최적의 해를 찾는 방식
  - 큰 문제를 작은 문제로 나누어서 푸는 방식
  - 조건
    1. **작은 문제가 반복적으로 일어난다.**
    2. **같은 문제는 구할 때마다 정답이 같다.**
  - **Memoization** : 1번 계산한 작은 문제를 저장해놓고 다시 사용하는 것
  - 구현방법
    1. Bottom-up: 작은 문제부터 구해가는 방법
    2. Top-down : 큰 문제를 풀 때 작은 문제가 아직 풀리지 않았으면 그때 작은 문제 해결 (재귀함수)
<br>

## Greedy
- 여러 경우 중 하나를 결정해야 할 때마다, 그 순간 최적이라 생각되는 것을 선택하는 방법
<br>

## Dijkstra (다익스트라)
- 최단 경로 탐색 알고리즘
- **특정한 하나의 정점에서 다른 모든 정점으로 가는 최단 경로**를 알 수 있음.
- 하나의 최단 거리를 구할 때, 그 이전까지 구했던 최단 거리 정보를 그대로 사용 <br>
  (현재까지 알고있던 최단경로를 계속해서 갱신)
<br>

## Floyd warshall (플로이드 와샬)
- **모든 정점에서 모든 정점으로의 최단경로**를 구할 수 있음.
- '거쳐가는 정점'을 기준으로 최단 거리를 구한다.
<br>

## Eratosthenes (에라토스테네스의 체)
- 소수 판별 알고리즘 (소수: 양의 약수 2개만 가지는 자연수)
- 장) 대량의 소수를 한번에 판별할 때 편리
- 구현 방법: 2부터 시작해서 특정 수의 배수에 해당하는 수를 모두 지운다. (자기자신은 제외)
<br>

## Two Pointer
- 1차원 배열에서 **2개의 포인터 위치를 기록하면서 처리**하는 알고리즘
- 시간복잡도 : O(N)
<br>
