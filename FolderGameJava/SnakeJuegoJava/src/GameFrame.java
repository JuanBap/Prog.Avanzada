import javax.swing.JFrame;
/*	Import javax.swing.JFrame: es una biblioteca estándar de Swing, lo que permite a los programadores
	crear y manipular ventanas y marcos gráficos en sus aplicaciones */
import java.io.Serial;

//Inicio de la clase GameFrame que hereda de la clase JFrame
public class GameFrame extends JFrame{


	/*@Serial y la variable serialVersionUID se utilizan para indicar que una clase es
	 serializable y para asegurarse de que los objetos serializados y deserializados
	 sean compatibles en términos de versiones.  */

	@Serial
	private static final long serialVersionUID = 1L;

	//Método constructor de la ventana emergente:
	GameFrame() {
		GamePanel panel = new GamePanel();	//Instanciamos nuestro objeto panel de la clase GamePanel
		this.add(panel);					//Añadimos el panel a esta clase
		this.setTitle("Juego de Snake hecho en Java");	//Le damos el título al panel
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); //Significa que el programa se cerrará por completo cuando el usuario cierre la ventana
		this.setResizable(false); //Significa que el usuario no podrá cambiar el tamaño de la ventana
		this.pack(); //Ajusta el tamaño de la ventana de acuerdo con el tamaño preferido y los márgenes de su contenido
		this.setVisible(true); //Hace visible en la pantalla del usuario
		this.setLocationRelativeTo(null); //Establece la posición de la ventana en el centro de la pantalla
	}
}
