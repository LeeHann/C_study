# -*- coding: utf-8 -*-

cmd = input("원하시는 계산을 적으세요 : ")
print(f'당신은 {cmd} 을/를 입력하셨습니다.')

cmd = cmd.split()
ans = int(cmd[0])

for i in range(len(cmd)) :
    if cmd[i] == '+' :
        ans += int(cmd[i+1])
    elif cmd[i] == '-' :
        ans -= int(cmd[i+1])
    elif cmd[i] == '*' :
        ans *= int(cmd[i+1])
    elif cmd[i] == '/' :
        ans /= int(cmd[i+1])
    elif cmd[i] == '//' :
        ans //= int(cmd[i+1])        
print(ans)         

#if cmd[1] == '+' :
#    print(int(cmd[0]) + int(cmd[2]))
#elif cmd[1] == '-' :
#    print(int(cmd[0]) - int(cmd[2]))
#elif cmd[1] == '*' :
#    print(int(cmd[0]) * int(cmd[2]))
#elif cmd[1] == '/' :
#    print(int(cmd[0]) / int(cmd[2]))
#elif cmd[1] == '//' :
#    print(int(cmd[0]) // int(cmd[2]))
