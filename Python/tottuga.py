from turtle import *

def grafico():
    ht()
    up()
    seth(-90)
    speed(10)
    setx(-300)
    sety(250)
    down()
    st()
    forward(10)

grafico()

n=7
for i in range(n):
    right(90)
    forward(20)
    up()
    backward(20)
    down()
    right(-90)
    if i != n-1:
        forward(50)
    else:
        right(-90)



x = input()
