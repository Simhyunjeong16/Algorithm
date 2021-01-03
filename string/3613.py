s = str(input())

def cppTojava(s):
    answer = ""
    
    if s[0] == '_' or s[-1] == '_': #처음이나 마지막이 _면 에러
        return "Error!" 
        
    if "__" in s: #연속으로 __가 나오면 에러
        return "Error!"
    
    for i in range(len(s)):
        
        if s[i].isupper() == True:
            return "Error!"
        
        elif s[i-1] == '_':
            answer += s[i].upper()
        
        elif s[i] != '_':
            answer += s[i]
        
    return answer
    
    
def javaTocpp(s):
    answer = ""
    
    if s[0].isupper() == True: #처음이 대문자면 에러
        return "Error!" 
    
    for i in range(len(s)):
        
        if s[i].isupper() == True:
            answer += ('_' + s[i].lower())
            
        else:
            answer += s[i]
    
    return answer


if '_' in s:
    print(cppTojava(s))
else: 
    print(javaTocpp(s))
