//2. Clase ConjuntoDeDatosTabular
public class ConjuntoDeDatosTabular extends ConjuntoDeDatos {

    //Atributos
    private int numeroDeColumnas;
    private int numeroDeFilas;

    //Método constructor
    public ConjuntoDeDatosTabular(String nombre, int tamanho, int numeroDeColumnas, int numeroDeFilas) {

        super(nombre, tamanho);
        this.numeroDeColumnas = numeroDeColumnas;
        this.numeroDeFilas = numeroDeFilas;

    }

    public ConjuntoDeDatosTabular() {

    }

    //Sobrescritura del método abstracto describir
    @Override
    String describir() {

        return "Nombre: " + nombre + "\n" + "Tamaño: " + tamanho + "\n" +
               "Tipo: Tabular" + "\n" + "Filas: " + numeroDeFilas + "\n" +
               "Columnas: " + numeroDeColumnas;

    }


}
