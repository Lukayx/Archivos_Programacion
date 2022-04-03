package cl.uach.info090;

import java.util.ArrayList;

import cl.uach.info090.archivos.AccesoArchivosArrayList;

public class AccesoArchivosArray {

	public static void main(String[] args) {
		ArrayList<String> vAgencia1 =
				AccesoArchivosArrayList.leerArchivo("./data/victimas_agencia1.txt");
	//	ArrayList<String> vAgencia2 =
				AccesoArchivosArrayList.leerArchivo("./data/victimas_agencia2.txt");
		
		ArrayList<String> mujeres = new ArrayList<String>();
	//	ArrayList<String> hombres = new ArrayList<String>();
		
		for(String s : vAgencia1) {
			if(s.charAt(0) == 'M' || s.charAt(0) == 'm') {
/*				boolean existe = false;
				for(String m : mujeres) {
					if(m.equalsIgnoreCase(s)) existe = true;
	*/			}
				if(!mujeres.contains(s)) mujeres.add(s);
				//if(!existe) mujeres.add(s);
			}
		}
	}
