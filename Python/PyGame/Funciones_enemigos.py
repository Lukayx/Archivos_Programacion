import pygame,sys,random,os
from Funciones import *

#colores
blanco=[255,255,255]
negro=[0,0,0]
rojo=[255,0,0]
verde=[0,255,0]
azul=[0,0,255]
verdeazul=[0, 200, 70]

#detectar colision
def detectar_colision(tecla,movx,movy,lista1):
    if tecla=="w":
        if movy==0 or lista1[movx][movy-1][2]==1:
            return 0
        else:
            return "w"
    if tecla=="a":
        if movx==0 or lista1[movx-1][movy][2]==1:
            return 0
        else:
            return "a"
    if tecla=="s":
        if movy==9 or lista1[movx][movy+1][2]==1:
            return 0
        else:
            return "s"
    if tecla=="d":
        if movx==9 or lista1[movx+1][movy][2]==1:
            return 0
        else:
            return "d"

#movimiento enemigo
def movimiento_enemigo(moex,moey,lista1,xd):
    direccion=direccion_alea_enemigo()
    if direccion=="arriba":
        if detectar_colision("w",moex,moey,lista1)=="w":
            moey-=1
        else:
            moey+=0
    if direccion=="izquierda":
        if detectar_colision("a",moex,moey,lista1)=="a":
            moex-=1
            xd=0
        else:
            moex+=0
    if direccion=="abajo":
        if detectar_colision("s",moex,moey,lista1)=="s":
            moey+=1
        else:
            moey+=0
    if direccion=="derecha":
        if detectar_colision("d",moex,moey,lista1)=="d":
            moex+=1
            xd=1
        else:
            moex+=0
    return [moex,moey,xd]

#generacion de enemigos
def generacion_enemigos(lista):
    bachelet_onu=True
    moex=random.randint(4,9)
    moey=random.randint(4,9)
    while bachelet_onu:
        if lista[moex][moey][2]==1:
            moex=random.randint(4,9)
            moey=random.randint(4,9)
        else:
            bachelet_onu=False
    return [moex,moey]

#direccion enemigo
def direccion_alea_enemigo():
    direccion=random.randint(0,3)
    if direccion==0:
        return "arriba"
    if direccion==1:
        return "izquierda"
    if direccion==2:
        return "abajo"
    if direccion==3:
        return "derecha"

#detectar colision jugador-enemigo
def detectar_jugadorenemigo(enemigox,enemigoy,jugadorx,jugadory,lista):
    ex1=lista[enemigox][enemigoy][0]
    ey1=lista[enemigox][enemigoy][1]
    jx1=lista[jugadorx][jugadory][0]
    jy1=lista[jugadorx][jugadory][1]
    if ex1==jx1 and ey1==jy1:
        return True
