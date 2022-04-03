package actividad2;

import java.util.ArrayList;

public class DiezPrimosCercanos {

	public static boolean esPrimo(int num) {
		for(int i=2; i<num;i++){
			if(num%i==0) {
				return false;
			}
		}
		return true;
	}
	
	public static void main(String[] args) {
		ArrayList<String> entrada = 
				AccesoArchivosArrayList.leerArchivo("./data/entrada.txt");
		for(String s : entrada) {
			String strNum = s.substring(0,s.indexOf(" "));//RECORTA EL "N" DE LA LINEA COMO STRING
			int N = Integer.parseInt(strNum);// TRANSFORMA EL "N" A INT 
			String strC = s.substring(s.indexOf(" ")+1,s.length());//RECORTA EL "P" DE LA LINEA COMO STRING
			int P = Integer.parseInt(strC);//TRANSFORMA EL "P" A INT
			
			if(N<1 || P<1 || P>10000) { //COMPRUEBA SI LOS NUMEROS ESTAN BIEN
				System.out.println("ERROR: Los numeros no cumplen con lo indicado");
				break;
			}
			
			//COMPROBACION DE "N"
			int c=0;
			if(esPrimo(N)) {
				c += 1;
				//AQUI FALTA CREAR UNA LINEA EN EL ARCHIVO DE SALIDA
			}
			/*while(c<P){
			
				//CREARA PRIMERA LINEA DEL ARCHIVO
			}*/
			
			//ArrayList<String> numPrim;
			//AccesoArchivosArrayList.escribirArchivo("./data/salida.txt",numPrim);
			
		}

	}

}
