package cl.uach.info090.archivos;

import java.util.ArrayList;

public class EjemploArchivo {

	public static void main(String[] args) {
		ArrayList<String> vic1 = AccesoArchivosArrayList.leerArchivo("data/victimas_agencia1.txt");
		for(String s: vic1) {
			System.out.println(s);
		}
		AccesoArchivosArrayList.escribirArchivo("data/salida.txt", vic1);
	}

}
