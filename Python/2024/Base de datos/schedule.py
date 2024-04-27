from dotenv import load_dotenv
from crontab import CronTab
import os

load_dotenv()

TIEMPO_ENV = os.getenv("TIEMPO")
MENSAJE_ENV = os.getenv("MENSAJE")

cron = CronTab(user=True)

job = cron.new(command=f"echo {MENSAJE_ENV}")
job.minute.every(TIEMPO_ENV)

cron.write()

print(f"Este es el tiempo: {TIEMPO_ENV}s \nEste es el mensaje: {MENSAJE_ENV}")