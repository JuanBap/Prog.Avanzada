//Imports que usamos para métodos
import java.time.LocalDateTime;
import java.time.ZoneId;
import java.time.format.DateTimeFormatter;
import java.util.Date;
import java.text.SimpleDateFormat;

//Clase Celular que hereda de la clase abstracta ProductoElectronico

public class Celular extends ProductoElectronico {

    //Atributos propios de la clase celular

    private String marca;
    private String procesador;
    private int megapixeles;
    private long numero;


    //Método constructor de la clase celular

    public Celular (String nombre, double precio, int garantia, String marca, String procesador, int megapixeles, long numero){

        super(nombre, precio, garantia);
        this.marca = marca;
        this.procesador = procesador;
        this.megapixeles = megapixeles;
        this.numero = numero;


    }

    //Métodos propios de la clase Celular

    public void setMarca(String marca){

        this.marca = marca;

    }

    public String getMarca(){

        return this.marca;

    }

    public void setProcesador(String procesador){

        this.procesador = procesador;

    }

    public String getProcesador(){

        return this.procesador;

    }

    public void setMegapixeles(int megapixeles){

        this.megapixeles = megapixeles;

    }

    public int getMegapixeles(){

        return this.megapixeles;

    }

    public void setNumero(long numero){

        this.numero = numero;

    }

    public long getNumero(){

        return this.numero;

    }

    //Sobrescritura del método
    @Override
    public void cargar(int carga){

        //Recibe un porcentaje de batería y hace el cálculo de cuanto falta

        double porcentajeRestante = 100 - carga;

        //Si cargar al 100% se demora 2 horas, cargar un N porcentaje se demorará
        //Calculándose por medio de regla de 3

        //100% ---> 2 horas
        //N%   ---> x horas, entonces x = N * 2 / 100

        double tiempo = porcentajeRestante * 2 / 100;

        System.out.println("\n\nLa carga actual del dispositivo  "+ super.getNombre() +" es de: "+ carga + "%");
        System.out.println("Para que llegue al 100% requiere un "+porcentajeRestante+"%"+" adicional");
        System.out.println("Necesitará cargarse por: "+ tiempo+" horas");

    }

    //Métodos adicionales EXTRAS
    public void imprimirInformacion() {

        // Imprime la información detallada del celular

        System.out.println("MOSTRANDO INFORMACIÓN DETALLADA DEL CELULAR");
        System.out.println("Nombre: " + getNombre());
        System.out.println("Precio: " + getPrecio());
        System.out.println("Garantía: " + getGarantia());
        System.out.println("Marca: " + getMarca());
        System.out.println("Procesador: " + getProcesador());
        System.out.println("Megapíxeles de la cámara: " + getMegapixeles());

        if (getNumero() != 0) {
            System.out.println("Número de teléfono: " + getNumero());
        }
    }


    public void calculadora(double numA, double numB, String operacion) {

        // Realiza operaciones de una calculadora básica e imprime el resultado

        double resultado = 0.0;

        switch (operacion) {
            case "+":
                resultado = numA + numB;
                break;
            case "-":
                resultado = numA - numB;
                break;
            case "*":
                resultado = numA * numB;
                break;
            case "/":
                if (numB != 0) {
                    resultado = numA / numB;
                } else {
                    System.out.println("Error: división entre cero no permitida");
                    return; // Sale del método si hay una división entre cero
                }
                break;
            default:
                System.out.println("Error: operación no válida");
                return; // Sale del método si la operación no es válida
        }
        System.out.println("Método calculadora en "+super.getNombre());
        System.out.println("El resultado de la operacion: "+ numA + operacion + numB + " es: "+ resultado);
    }


    public void fechaDeHoy() {

        //Obtenemos fecha actual
        LocalDateTime fechaHoy = LocalDateTime.now();

        //Obtenemos zona horaria de Bogotá, Colombia
        ZoneId zonaBogota = ZoneId.of("America/Bogota");

        //Convertimos la fecha actual a la zona horaria de Bogotá
        LocalDateTime fechaBogota = fechaHoy.atZone(zonaBogota).toLocalDateTime();

        //Asignamos formato a las fechas
        DateTimeFormatter formatoFecha = DateTimeFormatter.ofPattern("dd/MM/yyyy");
        DateTimeFormatter formatoHora = DateTimeFormatter.ofPattern("HH:mm:ss");

        //Obtener las cadenas formateadas de fecha y hora
        String fechaString = fechaBogota.format(formatoFecha);
        String horaString = fechaBogota.format(formatoHora);

        //Imprimir la fecha y hora actual en Bogotá, Colombia
        System.out.println("El celular "+ super.getNombre()+" muestra la siguiente información");
        System.out.println("La fecha de hoy en Bogotá, Colombia es: " + fechaString);
        System.out.println("La hora actual en Bogotá, Colombia es: " + horaString);
    }

    public void aplicaParaDescuento(){

        //Variable para calcular el precio final
        double precioFinal;

        if(super.getPrecio()>=1600){

            precioFinal= super.getPrecio()-(super.getPrecio()*0.2);

            System.out.println("El celular "+super.getNombre()+" aplica para un descuento del 20 %, es decir el precio es de: "+precioFinal + " USD.");

        }
        if(super.getPrecio()<1600 && super.getPrecio()>=950){

            precioFinal= super.getPrecio()-(super.getPrecio()*0.1);

            System.out.println("El celular "+super.getNombre()+" aplica para un descuento del 10 %, es decir el precio es de: "+precioFinal + " USD.");

        }
        else{
            System.out.println("El celular "+super.getNombre()+ " no aplica para descuento, ya es muy barata");
        }
    }

    public void cuantaGarantia(){

        float garantia = super.getGarantia()/12;

        System.out.println("El celular " +super.getNombre()+ " tiene una garantía de " + garantia +" años.");

    }
    public void informacionRelevante(){

        System.out.println("El celular "+super.getNombre()+" tiene "+ megapixeles + " Megapixeles" );

    }





}



