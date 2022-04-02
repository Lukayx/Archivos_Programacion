import pygame,sys,random

xventana = 800
yventana = 600
rojo = (255,0,0)
verde = (0,255,0)
azul =(0,0,255)
negro = (0,0,0)
size=50

#Player
player_pos = [10,10]
player_size = [50,50]

#Enemigo
enemy_size = [50,50]
enemy_pos = [random.randint(0,xventana-size),0]

#vetana
ventana = pygame.display.set_mode((xventana,yventana))

#Colision
def detectar_colision(player_pos,enemy_pos):
    px = player_pos[0]
    py = player_pos[1]
    ex = enemy_pos[0]
    ey = enemy_pos[1]

    if (ex>=px and ex <(px+size)) or (px>=ex and px <(ex+size)):
        if (ey>=py and ey <(py+size)) or (py>=ey and py <(ey+size)):
            return True
    return False

#Ejecucion
clock=pygame.time.Clock()
run=True
while run:
    for event in pygame.event.get():

        #Evento Salir
        if event.type == pygame.QUIT:
            sys.exit()

        #Evento Tecla
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                print("Izquierda")
                player_pos[0]-=50
            if event.key == pygame.K_RIGHT:
                print("Derecha")
                player_pos[0]+=50
            if event.key == pygame.K_UP:
                print("Arriba")
                player_pos[1]-=50
            if event.key == pygame.K_DOWN:
                print("abajo")
                player_pos[1]+=50

    #Caida enemigo
    if enemy_pos[1]>= 0 and enemy_pos[1]<yventana:
        enemy_pos[1] +=20
    else:
        enemy_pos[0]= random.randint(0,xventana-size)
        enemy_pos[1]=0

    #Colision
    if detectar_colision(player_pos,enemy_pos):
        run=False

    #Limpiar pantalla
    ventana.fill(negro)

    #Dibujar jugador
    pygame.draw.rect(ventana,rojo ,(player_pos,player_size))

    #Dibujar enemigo
    pygame.draw.rect(ventana,azul,(enemy_pos,enemy_size))

    #Actualizar pantalla
    clock.tick(20)
    pygame.display.flip()
    
