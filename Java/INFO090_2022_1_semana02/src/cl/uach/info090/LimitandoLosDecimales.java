package cl.uach.info090;

import java.text.DecimalFormat;

public class LimitandoLosDecimales {
	/**
	 * Distintas formas de reondear decimales
	 * @param args
	 */
	public static void main(String[] args) {
		double d = 100.0 / 3;
		// Usando una clase externa de la API
		DecimalFormat df = new DecimalFormat("#.##");
		System.out.println(df.format(d));

		// el hack
		d = ((int)(d*100))/100.0;
		d = Math.round(d*100)/100.0;
		System.out.println(d);
				
	}

}
