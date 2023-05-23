//Clase principal del programa

import java.util.ArrayList;
import java.util.Scanner;

public class ProgramaPrincipal{
	
	public static void main (String[] args){

		//Arraylist del tipo ProductoElectronico
		ArrayList <ProductoElectronico> listaProductos = new ArrayList<>();

		//variable para pedir un enter para continuar
		Scanner  s = new Scanner(System.in);
		String flush;


		//Instanciar 2 objetos de la clase Celular
		Celular celular1 = new Celular("iPhone 14", 999.99, 12, "Apple", "A13 Bionic", 12, 3187677);
		Celular celular2 = new Celular("Galaxy S23", 899.99, 12, "Samsung", "Exynos 3100", 64, 316680);

		//Insanciar 2 objetos de la clase Computadora
		Computadora computadora1 = new Computadora("MacBook Pro M1", 1999.99, 24, 8, 13.9, 4.8, 32);
		Computadora computadora2 = new Computadora("TUF F14", 1499.99, 12, 16, 16, 4.5, 16);


		//Agregar objetos a la lista
		listaProductos.add(celular1);
		listaProductos.add(celular2);
		listaProductos.add(computadora1);
		listaProductos.add(computadora2);

		//Método cargar de la clase abstracta
		celular1.cargar(10);		//Le enviamos como argumento la carga al primer celular
		celular2.cargar(30);		//Le enviamos como argumento la carga al segundo celular
		System.out.println("\n");
		System.out.println("Presione enter para continuar...");
		flush = s.nextLine();


		computadora1.cargar(60);	//Carga al la primera computadora
		computadora2.cargar(80);	//Carga a la segunda computadora
		System.out.println("\n");
		System.out.println("Presione enter para continuar...");
		flush = s.nextLine();


		//para imprimir
		boolean token = true;

		//Ciclo que recorre la lista y pone a funcionar sus métodos
		for(ProductoElectronico producto : listaProductos){


			if(producto instanceof Computadora){


				((Computadora) producto).cumpleRequisitosMinimos();
				System.out.println("\n");
				((Computadora) producto).determinarTamañoPantalla();
				System.out.println("\n");
				((Computadora) producto).rendimiento();
				System.out.println("\n");

				System.out.println("\nPresione enter para continuar...");
				flush = s.nextLine();

				//Métodos que aplican para ambas clase
				((Computadora) producto).aplicaParaDescuento();
				((Computadora) producto).cuantaGarantia();
				((Computadora) producto).informacionRelevante();
				System.out.println("\n");
				System.out.println("Presione enter para continuar...");
				flush = s.nextLine();

			}

			if(producto instanceof Celular){


				((Celular) producto).imprimirInformacion();
				System.out.println("\n");
				if(token){

					((Celular) producto).calculadora(1, 2, "+");
					System.out.println("\n");
					token = false;
					System.out.println("\n");
					System.out.println("Presione enter para continuar...");
					flush = s.nextLine();
				}
				if(!token) {
					((Celular) producto).calculadora(3, 7.8, "*");
					System.out.println("\n");
					System.out.println("\n");
					System.out.println("Presione enter para continuar...");
					flush = s.nextLine();

				}

				((Celular)producto).fechaDeHoy();
				System.out.println("\n");
				System.out.println("Presione enter para continuar...");
				flush = s.nextLine();


				//Métodos que aplican para ambas clase
				((Celular) producto).aplicaParaDescuento();
				((Celular) producto).cuantaGarantia();
				((Celular) producto).informacionRelevante();
				System.out.println("\n");
				System.out.println("Presione enter para continuar...");
				flush = s.nextLine();

			}




		}









	}
	
}