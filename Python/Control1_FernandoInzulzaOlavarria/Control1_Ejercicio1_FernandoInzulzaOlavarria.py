from random import *
def generaSecuencia(lmin,lmax):
    x=randint(lmin,lmax)
    secuencia = ""
    for i in range(x):
        l=randint(1,4)
        if l==1:
            secuencia+="A"
        else:
            if l==2:
                secuencia+="T"
            else:
                if l==3:
                    secuencia+="C"
                else:
                    if l==4:
                        secuencia+="G"
    return secuencia

def informaUnion(adn,cebador):
    coincidencia = 0
    for i in range(len(adn)-len(cebador)):
        a=0
        ok=0
        for j in cebador:
            if j == "C" and adn[i+a]=="G":
                ok+=1
                a+=1
            else:
                if j == "G" and adn[i+a]=="C":
                    ok+=1
                    a+=1
                else:
                    if j == "A" and adn[i+a]=="T":
                        ok+=1
                        a+=1
                    else:
                        if j == "T" and adn[i+a]=="A":
                            ok+=1
                            a+=1
                        else:
                            break
        if(ok==len(cebador)):
            coincidencia += 1
    return coincidencia

# C-G, G-C, A-T y T-A
def imprimeResultados(adn,cebador,ocurrencias):
    print(f"ADN: {adn}")
    print(f"Cebador: {cebador}")
    if(ocurrencias==1):
        G=cebador.count("G")
        C=cebador.count("C")
        A=cebador.count("A")
        T=cebador.count("T")
        Tm = 4*(G+C)+2*(A+T)
        print(f"El cebador es específico, con Tm = {Tm}°C")
    else:
        print("El cebador no es especifico")

def main():
    adn = generaSecuencia(20,40) # corrección: 30%
    ceb = generaSecuencia(2,4)
    res = informaUnion(adn,ceb) # corrección: 50%
    imprimeResultados(adn,ceb,res) # corrección: 20%
#
main()