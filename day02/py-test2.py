finger = 0
ck = 0
n = int(input())

while(n>0) :
    if(ck == 0) :
        if(finger == 5) :
            ck = 1
            continue;
        finger = finger+1
    else :
        if(finger == 1) :
            ck = 0
            continue;
        finger = finger-1
    n = n-1
print(finger)