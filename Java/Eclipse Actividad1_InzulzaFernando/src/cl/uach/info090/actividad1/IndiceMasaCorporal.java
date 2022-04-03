package cl.uach.info090.actividad1;

import javax.swing.JOptionPane;

public class IndiceMasaCorporal {

	public static void main(String[] args) {
		String kg_temp,h_temp;
		float kg, h, IMC;
		
		kg_temp = JOptionPane.showInputDialog("Ingrese su peso en kilogramos: ");
		h_temp =  JOptionPane.showInputDialog("Ingrese su altura en metros: ");
		kg_temp = kg_temp.replace(" ","");
		h_temp = h_temp.replace(" ","");
		
		h = Float.parseFloat(h_temp);
		kg = Float.parseFloat(kg_temp);
		
		IMC = kg/(h*h);
				
		if(IMC < 16.0) {
			JOptionPane.showMessageDialog(null,
					"Su IMC es "+ IMC +" y su estado es: Bajo de peso (Delgadez Severa)");
		} else if(16.0 <= IMC && IMC < 17) {
			JOptionPane.showMessageDialog(null,
					"Su IMC es "+ IMC +" y su estado es: Bajo de peso (Delgadez Moderada)");
		} else if(17.0 <= IMC && IMC < 18.5) {
			JOptionPane.showMessageDialog(null, 
					"Su IMC es "+ IMC +" y su estado es: Bajo de peso (Delgadez Leve)");
		} else if(18.5 <= IMC && IMC < 25) {
			JOptionPane.showMessageDialog(null, 
					"Su IMC es "+ IMC +" y su estado es: Rango Nomal");
		} else if(25.0 <= IMC && IMC < 30.0) {
			JOptionPane.showMessageDialog(null, 
					"Su IMC es "+ IMC +" y su estado es: Sobrepeso (Pre-Obesidad)");
		} else if(30.0 <= IMC && IMC < 35) {
			JOptionPane.showMessageDialog(null, 
					"Su IMC es "+ IMC +" y su estado es: Obesidad (Clase 1)");
		} else if(35.0 <= IMC && IMC < 40) {
			JOptionPane.showMessageDialog(null, 
					"Su IMC es "+ IMC +" y su estado es: Obesidad (Clase 2)");
		} else if(40.0 <= IMC) {
			JOptionPane.showMessageDialog(null, 
					"Su IMC es "+ IMC +" y su estado es: Obesidad (Clase 3)");
		}
	}

}
