from dotenv import load_dotenv
import os
import time 
import schedule

load_dotenv()

TIEMPO_ENV = os.getenv("TIEMPO_EN_MINUTOS")
MENSAJE_ENV = os.getenv("MENSAJE")

def Tarea():
    print(MENSAJE_ENV)

schedule.every(int(TIEMPO_ENV)).minutes.do(Tarea)

while True:
    schedule.run_pending()
    time.sleep(1)