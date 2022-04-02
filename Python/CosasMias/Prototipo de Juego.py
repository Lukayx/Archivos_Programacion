def validar_invitacion(resp):
    
    if resp == "Acepto" or resp == "acepto":
        return "SI"
    else:
        if resp == "No puedo ahora" or resp == "no puedo ahora":
            return "NO" 
        else:
            while(resp != "Acepto" or resp != "acepto" or resp != "No puedo ahora" or resp != "no puedo ahora"):
                print()
                resp = str(input("Ingrese 'Acepto' para Aceptar la invitación o 'No puedo ahora' para Rechazarla: "))
                
                if resp == "Acepto" or resp == "acepto":
                    return "SI"
                else :
                    if resp == "No puedo ahora" or resp == "no puedo ahora":
                        return "NO"
#|___--------------------------------___|Inicio de juego|___--------------------------------___|#

print("Mucho gusto! Queria invitarlo a exteminar unos goblins ¿Que le parece?")
print()

respuesta = str(input("Ingrese 'Acepto' para Aceptar la invitación o 'No puedo ahora' para Rechazarla: "))

resp_invitacion = validar_invitacion(respuesta)

if(resp_invitacion == "SI"):
    print("Genial! :")
else:
    print("Esta bien :c")