t = int(input())
a = []

for _ in range(t):
    sound = list(map(str, input().split()))
    animal = list(map(str, input().split()))
    
    while(animal[0] != 'what'):
        a.append(animal[2])
        animal = list(map(str, input().split()))
        
    for i in range(len(sound)):
        for j in range(len(a)):
            if sound[i] == a[j]:
                sound[i] = "#"
                break
                
    for i in sound:
        if i != "#":
            print(i, end = ' ')
