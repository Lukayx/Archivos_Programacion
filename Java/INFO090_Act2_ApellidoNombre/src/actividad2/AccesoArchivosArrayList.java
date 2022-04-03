package actividad2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
/**
 * Esta Clase contiene metodos para leer y escribir archivos de texto 
 * 
 * @author JG
 *
 */
public class AccesoArchivosArrayList {
	
	/**
	 * Lee el archivo especificado (ruta) y devuelve un arreglo de String conteniendo las 
	 * lineas del archivo, una linea en cada posicion del arreglo, en el orden en que fueron
	 * leidas.
	 *  
	 * @param ruta la ruta relativa o absoluta incluyendo el nombre del archivo
	 * @return
	 */
	public static ArrayList<String> leerArchivo(String ruta){
		ArrayList<String> lineas = new ArrayList<String>();
		
		FileReader fr;
		BufferedReader br;
		try{
			fr = new FileReader(ruta);
			br = new BufferedReader(fr);
			String line = "";
			while((line = br.readLine()) != null){
				lineas.add(line);
			}
			br.close();
			fr.close();
		}catch(Exception e){
			e.printStackTrace();
		}
		
		return lineas;
	}
	
	/**
	 * Crea o sobreescribe el archivo indicado por ruta con el contenido de arreglo lineas
	 * 
	 * @param ruta la ruta incluyendo el nombre del archivo a escribir
	 * @param lineas un arreglo con las lineas de texto que se escribiran en el archivo
	 */
	public static void escribirArchivo(String ruta, ArrayList<String> lineas) {
		FileWriter fw;
		BufferedWriter bw;
		try{
			fw = new FileWriter(ruta);
			bw = new BufferedWriter(fw);
			for(int i = 0; i < lineas.size(); i++) {
				bw.write(lineas.get(i));
				if(i<lineas.size()-1) bw.newLine();
			}
			bw.close();
			fw.close();
		}catch(Exception e){
			e.printStackTrace();
		}
	}
}
