t = int(input())
a = []

for _ in range(t):
    sound = list(map(str, input().split()))
    animal = list(map(str, input().split()))
    
    while(animal[0] != 'what'):
        a.append(animal[2])
        animal = list(map(str, input().split()))
        
    for s in sound:
        if s not in a:
            print(s, end = " ")
