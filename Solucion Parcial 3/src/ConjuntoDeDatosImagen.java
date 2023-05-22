//3. Clase ConjuntoDeDatosImagen
public class ConjuntoDeDatosImagen extends ConjuntoDeDatos{

    //Atributos
    private int ancho;
    private int alto;

    //Método constructor
    public ConjuntoDeDatosImagen(String nombre, int tamanho, int ancho, int alto){

        super(nombre,tamanho);
        this.ancho = ancho;
        this.alto = alto;

    }

    public ConjuntoDeDatosImagen() {
        super();
    }

    //Sobrescritura del método abstracto describir
    @Override
    public String describir() {

        return "Nombre: " + nombre + "\n" + "Tamaño: " + tamanho + "\n" +
                "Tipo: Imagen" + "\n" + "Resolución Horizontal: " + ancho + "\n" + "Resolución Vertical: " + alto;

    }

}
