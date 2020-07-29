from turtle import *
speed(10)

for i in range(1, 48) :
    if(i%6) :
        forward(100)
        left(144)
    else :
        penup()
        backward(100)
        lt(45)
        pendown()
        