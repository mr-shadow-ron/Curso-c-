#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h> // getch
#include <vector>

#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3

using namespace std;

int main()
{   
  //se declaran dos vectores de string (vector) 
  //llamados usuarios y claves donde se van a guardar los nombres de usuario (v�lidos) 
//   y sus respectivas claves
    vector<string> usuarios;
    vector<string> claves;

    // Se a�aden usuarios al vector
    usuarios.push_back("Juliana");
 	usuarios.push_back ("UAG");

    // Se a�aden claves al vector
    claves.push_back("123");
   claves.push_back ("123");
   string usuario, password;

    int contador = 0;
    bool ingresa = false;
//  Se usa un bucle do-while para encerrar el bloque de c�digo 
//donde el programa pedir� y validar� las credenciales ingresadas. 
//La condici�n de repetici�n del bucle es que el contador de intentos sea menor que 3 
//y que la variable ingresa se mantenga en false. (ambas condiciones)
//El bucle termina si se sobrepasa la cantidad de intentos que es igual a 3 
//o si la variable ingresa cambia de false a true.
    do
    {
        system("cls");
        cout << "\t\t\tLOGIN DE USUARIO" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n\tUsuario: ";
        getline(cin, usuario);

        char caracter;

        cout << "\tPassword: ";
        caracter = getch();

        password = "";
     //Se usa la funci�n getline para leer el nombre de usuario en una cadena normal (l�nea 43).
//Para leer la contrase�a se utiliza la funci�n getch, la cual lee caracter por caracter. 
//Esta funci�n solo lee mas no muestra caracter alguno en la pantalla, 
//por lo que en la l�nea 58 imprimimos manualmente un asterisco por cada caracter le�do.
//Los caracteres se leen dentro de un bucle while y la condici�n de repetici�n 
//es que el caracter le�do no sea el correspondiente a la tecla ENTER 
//(cuyo c�digo ASCII es 13).
//Se hace un an�lisis de cada caracter le�do de tal manera 
//que si el caracter le�do no es ENTER ni tampoco BACKSPACE (tecla de retroceso) 
//se concatena en la variable password.
        while (caracter != ENTER)
        {

            if (caracter != BACKSPACE)
            {
                password.push_back(caracter);
                cout << "*";
            }
            else
            {
                if (password.length() > 0)
                {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }

            caracter = getch();
        }

        for (int i = 0; i < usuarios.size(); i++)
        {
            if (usuarios[i] == usuario && claves[i] == password)
            {
                ingresa = true;
                break;
            }
        }

        if (!ingresa)
        {
            cout << "\n\n\tEl usuario y/o password son incorrectos" << endl;
            cin.get();
            contador++;
        }

    } while (ingresa == false && contador < INTENTOS);

    if (ingresa == false)
    {
        cout << "\n\tUsted no pudo ingresar al sistema. ADIOS" << endl;
    }
    else
    {
        cout << "\n\n\tBienvenido al sistema" << endl;
        /* 
        Aqu� va el c�digo del programa cuando el usuario ingresa sus credenciales correctas
        */
        int n1,n2,n3, suma=0,resta=0,multiplicacion=0,division=0,promedio=0; 
	//se agrega el 0 porque al final de la operacion la variable terminara con un valor, se agrega un 0 para evitar valores basura  
	cout<<"digita un numero: ";cin>>n1;
	cout<<"digite otro numero: ";cin>>n2;
	cout<<"digite otro numero: ";cin>>n3;
	suma= n1+n2;
	resta= n1-n2;
	multiplicacion= n1*n2;
	division=n1/n2;
	promedio= n1+n2/3;
	cout<<"\nLa suma es: "<<suma<<endl;//como antes ya se menciono endl sirve para dar salto de linea
	cout<<"\nLa resta es: "<<resta<<endl;
	cout<<"\nLa multiplicacion es: "<<multiplicacion<<endl;
	cout<<"\nLa division es: "<<division<<endl;
	cout<<"\nEl promedio es: "<<promedio<<endl;
	}

    cin.get();

    return 0;
}
