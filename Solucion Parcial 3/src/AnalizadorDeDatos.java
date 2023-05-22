import java.util.ArrayList;
import java.util.Iterator;

//4. Clase AnalizadorDeDatos
public class AnalizadorDeDatos {

    private ArrayList<ConjuntoDeDatos> conjuntosDeDatos;

    //Método constructor
    public AnalizadorDeDatos (){

        //Atributos
       conjuntosDeDatos = new ArrayList<>();

    }


    //Método añadirConjuntoDeDatos
        //Recibe como argumento un objeto de la clase ConjuntoDeDatos
    public void anhadirConjuntoDeDatos(ConjuntoDeDatos objetoConjuntoDeDatos){

        conjuntosDeDatos.add(objetoConjuntoDeDatos);    //Añade el objeto a la lista

    }
    //Método eliminarConjuntoDeDatos
        //Recibe como argumento un objeto de clase ConjuntoDeDatos
    public void eliminarConjuntoDeDatos(String nombre){

        System.out.println("Entra al método");

        //Instanciamos un objeto iterador de la clase Iterator para que recorra la lista conjuntoDeDatos con el método iterator();
        Iterator<ConjuntoDeDatos> iterador = conjuntosDeDatos.iterator();

        //Mientras todavía haya un elemento en la lista la recorremos
        while (iterador.hasNext()) {

            //Se utiliza para obtener el siguiente elemento del iterador en el ciclo while
            ConjuntoDeDatos conjunto = iterador.next();

            //Preguntamos si los nombres coinciden
            if (conjunto.getNombre().equals(nombre)) {

                //Si esta condición se cumple eliminamos el elemento
                iterador.remove();

                //Finalizamos el ciclo y acaba el trabajo del método
                break;

            }
        }
    }

    public ArrayList<String> describirConjuntosDeDatos() {

        //Instanciamos un ArrayList para almacenar los strings del método describir
        ArrayList<String> descripcionDatos = new ArrayList<>();

        //Creamos una variable auxiliar para que reciba los datos de las descripciones
        String auxiliarDescripcion;

        //Recorremos la lista de conjuntoDeDatos para llamar lo que necesitamos de cada elemento
        for (ConjuntoDeDatos conjunto : conjuntosDeDatos) {

            //Obtenemos la descripción llamando al método describir y lo almacenamos en el auxiliar
            auxiliarDescripcion = conjunto.describir();

            //Añadimos el auxiliar al ArrayList que queremos retornar
            descripcionDatos.add(auxiliarDescripcion);
        }

        //Devolvemos el ArrayList con todas las descripciones de los datos
        return descripcionDatos;
    }


}
