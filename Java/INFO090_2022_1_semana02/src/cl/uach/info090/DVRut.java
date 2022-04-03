package cl.uach.info090;

import javax.swing.JOptionPane;


public class DVRut {

/**
 * 1. pedir al usuario el rut
 * 2. calcular el digito verificador (DV)
 * 3. informar al usuariodel DV
 * @param args no los estamos usando por ahora!
 */
	public static void main(String[] args) {
		String rut = JOptionPane.showInputDialog(
				"Ingresa tu rut, sin puntos ni dígito verificador");
		char dv = calculaDV(rut);
		JOptionPane.showMessageDialog(null, rut+"-"+dv);
		
	} 
	
	public static char calculaDV(String rut){
		int sum = 0;
		for(int i = rut.length()-1;i>=0;i--){
			char digito = rut.charAt(i);
			int num = digito - '0';
			int factor = rut.length() - 1 - i;
			factor = (factor % 6) + 2; // 2 3 4 5 6 7 2 3 4 5 6 7 2 3 4 
			sum += num*factor;
		}
		int resto = sum % 11;
		int dv = 11-resto;
		if(dv == 11) {
			return '0';
		}else{
			if(dv == 10) {
				return 'K';
			}else{
				return (char) (dv + '0');
			}
		}
		
	}

}
