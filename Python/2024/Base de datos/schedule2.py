from dotenv import load_dotenv
import time
import os

load_dotenv()

TIEMPO_ENV = int(os.getenv("TIEMPO"))
MENSAJE_ENV = os.getenv("MENSAJE")

while(True):
  time.sleep(TIEMPO_ENV)
  print(MENSAJE_ENV)