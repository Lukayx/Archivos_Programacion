import pygame,sys,random,os


# !-------Funciones-------! #

#generacion de enemigos
def generacion_enemigos(lista):
    moex=random.randint(4,9)
    moey=random.randint(4,9)
    bachelet_onu = True
    while bachelet_onu:
        if lista[moex][moey][2]==1:
            moex=random.randint(4,9)
            moey=random.randint(4,9)
        else:
            bachelet_onu=False
    return [moex,moey]

#movimiento enemigo
def movimiento_alea_enemigo():
    direccion=random.randint(0,3)
    if direccion==0:
        return "w"
    if direccion==1:
        return "a"
    if direccion==2:
        return "s"
    if direccion==3:
        return "d"

#crear boton
def crear_boton(pantalla,boton,texto):
    fuente1=pygame.font.SysFont("Times New Roman",30)
    if boton.collidepoint(pygame.mouse.get_pos()):
        pygame.draw.rect(pantalla,[225, 38, 180],boton,0)
    else:
        pygame.draw.rect(pantalla,[174, 15, 135],boton,0)
    ren=fuente1.render(texto,True,(255,255,255))
    pantalla.blit(ren,(boton.x+(boton.width-ren.get_width())/2,boton.y+(boton.height-ren.get_height())/2))

#imprime texto en pantalla
def escribir_texto_time(pantalla,localizacion,texto,tamaño):
    fuente1=pygame.font.SysFont("Times New Roman",tamaño)
    ren2=fuente1.render(texto,True,(0,0,0))
    pantalla.blit(ren2,((localizacion[0]-(ren2.get_width()/2)),(localizacion[1]-(ren2.get_height()/2))))

#detecta colision
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

#juego
def ejecucion_juego(ventana):
    final_final=0
    puntaje=1
    pygame.init()
    lista1=[]
    movx=0
    movy=0
    piñera_presidente=True
    generacion_final=[]
    igual=True
    igual2=True
    xd=0
    v=0
    # ? ------- LISTA DEL TABLERO ------- ? #
    for i in range(10):
        lista1.append([])   
        for j in range(10):
            x = 135 + (70*i)
            y = 120 + (60*j)
            lista1[i].append([x,y,0])
    # * ------- OBSTACULOS ------- * #
    obstaculo_pos=[(random.randint(2,9)),(random.randint(2,9))]

    obstaculo2_pos=[(random.randint(2,9)),(random.randint(2,9))]
    obstaculo2_1_pos=[obstaculo2_pos[0],obstaculo2_pos[1]-1]

    obstaculo3_pos=[(random.randint(2,9)),(random.randint(2,9))]
    obstaculo3_1_pos=[obstaculo3_pos[0],obstaculo3_pos[1]-1]
    obstaculo3_2_pos=[obstaculo3_pos[0]-1,obstaculo3_pos[1]]

    obstaculo3=[obstaculo3_pos,obstaculo3_1_pos,obstaculo3_2_pos]

    obstaculoslista=[obstaculo_pos,obstaculo2_pos,obstaculo2_1_pos,obstaculo3_pos,obstaculo3_1_pos,obstaculo3_2_pos]

    # ? IMPRIME OBBSTACULOS Y COMPRUEBA ? #
    while piñera_presidente:
        if igual==False and igual2==False:
            piñera_presidente=False
        if obstaculo2_pos==obstaculo_pos or obstaculo2_1_pos==obstaculo_pos:
            obstaculo2_pos=[(random.randint(2,8)),(random.randint(2,8))]
        else:
            igual=False
        while igual2:
            for obstaculo in obstaculo3:
                while obstaculo==obstaculo_pos:
                    obstaculo3_pos=[(random.randint(2,8)),(random.randint(2,8))]
                while obstaculo==obstaculo2_pos:
                    obstaculo3_pos=[(random.randint(2,8)),(random.randint(2,8))]
                while obstaculo==obstaculo2_1_pos:
                    obstaculo3_pos=[(random.randint(2,8)),(random.randint(2,8))]
            igual2=False

    # * ------- GENERACION OBSTACULOS LISTA ------- * #
    for a in obstaculoslista:
        lista1[a[0]][a[1]][2]=1

    # * ------- GENERACION ENEMIGOS ------- * #
    localizacion_enemigo=generacion_enemigos(lista1)
    moex=localizacion_enemigo[0]
    moey=localizacion_enemigo[1]
    
    # * ------- IMAGEN DE FONDO ------- * #
    background = pygame.image.load(os.path.dirname(os.path.abspath(__file__))+"\\Background\Background.png").convert_alpha()
    background = pygame.transform.scale(background,(960,800))

    # ? ------- ROCA ------- ? #
    roca = pygame.image.load(os.path.dirname(os.path.abspath(__file__))+"\\Sprites/roca.png").convert_alpha()
    roca = pygame.transform.scale(roca,(70,60))

    # ?  ------- ROCA CON TELEARAÑA ------- ? #
    roca2 = pygame.image.load(os.path.dirname(os.path.abspath(__file__))+"\\Sprites/RT1.png").convert_alpha()
    roca2 = pygame.transform.scale(roca2,(70,60))

    # ? ------- ROCA OBSTACULO ------- ? #
    rocaObs = pygame.image.load(os.path.dirname(os.path.abspath(__file__))+"\\Sprites/Roca punta Sangre.png").convert_alpha()
    rocaObs = pygame.transform.scale(rocaObs,(70,60))

    # * ------- ARAÑA ------- * #
    araña = [pygame.image.load(os.path.dirname(os.path.abspath(__file__))+"\\Sprites/ArañitaFinal_L.png").convert_alpha()
            ,pygame.image.load(os.path.dirname(os.path.abspath(__file__))+"\\Sprites/ArañitaFinal_R.png").convert_alpha()]
    araña[0] = pygame.transform.scale(araña[0],(45,45))
    araña[1] = pygame.transform.scale(araña[1],(45,45))

    pokemon = [pygame.image.load(os.path.dirname(os.path.abspath(__file__))+"\\Sprites/SQ_L.png").convert_alpha()
            ,pygame.image.load(os.path.dirname(os.path.abspath(__file__))+"\\Sprites/SQ_R.png").convert_alpha()]
    pokemon[0] = pygame.transform.scale(pokemon[0],(50,50))
    pokemon[1] = pygame.transform.scale(pokemon[1],(50,50))


    # * ------- AQUI ES DONDE SE CARGA LA MUSICA DE FONDO ------- * #
    pygame.mixer.music.load(os.path.dirname(os.path.abspath(__file__))+"\\Musica/mus_spider.wav")
    pygame.mixer.music.play(-1,0.0)
    pygame.mixer.music.set_volume(0.04)
    lista1[0][0][2]=2
    clock = pygame.time.Clock()
    run=True
    while run:
        # * --------- IMAGEN DE FONDO --------- * #
        ventana.fill((132,130,128))
        ventana.blit(background,[0,0])
        clock.tick(40)
        
        # * --------- TABLERO JUEGO --------- * #
        for c in lista1:
            for u in c:
                if u[2]==0:
                    ventana.blit(roca,[u[0],u[1]])
                else:
                    if u[2]==2:
                        ventana.blit(roca2,[u[0],u[1]])
                    if u[2]==1:
                        ventana.blit(rocaObs,[u[0],u[1]])
        
        # ? --------- TECLAS --------- ? #
        for event in pygame.event.get():
            if event.type==pygame.QUIT:
                pygame.mixer.music.stop()
                sys.exit()
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:# ! --------- SALIR DEL JUEGO --------- ! #
                    pygame.mixer.music.stop()
                    run = False
            
            #* --------- MOVIMIENTO JUGADOR --------- *#
                tecla_presionada = pygame.key.name(event.key)
                if tecla_presionada=="w" or tecla_presionada=="a" or tecla_presionada=="s" or tecla_presionada=="d":
                    direccion=movimiento_alea_enemigo()
                    if direccion=="w":
                        if detectar_colision("w",moex,moey,lista1)=="w":
                            moey-=1
                        else:
                            moey+=0
                    if direccion=="a":
                        if detectar_colision("a",moex,moey,lista1)=="a":
                            moex-=1
                            xd=0
                        else:
                            xd=0
                            moex+=0
                    if direccion=="s":
                        if detectar_colision("s",moex,moey,lista1)=="s":
                            moey+=1
                        else:
                            moey+=0
                    if direccion=="d":
                        if detectar_colision("d",moex,moey,lista1)=="d":
                            moex+=1
                            xd=1
                        else:
                            xd=1
                            moex+=0
                if tecla_presionada == "w":# ? ----------- ARRIBA ----------- ? #
                    if detectar_colision("w",movx,movy,lista1)=="w":
                        if lista1[movx][movy-1][2]==0:
                            lista1[movx][movy-1][2]=2
                            puntaje+=7
                        else:
                            lista1[movx][movy-1][2]=0
                            puntaje-=7
                        movy-=1
                    else:
                        movy+=0
                if tecla_presionada == "a": # ? ----------- IZQUIERDA ----------- ? #
                    if detectar_colision("a",movx,movy,lista1)=="a":
                        if lista1[movx-1][movy][2]==0:
                            lista1[movx-1][movy][2]=2
                            puntaje+=7
                            v=0
                        else:
                            lista1[movx-1][movy][2]=0
                            puntaje-=7
                            v=0
                        movx-=1
                    else:
                        movx+=0
                        v=0
                if tecla_presionada == "s": # ? ----------- ABAJO ----------- ? #
                    if detectar_colision("s",movx,movy,lista1)=="s":
                        if lista1[movx][movy+1][2]==0:
                            lista1[movx][movy+1][2]=2
                            puntaje+=7
                        else:
                            lista1[movx][movy+1][2]=0
                            puntaje-=7
                        movy+=1
                    else:
                        movy+=0
                if tecla_presionada == "d": # ? ----------- DERECHA ----------- ? #
                    if detectar_colision("d",movx,movy,lista1)=="d":
                        if lista1[movx+1][movy][2]==0:
                            lista1[movx+1][movy][2]=2
                            puntaje+=7
                            v=1
                        else:
                            lista1[movx+1][movy][2]=0
                            puntaje-=7
                            v=1
                        movx+=1
                    else:
                        movx+=0
                        v=1
        
        if puntaje==652:
            final_final+=1
        if final_final==2:
            pygame.mixer.music.stop()
            escribir_texto_time(ventana,(ventana.get_width()/2,ventana.get_height()/2),"Ganaste",50)
            ventana.blit(araña[v],(lista1[movx][movy][0]+18,lista1[movx][movy][1]-33))
            pygame.display.flip()
            pygame.time.wait(5000)
            run=False
            
        print(puntaje)
        ventana.blit(pokemon[xd],(lista1[moex][moey][0]+15,lista1[moex][moey][1]-39))
        ventana.blit(araña[v],(lista1[movx][movy][0]+18,lista1[movx][movy][1]-33)) # * --------- IMPRIME POSICION ARAÑA --------- * #
        pygame.display.flip()
