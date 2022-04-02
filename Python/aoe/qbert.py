#Catalina Leal 21.248.896-8
#Vicente Alves 21.290.051-6
#Cristóbal Mansilla
import random
import pygame
import sys

def prota ():
    opcion = 3
    if opcion == 0:
        prota = pygame.image.load("pj.png")
    if opcion == 1:
        prota = pygame.image.load("pj_rojo.png")
    if opcion == 2:
        prota = pygame.image.load("pj_azul.png")
    if opcion == 3:
        prota = pygame.image.load("pj_verde.png")
    return prota
    

def main (tabla):
    pygame.init()
    pygame.mixer.init()
    ventana = pygame.display.set_mode((864,720))
    pygame.display.set_caption("Q*bert Space War")
    ventana.fill((25,166,194)) #Red Green Blue

    pj1 = pygame.image.load("pj_verde.png")
    pj2 = pygame.image.load("pj.png")
    pj3 = pygame.image.load("pj_azul.png")
    pj4 = pygame.image.load("pj_rojo.png")
    
    fondo = pygame.image.load("2kmdlrc0av041.png")
    seleccionar = pygame.image.load("sel.png")
    escoger = pygame.image.load("escoger.png")
    escoger = pygame.transform.scale(escoger, ((150,163)))
    meteorito1 = pygame.image.load("meteorito.png")
    meteorito2 = pygame.image.load("meteoritopisado.png")
    start = pygame.image.load("meteoritostart.png")
    obstaculo = pygame.image.load("obstaculo.png")
    b_pausa = pygame.image.load("pausa.png")
    corazon1 = pygame.image.load("corazon1.png")
    corazon1 = pygame.transform.scale(corazon1, ((170,170)))
    corazon2 = pygame.image.load("corazon2.png")
    corazon2 = pygame.transform.scale(corazon2, ((170,170)))
    corazon3 = pygame.image.load("corazon3.png")
    corazon3 = pygame.transform.scale(corazon3, ((170,170)))
    musica_pausa = pygame.mixer.music.load("pausaop.mp3")
    sonido_seleccionar = pygame.mixer.Sound("sonidoseleccionar.mp3")
    sonido_seleccionar.set_volume(0.4)
    movimiento_sonido = pygame.mixer.Sound("movimiento.mp3")
    movimiento_sonido.set_volume(0.3) # volumen sonido mov

    corriendo = True
     
    posicion_x = 0
    posicion_y = 0
    cordenada_x = 0
    cordenada_y = 0
    pausa = 0
    valor_puntuacion = 0
    bloques = 0
    vidas = 0
    sel_personaje = 0
    prota = pj1
    #pygame.draw.rect(ventana,(255,0,0), pygame.Rect((posicion_x,posicion_y,40,40)))
    ventana.blit(fondo, ((0,0)))
    

    pygame.display.flip()

    reloj = pygame.time.Clock()
    while corriendo:
        reloj.tick(60) #fps

        ventana.blit(fondo, ((0,0)))
        
        cordenada = tabla[cordenada_x][cordenada_y]

        font = pygame.font.Font('freesansbold.ttf',32)

        puntuacion = font.render("Score : " + str(valor_puntuacion), True, (255,255,255))
        ventana.blit(puntuacion, (660, 50))
        
        while sel_personaje == 0:
            ventana.blit(seleccionar, pygame.Rect((0, 0, 48, 48)))
            if prota == pj1:
                ventana.blit(escoger, pygame.Rect((43, 43, 48, 48)))
                sonido_seleccionar.play
            if prota == pj2:
                ventana.blit(escoger, pygame.Rect((256, 43, 48, 48)))
                sonido_seleccionar.play
            if prota == pj3:
                ventana.blit(escoger, pygame.Rect((456, 43, 48, 48)))
                sonido_seleccionar.play
            if prota == pj4:
                ventana.blit(escoger, pygame.Rect((670, 43, 48, 48)))
                sonido_seleccionar.play
            for event in pygame.event.get():
                if event.type == pygame.QUIT:  ## hace que se cierre junto con  la linea de pygame.quit()
                    corriendo = False
            
                if event.type == pygame.KEYDOWN:
                    tecla_presionada = pygame.key.name(event.key)

                    if tecla_presionada == "1":
                            prota = pj1
                            sonido_seleccionar.play()
                    if tecla_presionada == "2":
                            prota = pj2
                            sonido_seleccionar.play()
                    if tecla_presionada == "3":
                            prota = pj3
                            sonido_seleccionar.play()
                    if tecla_presionada == "4":
                            prota = pj4
                            sonido_seleccionar.play()
                    if tecla_presionada =="l":
                            sel_personaje = 1
                    print(tecla_presionada)
                
            pygame.display.flip()
        #print(cordenada, cordenada_x, cordenada_y)
        for i in range((len(tabla))):
            for j in range((len(tabla))):
                if tabla[i][j] == "2":
                    ventana.blit(obstaculo, pygame.Rect((64*i, 64*j, 48, 48)))
                    
                    #pygame.draw.rect(ventana,(255,242,0), pygame.Rect((64*i, 64*j, 48, 48)))
                else:
                    ventana.blit(meteorito1 , pygame.Rect((64*i, 64*j, 48, 48)))
                    
                    #pygame.draw.rect(ventana, (0, 0, 255), pygame.Rect(64*i, 64*j, 48, 48))


        
            
        for i in range ((len(tabla))):
            for j in range((len(tabla))):
                if tabla [i][j] == "1":
                    ventana.blit(start, ((64*i,64*j,48,48)))
                if tabla[i][j] == "-":
                    ventana.blit(meteorito2 , pygame.Rect((64*i, 64*j, 48, 48)))                    
                    #pygame.draw.rect(ventana,(0,255,0), pygame.Rect((64*i,64*j,48,48)))
                

        #print (cordenada, cordenada_x, cordenada_y)
        

        #pygame.draw.rect(ventana,(163,73,164), pygame.Rect((posicion_x,posicion_y,48,48)))
        ventana.blit(prota, ((posicion_x,posicion_y,48,48)))
        if vidas == 3:
            ventana.blit(corazon3, (( 651, 50)))
        if vidas == 2:
            ventana.blit(corazon2, (( 651, 50)))
        if vidas == 1:
            ventana.blit(corazon1, (( 651, 50)))

        if pausa == 1:
            ventana.blit(b_pausa, pygame.Rect((0, 0, 48, 48)))
            musica_pausa = pygame.mixer.music.play(-1)
            pygame.display.flip()

        while pausa == 1:
            
            for event in pygame.event.get():
                if event.type == pygame.QUIT:  ## hace que se cierre junto con  la linea de pygame.quit()
                    corriendo = False
            
                if event.type == pygame.KEYDOWN:
                    tecla_presionada = pygame.key.name(event.key)
                    if tecla_presionada == "p":
                        pausa = 0
                        print(pausa)
    
        if pausa == 0:
            musica_pausa = pygame.mixer.music.stop()
        if (bloques == 93):
            ventana.blit(b_pausa, pygame.Rect((0, 0, 48, 48)))
            pygame.display.flip()
        
        for event in pygame.event.get():

            if event.type == pygame.QUIT:  ## hace que se cierre junto con  la linea de pygame.quit()
                corriendo = False
            
            if event.type == pygame.KEYDOWN:
                tecla_presionada = pygame.key.name(event.key)
                
                if tecla_presionada == "w": 
                    if cordenada_y > 0:
                        if tabla[cordenada_x][cordenada_y-1] != "2":
                            posicion_y -=64
                            cordenada_y -= 1
                            cordenada = tabla[cordenada_x][cordenada_y]
                            movimiento_sonido.play()
                            if cordenada == "+":
                                tabla[cordenada_x][cordenada_y] = "-"
                            elif cordenada == "-":
                                tabla[cordenada_x][cordenada_y] = "+"
                            if cordenada == "+":
                                valor_puntuacion += 10
                                bloques += 1
                            if cordenada == "-":
                                valor_puntuacion -= 10
                                bloques -= 1

                if tecla_presionada == "a":
                    if cordenada_x > 0:
                        if tabla[cordenada_x-1][cordenada_y] != "2":
                            posicion_x -=64
                            cordenada_x -= 1
                            cordenada = tabla[cordenada_x][cordenada_y]
                            movimiento_sonido.play()
                            if cordenada == "+":
                                tabla[cordenada_x][cordenada_y] = "-"
                            elif cordenada == "-":
                                tabla[cordenada_x][cordenada_y] = "+"
                            if cordenada == "+":
                                valor_puntuacion += 10
                                bloques += 1
                            if cordenada == "-":
                                valor_puntuacion -= 10
                                bloques -= 1
                if tecla_presionada == "s":
                    if cordenada_y < 9:
                        if tabla[cordenada_x][cordenada_y+1] != "2":
                            posicion_y +=64
                            cordenada_y += 1
                            cordenada = tabla[cordenada_x][cordenada_y]
                            movimiento_sonido.play()
                            if cordenada == "+":
                                tabla[cordenada_x][cordenada_y] = "-"
                            elif cordenada == "-":
                                tabla[cordenada_x][cordenada_y] = "+"    
                            if cordenada == "+":
                                valor_puntuacion += 10
                                bloques += 1
                            if cordenada == "-":
                                valor_puntuacion -= 10
                                bloques -= 1
                if tecla_presionada == "d":
                    if cordenada_x < 9:
                        if tabla[cordenada_x+1][cordenada_y] != "2":
                            posicion_x +=64
                            cordenada_x += 1
                            cordenada = tabla[cordenada_x][cordenada_y]
                            movimiento_sonido.play()
                            if cordenada == "+":
                                tabla[cordenada_x][cordenada_y] = "-"
                            elif cordenada == "-":
                                tabla[cordenada_x][cordenada_y] = "+"
                            if cordenada == "+":
                                valor_puntuacion += 10
                                bloques += 1
                            if cordenada == "-":
                                valor_puntuacion -= 10
                                bloques -= 1
                if tecla_presionada == "p":
                    pausa = 1
                if tecla_presionada == "k":
                    vidas += 1

                #print (cordenada)
        pygame.display.flip()
    pygame.quit()
    sys.exit()



def tablero ():
    aleatorio_1 = random.randint(2,8) # Variables que definirán la base de nuestros puntos aleatorios sin obstruir el inicio
    aleatorio_2 = random.randint(2,8)
    aleatorio_3 = random.randint(2,7)
    aleatorio_4 = random.randint(2,7)
    aleatorio_5 = random.randint(3,7)   
    aleatorio_6 = random.randint(3,7)   
    # Fin

    #Se encarga de que las variables no sean iguales
    while aleatorio_1 == aleatorio_3 and aleatorio_2 == aleatorio_4:
        aleatorio_3 = random.randint(2,7)
        aleatorio_4 = random.randint(2,7)

    while aleatorio_5 == aleatorio_3 or aleatorio_5 == aleatorio_1 and aleatorio_6 == aleatorio_4 or aleatorio_6 == aleatorio_2:
        aleatorio_5 = random.randint(3,7)
        aleatorio_6 = random.randint(3,7)
    #Fin


    #Tablero
    tablero = []
    for i in range (10):
        fila =[]
        for j in range (10):
            fila.append("+")
        tablero.append(fila)
    tablero[0][0]="1"
    #fin

    obstaculo_1 = tablero[aleatorio_1][aleatorio_2] = "2" #obstaculo 1
    obstaculo_2 = tablero[aleatorio_3][aleatorio_4] = "2" #obstaculo 2
    obstaculo_3 = tablero[aleatorio_5][aleatorio_6] = "2" #obstaculo 3
    print(aleatorio_1,aleatorio_2 ,aleatorio_3,aleatorio_4)
    print(aleatorio_5,aleatorio_6)

    x_1 = aleatorio_1
    y_1 = aleatorio_2
    x_2 = aleatorio_3
    y_2 = aleatorio_4
    x_3 = aleatorio_5
    y_3 = aleatorio_6

    #Extensión obstáculo 2
    suma_1 = random.randrange(-1,2,1)
    suma_2 = random.randrange(-1,2,1)
    obstaculo_21 = tablero[aleatorio_3+suma_1][aleatorio_4+suma_2 ]
    #print ("s1",suma_1 ,suma_2)
    while (obstaculo_21 == "2") :
        suma_1 = random.randrange(-1,2,1)
        suma_2 = random.randrange(-1,2,1)
        print ("obs21" ,suma_1 ,suma_2)
        obstaculo_21= tablero[aleatorio_3+suma_1][aleatorio_4+suma_2]
    for i in range (2):
        obstaculo_21 = tablero[aleatorio_3+suma_1][aleatorio_4+suma_2] = "2"
    print ("obstaculo_21: " ,aleatorio_3 + suma_1, aleatorio_4+suma_2)
    #Fin extension 

    #extensión obstáculo 3
    suma_3 = random.randrange(-1,2,1) #primer brazo(x)
    suma_4 = random.randrange(-1,2,1) #primer brazo(y)
    suma_5 = random.randrange(-1,2,2) #segundo brazo(x) 
    suma_6 = random.randrange(-1,2,2) #segundo brazo(y)
    #inicio primer brazo
    obstaculo_31 = tablero[aleatorio_5+suma_3][aleatorio_6+suma_4]
    print ("obs1:",aleatorio_5+suma_3, aleatorio_6+suma_4)

    while (obstaculo_31 == "2"):
        suma_3 = random.randrange(-1,2,1)
        suma_4 = random.randrange(-1,2,1)
        print ("obs31:",aleatorio_5+suma_3, aleatorio_6+suma_4)
        obstaculo_31 = tablero[aleatorio_5+suma_3][aleatorio_6+suma_4]

    for i in range (2):
        obstaculo_31 = tablero[aleatorio_5+suma_3][aleatorio_6+suma_4] = "2"
    print ("obstaculo_31" ,aleatorio_5+suma_3, aleatorio_6+suma_4)
    #fin primer brazo
    #inicio segundo brazo
    obstaculo_32 = tablero [aleatorio_5+suma_5][aleatorio_6+suma_6]
    print ("obs32:",aleatorio_5+suma_5, aleatorio_6+suma_6)
    while (obstaculo_32 == "2"):
        suma_5 = random.randrange(-1,2,1)
        suma_6 = random.randrange(-1,2,1)
        obstaculo_32 = tablero [aleatorio_5+suma_5][aleatorio_6+suma_6]
        print("obstaculo32", aleatorio_5+suma_5, aleatorio_6+suma_6)

    for i in range (2):
        obstaculo_32 = tablero[aleatorio_5+suma_5][aleatorio_6+suma_6] = "2"
    #Fin extensión 3



    return(tablero)

tabla = tablero()
#for i in range(len(tabla)):
#    print(tabla[i])

main(tabla)
