package cl.uach.info0909.semana03;

public class Counter {
	private int value = 0;
	public int getValue() {
		return value;
	}
	public void click() {
		if(value<1000) {
			value = value + 1;
		} else {
			value = 0;	
		}
	}
	public void reset() {
		value = 0;
	}
}
