def solution(s):
    answer = ''
    
    lst = list(map(int, s.split()));
    # lst.sort()
    # answer = str(lst[0]) + " " + str(lst[-1]);
    answer = str(min(lst)) + " " + str(max(lst));
    
    return answer