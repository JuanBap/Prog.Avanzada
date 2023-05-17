import java.awt.*;
import java.awt.event.*;
/* Permite utilizar las clases y métodos del paquete java.awt.event,
   el cual proporciona una serie de clases para manejar eventos de usuario como
   clics de ratón, teclas presionadas, cambios en el tamaño de la ventana, entre otros */
import javax.swing.*;
import java.io.Serial;
/* Es utilizada para serializar objetos y permitir su almacenamiento o transmisión a través
   de una red o sistema de archivos */

import java.util.Random;
/* permite que el código de un archivo fuente utilice la clase Random del paquete
   java.util, que proporciona una funcionalidad para generar números aleatorios */

import javax.swing.JPanel;

/*  es una clase que se utiliza para crear un panel que puede contener otros
    componentes y que se puede agregar a un contenedor como una ventana JFrame */

//Inicio de la clase GamePanel que hereda de JPanel e implementa la interfaz ActionListener
public class GamePanel extends JPanel implements ActionListener{


	/*@Serial y la variable serialVersionUID se utilizan para indicar que una clase es
	 serializable y para asegurarse de que los objetos serializados y deserializados
	 sean compatibles en términos de versiones.  */
	@Serial
	private static final long serialVersionUID = 1L;


	//Asignamos las dimensiones de nuestra pantalla como constantes
	static final int WIDTH = 800;	//Ancho de la pantalla
	static final int HEIGHT = 500;	//Altura de la pantalla

	//Tamaño de cada casilla dentro de la pantalla
	static final int UNIT_SIZE = 20;	//Tamaño del cuadrado de la casilla

	//Calculamos la cantidad de casillas que tiene el tablero
	static final int NUMBER_OF_UNITS = (WIDTH * HEIGHT) / (UNIT_SIZE * UNIT_SIZE);	//Total de casillas en el mapa

	/*En estos arreglos estáticos guardamos la cantidad de piezas que va adquiriendo la serpiente
	  y asignamos el tamaño máximo de esta como el total de las casillas en el mapa */

	final int x[] = new int[NUMBER_OF_UNITS];	// Guarda las coordenadas X de cada pieza de la serpiente
	final int y[] = new int[NUMBER_OF_UNITS];	// Guarda las coordenadas Y de cada pieza de la serpiente
	
	//Condiciones iniciales de nuestra serpiente
	int length = 5;		//Indica la cantidad de piezas que tiene la serpiente
	int foodEaten;		//Lleva la cuenta de la cantidad de frutas que ha comido la serpiente
	int foodX;			//Indica la coordenada en el eje X del alimento
	int foodY;			//Indica la coordenada en el eje Y del alimento
	char direction = 'D';	//Indica la dirección de la serpiente, esta arranca corriendo hacia la derecha
	boolean running = false;	//Indica si el juego está en ejecución o no
	Random random;	//Instancia de la clase Random que se usa para generar la posición del alimento
	Timer timer;	//Instancia de la clase Timer que llama al método actionPerformed


	//El método constructor del panel, aquí se inicializan las variables de instancia y se configura el panel del juego
	GamePanel() {
		random = new Random();	//Crea una instancia de la clase Random para ser utilizada posteriormente en el juego
		this.setPreferredSize(new Dimension(WIDTH, HEIGHT));	//Establece las dimensiones preferidas del panel de juego con WIDTH y HEIGHT
		this.setBackground(new Color(18, 9, 65));	//Establece el color de fondo del panel a azul oscuro
		this.setFocusable(true);	//Permite que el panel pueda recibir eventos del teclado
		this.addKeyListener(new MyKeyAdapter());	//Agrega el objeto MyKeyAdapter como un KeyListener en el panel para detectar las entradas del usuario
		play();		//Llama el método play() para comenzar el juego
	}	

	//El método play se encarga de iniciar el juego
	public void play() {
		addFood();		//Llama al método addFood() para agregar una pieza de comida en una ubicación aleatoria dentro del panel del juego
		running = true;		//Establece el valor de running lo que indica si el juego está en funcionamiento o no
		timer = new Timer(120, this);	//Establece la duración en milisegundos (80) que es el período de tiempo que se encargará de actualizar el juego
		timer.start();		//Se inicia el temporizador llamando el método start dentro del objeto timer
	}

	//Sobrescritura de método paintComponent

	/* Es un método de la clase JPanel que se utiliza para dibujar los componentes de la interfaz gráfica de usuario,
	   en este caso, se está sobrescribiendo el método para personalizar la forma en que se dibuja el panel del juego */

	@Override
	//Recibe como argumento el objeto Graphics que se utiliza para dibujar los componentes del panel
	public void paintComponent(Graphics graphics) {

		super.paintComponent(graphics);	//Se llama el método para asegurarse de que los componentes de la superclase se dibujen correctamente
		draw(graphics);		//Se llama el método para dibujar la serpiente y la comida en el panel, haciendo uso de los métodos drawSnake y drawFood.

	}



	/* El método move() es responsable de mover la serpiente en la dirección especificada por la variable direction.
	   Primero, el método actualiza las posiciones de la serpiente a medida que se mueve.
	   Esto se logra moviendo cada segmento de la serpiente a la posición del segmento anterior.
	   Luego, el método mueve la cabeza de la serpiente (el primer segmento) en la dirección especificada por direction.
	   Si la dirección es 'L' (izquierda), se mueve la cabeza una unidad a la izquierda, si es 'R' (derecha),
	   se mueve una unidad a la derecha, si es 'U' (arriba), se mueve una unidad hacia arriba,
	   y si es 'D' (abajo), se mueve una unidad hacia abajo. El movimiento se realiza en intervalos
	   de tiempo determinados por el temporizador que se establece en el método play() */
	public void move() {
		for (int i = length; i > 0; i--) {
			// Aquí indicamos que giremos la serpiente una unidad hacia la dirección deseada para generar un movimiento
			x[i] = x[i-1];
			y[i] = y[i-1];
		}
		
		if (direction == 'L') {
			x[0] = x[0] - UNIT_SIZE;
		} else if (direction == 'R') {
			x[0] = x[0] + UNIT_SIZE;
		} else if (direction == 'U') {
			y[0] = y[0] - UNIT_SIZE;
		} else {
			y[0] = y[0] + UNIT_SIZE;
		}	
	}

	/* El método checkFood() comprueba si la cabeza de la serpiente
	   se encuentra en la misma posición que la comida */
	public void checkFood() {
		if(x[0] == foodX && y[0] == foodY) { 	//Si esa condición se cumple
			length++;	//Incrementa la longitud de la serpiente una unidad
			foodEaten++;	//Incrementa el contador de frutas comidas
			addFood();	//Llama al método addFood() para generar una nueva fruta en una posición nueva aleatoria
		}
	}
	
	public void draw(Graphics graphics) {
		
		if (running) {		//Si el juego está corriendo:

			graphics.setColor(new Color(235, 255, 21, 255));	//Color de la fruta
			graphics.fillOval(foodX, foodY, UNIT_SIZE, UNIT_SIZE);		//Posición de la fruta
			
			graphics.setColor(new Color(190, 255, 190));		//Color de la cabeza de la serpiente
			graphics.fillRect(x[0], y[0], UNIT_SIZE, UNIT_SIZE);		//Posición de la cabeza de la serpiente
			
			for (int i = 1; i < length; i++) {							//Ciclo que va actualizando el cuerpo de la serpiente teniendo en cuenta su largo
				graphics.setColor(new Color(21, 236, 0));		//Color del cuerpo de la serpiente
				graphics.fillRect(x[i], y[i], UNIT_SIZE, UNIT_SIZE);	//Posición del cuerpo de la serpiente
			}

			//Letrero de la puntuación del jugador
			graphics.setColor(Color.YELLOW);		//Color de la letra
			graphics.setFont(new Font("Sans serif", Font.ROMAN_BASELINE, 25));	//Fuente de la letra
			FontMetrics metrics = getFontMetrics(graphics.getFont());		//Información sobre la fuente utilizada para dibujar textos, como la altura y el ancho de los caracteres
			graphics.drawString("Puntuación: " + foodEaten, (WIDTH - metrics.stringWidth("Puntuación: " + foodEaten)) / 2, graphics.getFont().getSize()); //Posición del letrero de puntuación
		
		} else {
			gameOver(graphics);		//Si el juego deja de correr, llama al método gameOver(graphics) e imprime la pantalla de juego final
		}
	}

	//Este método añade una fruta en el tablero cada vez que es llamado
	public void addFood() {
		foodX = random.nextInt((int)(WIDTH / UNIT_SIZE))*UNIT_SIZE;		//Añade la posición aleatoria en el eje X en el mapa
		foodY = random.nextInt((int)(HEIGHT / UNIT_SIZE))*UNIT_SIZE;	//Añade la posición aleatoria en el eje Y en el mapa
	}

	//Revisa si hay colisiones. Si las hay deja de correr el juego y pone running como false
	public void checkHit() {
		// Revisa si el cuerpo choca con la cabeza
		for (int i = length; i > 0; i--) {
			if (x[0] == x[i] && y[0] == y[i]) {
				running = false;
			}
		}
		
		// Revisa si la serpiente se sale del mapa o choca con las paredes
		if (x[0] < 0 || x[0] > WIDTH || y[0] < 0 || y[0] > HEIGHT) {
			running = false;
		}
		//Si running se vuelve falso para el temporizador y llama el método timer.stop();
		if(!running) {
			timer.stop();
		}
	}

	//Método para imprimir en pantalla los textos de la puntuación y fin del juego al final
	public void gameOver(Graphics graphics) {

		graphics.setColor(Color.RED);	//Definimos el color del gráfico a mostrar
		graphics.setFont(new Font("Sans serif", Font.ROMAN_BASELINE, 50));	//Definimos la tipografía y el tamaño
		FontMetrics metrics = getFontMetrics(graphics.getFont());	//Información sobre la fuente utilizada para dibujar textos, como la altura y el ancho de los caracteres
		graphics.drawString("Fin del juego", (WIDTH - metrics.stringWidth("Fin del juego")) / 2, HEIGHT /3);	//Muestra en pantalla nuestro mensaje y la posición de este

		graphics.setColor(Color.orange);	//Definimos el color del gráfico a mostrar
		graphics.setFont(new Font("Sans serif", Font.ROMAN_BASELINE, 30));	//Definimos la tipografía y el tamaño
		metrics = getFontMetrics(graphics.getFont());	//Información sobre la fuente utilizada para dibujar textos, como la altura y el ancho de los caracteres
		graphics.drawString("Nombre: Juan Pablo Cañón Contreras", (WIDTH - metrics.stringWidth("Nombre: Juan Pablo Cañón Contreras")) / 2, HEIGHT / 2); //Muestra en pantalla nuestro mensaje y la posición de este
		
		graphics.setColor(Color.yellow);	//Definimos el color del gráfico a mostrar
		graphics.setFont(new Font("Sans serif", Font.ROMAN_BASELINE, 25));	//Definimos la tipografía y el tamaño
		metrics = getFontMetrics(graphics.getFont());	//Información sobre la fuente utilizada para dibujar textos, como la altura y el ancho de los caracteres
		graphics.drawString("Puntuación final: " + foodEaten, (WIDTH - metrics.stringWidth("Puntuación final: " + foodEaten)) / 2, graphics.getFont().getSize()); //Muestra en pantalla nuestro mensaje y la posición de este

	}


	/*
		Este método es una implementación de la interfaz ActionListener y se ejecuta automáticamente cada
		vez que se produce un evento de acción, en este caso, se llama al método cada vez que el temporizador
		 en el método play() envía una señal */

	@Override
	public void actionPerformed(ActionEvent arg0) {
		if (running) {		//Si el juego está corriendo
			move();		//Llama al método que se encarga de mover la serpiente
			checkFood();	//Comprueba si la serpiente se ha comido una fruta
			checkHit();		//Comprueba si la serpiente ha chocado con su cuerpo o con los bordes
		}
		repaint(); //Llama al método repaint(); que se utiliza para volver a dibujar la pantalla y actualizar la posición de la serpiente y de la comida.
	}



	/* Este código define una clase interna llamada MyKeyAdapter, que extiende la clase KeyAdapter y
	 anula su método keyPressed(). Esta clase permite al usuario controlar la dirección de la serpiente
	  mediante las teclas de flecha izquierda, derecha, arriba y abajo */

	public class MyKeyAdapter extends KeyAdapter {
		@Override
		public void keyPressed(KeyEvent e) {

			switch(e.getKeyCode()) {			//En la anulación del método keyPressed(), se usa un switch que evalúa
												//el código de la tecla presionada. Si la tecla presionada corresponde
				case KeyEvent.VK_LEFT:			//a la flecha izquierda, derecha, arriba o abajo, se comprueba si la
					if (direction != 'R') {		//dirección actual de la serpiente es opuesta a la dirección que
						direction = 'L';		//representa la tecla presionada. Si la dirección actual no es opuesta
					}							// a la dirección de la tecla presionada, se actualiza la dirección de
					break;						//la serpiente. Esto se hace para evitar que la serpiente se mueva
												//hacia atrás y choque consigo misma
				case KeyEvent.VK_RIGHT:
					if (direction != 'L') {
						direction = 'R';
					}
					break;
					
				case KeyEvent.VK_UP:
					if (direction != 'D') {
						direction = 'U';
					}
					break;
					
				case KeyEvent.VK_DOWN:
					if (direction != 'U') {
						direction = 'D';
					}
					break;		
			}
		}
	}
}








































