import pygame,sys,random
from Funciones import *

pygame.init()

def Victoria():
    resolucion=[960,800]
    ventana=pygame.display.set_mode(resolucion)
    Continuar=pygame.Rect(resolucion[0]-100,resolucion[1]-100,150,50)
    run=True
    while run:
        ventana.fill((145, 47, 218))
        for event in pygame.event.get():
            if event.type==pygame.QUIT:
                sys.exit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    run = False
        escribir_texto_time(ventana,(resolucion[0]-100,resolucion[1]-100),"Continuar",40)
        pygame.display.flip()
Victoria()