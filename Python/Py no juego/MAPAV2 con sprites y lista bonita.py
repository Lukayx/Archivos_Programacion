import pygame,sys,random,os

pygame.init()
xventana=800
yventana=600
blanco=(255,255,255)
negro=(0,0,0)
rojo=(255,0,0)
verde=(0,255,0)
azul=(0,0,255)

# ? coordenadas movimiento araña
xAraña=50
yAraña=50
size=40
cube_size=[45,45]
tablero = []
x = 160
y=90

# * TABLERO CON ARRAYS
for i in range(10):
    tablero.append([])
    for j in range(10):
        x = 160 + (50*i)
        y = 90 + (50*j)
        tablero[i].append([x,y,0])

# * VENTANA
ventana = pygame.display.set_mode((xventana,yventana))

# ? BACKGROUND/ RECT
background = pygame.image.load(os.path.dirname(os.path.abspath(__file__))+"\\Background\Fondo.png").convert_alpha()
background = pygame.transform.scale(background,(800,600))

# ? SPRITE ROCA/ RECT
roca = pygame.image.load(os.path.dirname(os.path.abspath(__file__))+"\\Sprites/roca.png").convert_alpha()
roca = pygame.transform.scale(roca,(45,45))
rocarect = roca.get_rect()

# ? SPRITE ARAÑA/ RECT
araña = pygame.image.load(os.path.dirname(os.path.abspath(__file__))+"\\Sprites/ArañitaFinal.png").convert_alpha()
araña = pygame.transform.scale(araña,(40,40))
arañarect = araña.get_rect()
arañarect.update(170,55,35,35)

# * OBSTACULOS
obstaculo_pos=[(random.randint(2,9)*50+160),(random.randint(2,9)*50+90)]
obstaculo2_pos=[(random.randint(2,9)*50+160),(random.randint(2,9)*50+90)]
obstaculo3_pos=[(random.randint(2,9)*50+160),(random.randint(2,9)*50+90)]


run=True
while run:
    # ? IMPRIME LAS ROCAS Y FUTURAMENTE LOS OBSTACULOS
    for i in range(10):
        for j in range(10):
            for c in range(2):
                x = tablero[i][j][0]
                y = tablero[i][j][1]
                background.blit(roca,[x,y])

    ventana.fill((132,130,128))

    # ? Obstaculos
    pygame.draw.rect(ventana,rojo,(obstaculo_pos,cube_size))
    pygame.draw.rect(ventana,rojo,(obstaculo2_pos,cube_size))
    pygame.draw.rect(ventana,rojo,((obstaculo2_pos[0],obstaculo2_pos[1]+50),cube_size))
    pygame.draw.rect(ventana,rojo,(obstaculo3_pos,cube_size))
    pygame.draw.rect(ventana,rojo,((obstaculo3_pos[0],obstaculo3_pos[1]-50),cube_size))
    pygame.draw.rect(ventana,rojo,((obstaculo3_pos[0]-50,obstaculo3_pos[1]),cube_size))
    
    # ? SALIR DEL JUEGO
    for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False
            # * DETECTA MOVIMIENTO Y RESTRINGE MOVIMIENTO
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    run = False
                tecla_presionada = pygame.key.name(event.key)

                if arañarect.left < 210 :
                    arañarect = arañarect.move(0,0)
                else:
                    if tecla_presionada == "a":
                        arañarect = arañarect.move(-xAraña,0)
                    
                if arañarect.top < 90:
                    arañarect = arañarect.move(0,0)    
                else:
                    if tecla_presionada == "w":
                        arañarect = arañarect.move(0,-yAraña)

                if arañarect.bottom > 490:
                    arañarect = arañarect.move(0,0)
                else:
                    if tecla_presionada == "s":
                        arañarect = arañarect.move(0,yAraña)

                if arañarect.right > 610:
                    arañarect = arañarect.move(0,0)
                else:
                    if tecla_presionada == "d":
                        arañarect = arañarect.move(xAraña,0)
    ventana.blit(background,[0,0])
    ventana.blit(araña,arañarect)
    pygame.display.flip()