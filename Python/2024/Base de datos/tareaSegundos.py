from dotenv import load_dotenv
import os
import time 
import sched

load_dotenv()

TIEMPO_ENV = os.getenv("TIEMPO_EN_SEGUNDOS")
MENSAJE_ENV = os.getenv("MENSAJE")

def Tarea():
    print(MENSAJE_ENV)

scheduler = sched.scheduler(time.time, time.sleep)

def programar_tarea(intervalo):
    scheduler.enter(intervalo, 1, programar_tarea, (intervalo,))
    Tarea()

# Iniciar la primera ejecución de la tarea
programar_tarea(int(TIEMPO_ENV))

# Ejecutar el scheduler
scheduler.run()