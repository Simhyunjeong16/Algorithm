s = str(input())
tag = ""
word = ""
chk = False

for i in range(len(s)):
    
    if s[i] == '<':
        
        if word != "":
            print(''.join(reversed(word)), end = '')
            word = ""
        
        tag += s[i]
        chk = True
        
    elif chk == True:
        tag += s[i]
        
        if s[i] == '>':
            print(tag, end = '')
            tag = ""
            chk = False
    
    else:
        if s[i] == ' ':
            print(''.join(reversed(word)), end = " ")
            word = ""
        
        else:
            word += s[i]
        

if word != "":
    print(''.join(reversed(word)), end = " ")
