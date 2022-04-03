package cl.uach.info090;
import javax.swing.JOptionPane;

/*
 * Este programa funciona, pero hay mucho que hacer para hacerlo 
 * ROBUSTO y MODULAR (asi gritando!!!). Vamos a: 
 * - Revisar y corregir convenciones de nombre
 * - Usar constantes
 * - Poner parte de la funcionalidad en metodos
 * - Revisar condiciones de borde, posibles errores...
 */
public class TemperatureConversor {

	public static final double CONSTANTE_1 = 273.15;
	public static final double CONSTANTE_2 = 1.8;
	public static final double CONSTANTE_3 = 32;
	
	public static double c2F(double c) {
		return c * CONSTANTE_2 + CONSTANTE_3;
	}
	
	public static void main (String[] args) {
		double far;
		double cel;
		double kel;
		double temperatura;
		
		String temp = JOptionPane.showInputDialog("Ingrese una temperatura seguida por su unidad de medida ( C, F o K ): ");
		
		// Si es que hubiera un espacio entre el numero y la unidad de medida, lo elimino
		temp = temp.replace(" ", "");
		
		// separar la unidad de medida para reconocer qué conversiones hacer
		int l = temp.length()-1; 
		char m = temp.charAt(l);
		
		//Acomodar tipos de datos para trabajarlos.
		String unidad = String.valueOf(m); // paso el caracter m a string
		unidad = unidad.toUpperCase(); //  con esto sabemos que trabajaremos con mayus
		m = unidad.charAt(0); 	// y ahora trabajamos con un char en mayuscula.
		temp = temp.substring(0, l); // cadena correspondiente al valor de la temperatura
		
		temperatura = Double.parseDouble(temp);
		
		System.out.println(temp + " " + unidad + " =");
		if (m == 'C' ) {
			far = c2F(temperatura);
			kel = temperatura + CONSTANTE_1;
			System.out.println("    " + far + " F");
			System.out.println("    " + kel + " K");
		}
		else if (m == 'K') {
			cel = (temperatura - CONSTANTE_1);
			far = (cel * CONSTANTE_2) + CONSTANTE_3;
			System.out.println("    " + cel + " C");
			System.out.println("    " + far + " F");
		}
		else if (m == 'F') {
			cel = (temperatura - CONSTANTE_3) / CONSTANTE_2;
			kel = cel + CONSTANTE_1;
			System.out.println("    " + cel + " C");
			System.out.println("    " + kel + " K"); 	
		} 
					
	}
}