//1. Clase ConjuntoDeDatos
public abstract class ConjuntoDeDatos {

    //Atributos
    String nombre;
    int tamanho;

    //Método constructor
    public ConjuntoDeDatos(String nombre, int tamanho){

        this.nombre = nombre;
        this.tamanho = tamanho;

    }

    //Método constructor vacío
    public ConjuntoDeDatos() {

    }

    //Método abstracto describir
    abstract String describir();

    //Lo usamos para comparar el nombre en el método eliminarConjuntoDeDatos
    public String getNombre() {

        return this.nombre;

    }
}
