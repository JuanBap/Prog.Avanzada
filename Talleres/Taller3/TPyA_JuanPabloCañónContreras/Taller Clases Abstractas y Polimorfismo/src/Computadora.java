//Clase Computadora que hereda de la clase abstracta ProductoElectronico

public class Computadora extends ProductoElectronico {

    //Atributos propios de la clase computadora
    private int memoriaGrafica;
    private double pulgadasPantalla;
    private double frecuenciaProcesador;
    private int memoriaRAM;

    //Método constructor de la clase computadora

    public Computadora(String nombre, double precio, int garantia, int memoriaGrafica, double pulgadasPantalla, double frecuenciaProcesador, int memoriaRAM) {
        super(nombre, precio, garantia);
        this.memoriaGrafica = memoriaGrafica;
        this.pulgadasPantalla = pulgadasPantalla;
        this.frecuenciaProcesador = frecuenciaProcesador;
        this.memoriaRAM = memoriaRAM;
    }

    public int getMemoriaGrafica() {

        return this.memoriaGrafica;

    }

    public void setMemoriaGrafica(int memoriaGrafica) {

        this.memoriaGrafica = memoriaGrafica;

    }

    public double getPulgadasPantalla() {

        return this.pulgadasPantalla;

    }

    public void setPulgadasPantalla(double pulgadasPantalla) {

        this.pulgadasPantalla = pulgadasPantalla;

    }

    public double getFrecuenciaProcesador() {

        return this.frecuenciaProcesador;

    }

    public void setFrecuenciaProcesador(double frecuenciaProcesador) {

        this.frecuenciaProcesador = frecuenciaProcesador;

    }

    public int getMemoriaRAM() {

        return this.memoriaRAM;

    }

    public void setMemoriaRAM(int memoriaRAM) {

        this.memoriaRAM = memoriaRAM;

    }

    //Sobrescritura del método
    @Override
    public void cargar(int carga){

        //Recibe un porcentaje de batería y hace el cálculo de cuanto falta

        double porcentajeRestante = 100 - carga;

        //Si cargar al 100% se demora 4 horas, cargar un N porcentaje se demorará
        //Calculándose por medio de regla de 3

        //100% ---> 2 horas
        //N%   ---> x horas, entonces x = N * 4 / 100

        double tiempo = porcentajeRestante * 4 / 100;

        System.out.println("\n\nLa carga actual del dispositivo  "+ super.getNombre() +" es de: "+ carga + "%");
        System.out.println("Para que llegue al 100% requiere un "+porcentajeRestante+"%"+" adicional");
        System.out.println("Necesitará cargarse por: "+ tiempo+" horas");

    }

    //Métodos propios de la clase computadora
    public void rendimiento() {

        double rendimiento = (memoriaRAM * memoriaGrafica * frecuenciaProcesador);

        if (rendimiento >= 1000) {

            System.out.println("La computadora" + super.getNombre() +" tiene un excelente rendimiento");

        } else if (rendimiento<1000 && rendimiento >= 800) {

            System.out.println("La computadora" + super.getNombre() +" tiene un buen rendimiento");

        } else if (rendimiento<800 && rendimiento >= 500) {

            System.out.println("La computadora" + super.getNombre() +" tiene un rendimiento aceptable");

        } else {

            System.out.println("La computadora" + super.getNombre() + "tiene un rendimiento bajo");

        }

    }


    public void cumpleRequisitosMinimos() {

        int requisitosMinimosMemoriaRAM = 8; //Requisitos mínimos de memoria RAM en GB

        int requisitosMinimosMemoriaGrafica = 2; //Requisitos mínimos de memoria gráfica en GB

        double requisitosMinimosFrecuenciaProcesador = 2.0; //Requisitos mínimos de frecuencia del procesador en GHz

        if (memoriaRAM >= requisitosMinimosMemoriaRAM && memoriaGrafica >= requisitosMinimosMemoriaGrafica && frecuenciaProcesador >= requisitosMinimosFrecuenciaProcesador) {
            System.out.println("\n");
            System.out.println("La computadora "+ super.getNombre() +" cumple con los requisitos mínimos.");


        } else {
            System.out.println("\n");
            System.out.println("La computadora "+super.getNombre()+" no cumple con los requisitos mínimos.");

        }


    }

    public void determinarTamañoPantalla() {

        double tamanoMedianoPantalla = 12.2; //Tamaño mediano de pantalla en pulgadas
        double tamanoGrandePantalla = 15.6; //Tamaño máximo de pantalla en pulgadas

        if (pulgadasPantalla < tamanoMedianoPantalla) {

            System.out.println("La pantalla de la computadora "+ super.getNombre()+" es pequeña.");

        } else if (pulgadasPantalla <= tamanoGrandePantalla) {

            System.out.println("La pantalla de la computadora "+ super.getNombre()+" es mediana.");

        } else {

            System.out.println("La pantalla de la computadora "+ super.getNombre()+" es grande.");

        }


    }

    //Métodos propios con igual nombre
    public void aplicaParaDescuento(){

        //Variable para calcular el precio final
        double precioFinal;

        if(super.getPrecio()>=1600){

            precioFinal= super.getPrecio()-(super.getPrecio()*0.2);

            System.out.println("La computadora "+super.getNombre()+" aplica para un descuento del 20 %, es decir el precio es de: "+precioFinal + " USD.");

        }
        if(super.getPrecio()<1600 && super.getPrecio()>=950){

            precioFinal= super.getPrecio()-(super.getPrecio()*0.1);

            System.out.println("La computadora "+super.getNombre()+" aplica para un descuento del 10 %, es decir el precio es de: "+precioFinal + " USD.");

        }
        else{
            System.out.println("La computadora "+super.getNombre()+ " no aplica para descuento, ya es muy barata");
        }
    }

    public void cuantaGarantia(){

        float garantia = super.getGarantia()/6;

        System.out.println("El computador " +super.getNombre()+ " tiene una garantía de " + garantia +" semestres.");

    }
    public void informacionRelevante(){
        System.out.println("La computadora "+super.getNombre()+" tiene un procesador de una frecuencia de "+ frecuenciaProcesador);
    }


}