package cl.uach.info0909.semana03;

	/*public class Guitar{
		String color;
		int nStrings; // si fuera "static" se aplicaría a todas las variables
		boolean hasWhammyBar;
	}*/

public class Car {
	private final double MILES_PER_GALLON = 10;
	private final double TANK_CAPACITY = 100;
	private double miles = 0.0;
	private double gas = 0.0;
	
	public void putGas(double gallons) {
		if((gas+gallons)<=TANK_CAPACITY) {
			gas = gas + gallons;
		} else {
			gas = TANK_CAPACITY;
		}
	}
	public void drive(double miles) {
		this.miles = miles;
		if(miles < 0) return;
		if(miles > gas*MILES_PER_GALLON) {
				gas=0;
				this.miles += gas*MILES_PER_GALLON;
		} else {
			this.miles += miles;
			gas -= miles/MILES_PER_GALLON;
		}
	}

	public double getGas() {return gas;}
	public double getMiles() {return miles;	}
	/*
	private static String brand = "Testarossa";
	private String color;
	private String licensePlate;
	private double mileage;
	*/
	
	/*
	public String getBrand(){
		return brand;
	}
	public String getColor(){
		return color;
	}	
	public String getLicensePlate(){
		return licensePlate;
	}
	public double getMileage(){
		return mileage;
	}
	public void setColor(String x) {
		color = x;
	}	
	public void setLicensePlate(String x) {
		licensePlate = x;
	}	
	public void setMileage(double x) {
		mileage = x;
	}
	*/
}	
