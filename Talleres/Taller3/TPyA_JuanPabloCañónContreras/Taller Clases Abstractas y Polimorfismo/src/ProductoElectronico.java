//Clase abstracta Producto Electrónico
public abstract class ProductoElectronico {

	//Atributos de la clase ProductoElectronico
		
	private String nombre;
	private double precio;
	private int garantia;

	//Método constructor de la clase ProductoElectronico
		
	public ProductoElectronico (String nombre, double precio, int garantia){

		this.nombre = nombre;
		this.precio = precio;
		this.garantia = garantia;
			
	}
			
	//Métodos de la clase ProductoElectronico
		
	public String getNombre(){
		
		return this.nombre;
	
	}

	public void setNombre(String nombre){

		this.nombre = nombre;

	}
		
	public double getPrecio(){
			
		return this.precio;
			
	}
		
	public void setPrecio(double precio){

		this.precio = precio;

	}

	public int getGarantia(){
			
		return this.garantia;
			
	}

	public void setGarantia(int garantia){

		this.garantia = garantia;

	}

	//Método abstracto cargar
	public abstract void cargar(int carga);

		
}