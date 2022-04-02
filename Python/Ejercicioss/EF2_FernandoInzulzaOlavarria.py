def texto():
    txt1 = str(input('Ingrese el primer texto: '))
    txt1 = txt1.replace(' ', "")
    while txt1.isalnum() == False:  
        print ('  ERROR: sólo se  permiten textos con caracteres alfabéticos y espacio')
        txt1 = str(input('Ingrese el primer texto: '))
        txt1 = txt1.replace(' ', "")

    txt2 = str(input('Ingrese el segundo texto: '))
    txt2 = txt2.replace(' ', "")
    while txt2.isalnum() == False: 
        print ('  ERROR: sólo se permiten textos con caracteres alfabéticos y espacio')
        txt2 = str(input('Ingrese el segundo texto: '))
        txt2 = txt2.replace(' ', "")

    return txt1,txt2

def anagrama(txt1,txt2):            
    txt1 = txt1.lower()              
    txt2 = txt2.lower()
    for i in txt1:           #1 = lana 2 anal
        if txt1.count(i) != txt2.count(i):
            print (f"txt1 ={txt1.count(i)} txt2 = { txt2.count(i)}")
            return False
    return True


def main():
    txt1,txt2 = texto()
    veracidad = anagrama(txt1,txt2)
    if veracidad == True :
        print ("Son anagramas")
    else:
        print("no son")

main()