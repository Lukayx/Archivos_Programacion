package cl.uach.info090.archivos;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
/**
 * Esta Clase contiene metodos para leer y escribir archivos de texto 
 * 
 * @author JG
 *
 */
public class AccesoArchivo {
	
	/**
	 * Lee el archivo especificado (ruta) y devuelve un arreglo de String conteniendo las 
	 * lineas del archivo, una linea en cada posicion del arreglo, en el orden en que fueron
	 * leidas.
	 *  
	 * @param ruta la rtua relativa o absoluta incluyendo el nombre del archivo
	 * @return
	 */
	public static String[] leerArchivo(String ruta){
		String[] lineas = new String[1000];
		int c = 0;
		FileReader fr;
		BufferedReader br;
		try{
			fr = new FileReader(ruta);
			br = new BufferedReader(fr);
			String line = "";
			while((line = br.readLine()) != null){
				if(line.length()>0)
					lineas[c++] = line.trim().toUpperCase();
			}
			br.close();
			fr.close();
		}catch(Exception e){
			e.printStackTrace();
		}
		String[] resultado = new String[c];
		for(int i=0;i<c;i++) {
			resultado[i] = lineas[i];
		}
		return resultado;
	}
	
	/**
	 * Crea o sobreescribe el archivo indicado por ruta con el contenido de arreglo lineas
	 * 
	 * @param ruta la ruta incluyendo el nombre del archivo a escribir
	 * @param lineas un arreglo con las lineas de texto que se escribiran en el archivo
	 */
	public static void escribirArchivo(String ruta, String[] lineas) {
		FileWriter fw;
		BufferedWriter bw;
		try{
			fw = new FileWriter(ruta);
			bw = new BufferedWriter(fw);
			for(int i = 0; i < lineas.length; i++) {
				bw.write(lineas[i]);
				if(i<lineas.length-1) bw.newLine();
			}
			bw.close();
			fw.close();
		}catch(Exception e){
			e.printStackTrace();
		}
	}
}
