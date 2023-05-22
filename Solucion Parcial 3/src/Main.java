/* Autor: Juan Pablo Cañón Contreras
   Fecha: 22/05/2023

   En el siguiente programa se realiza la solución al enunciado de la propuesta del parcial para el tercer corte
   de programación avanzada en la Pontificia Universidad Javeriana para el primer semestre del 2023.
 */

import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {

        //Lo usamos para decir "presione enter para continuar"
        Scanner leer = new Scanner(System.in);

        //Lo usamos para recibir el enter
        String enter;

        //5. Crear objeto de la clase AnalizadorDeDatos
        AnalizadorDeDatos analizador = new AnalizadorDeDatos();


        //Objetos que se requieren para probar el programa:
        /*  #1. Objeto de clase ConjuntoDeDatosTabular
            Nombre: Datos de estudiantes
            Tamaño: 1000
            Tipo: Tabular
            Columnas: 5
            Filas: 200                                   */

        //Instanciamos el primer objeto con esos datos y los agregamos al método constructor
        ConjuntoDeDatosTabular datosEstudiantes = new ConjuntoDeDatosTabular("Datos de estudiantes", 1000, 5,2000);


        /*  #2. Objeto de clase ConjuntoDeDatosImagen
            Nombre: Imágenes de satélite
            Tamaño: 2000
            Tipo: Imagen
            Resolución Horizontal: 1080
            Resolución Vertical: 720                     */
        //Instanciamos el segundo objeto con esos datos y los agregamos al método constructor
        ConjuntoDeDatosImagen datosSatelite = new ConjuntoDeDatosImagen("Imágenes de satélite",2000,1080, 720  );


        /*  #3. Objeto repetido de clase ConjuntoDeDatosImagen
            Nombre: Imágenes de satélite
            Tamaño: 2000
            Tipo: Imagen
            Resolución Horizontal: 1080
            Resolución Vertical: 720                     */
        //Instanciamos el segundo objeto con esos datos y los agregamos al método constructor
        ConjuntoDeDatosImagen datosSatelite2 = new ConjuntoDeDatosImagen("Imágenes de satélite",2000,1080, 720  );


        //Añadir los conjuntos de datos al analizador
        analizador.anhadirConjuntoDeDatos(datosEstudiantes);
        analizador.anhadirConjuntoDeDatos(datosSatelite);
        analizador.anhadirConjuntoDeDatos(datosSatelite2);

        //Obtener las descripciones de los conjuntos de datos
        ArrayList<String> descripciones = analizador.describirConjuntosDeDatos();

        //Imprimimos las descripciones en pantalla con el duplicado
        for (String emp : descripciones) {

            System.out.println(emp);
            System.out.println("------------------------------");

        }

        //Lo usamos para evidenciar el cambio en la lista de datos
        System.out.println("Presione enter para eliminar el elemento duplicado");
        enter = leer.nextLine();

        //Eliminar uno de los conjuntos de datos duplicados
        analizador.eliminarConjuntoDeDatos("Imágenes de satélite");

        // Obtener las descripciones actualizadas después de la eliminación
        ArrayList<String> descripcionesActualizadas = analizador.describirConjuntosDeDatos();

        // Imprimir las descripciones en pantalla
        for (String emp2 : descripcionesActualizadas) {

            System.out.println(emp2);
            System.out.println("------------------------------");

        }

        System.out.println("Solución a la propuesta del parcial por Juan Pablo Cañón Contreras");
    }
}