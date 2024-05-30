#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

typedef struct 
{
    int ticket = 0, dni = 0;
    string apellido, nombre;
    bool asistencia;

}tInvitado;

const int limite = 500;
typedef tInvitado tArray[limite];

typedef struct
{
    tArray elemento;
    int contador = 0;
}tLista;

void menu();
void cargarDatos(tLista& lista);
void guardarDatos(tLista lista);
void agregarInvitado(tLista& lista);
void eliminarInvitado(tLista& lista);
void modificarInvitado(tLista& lista);
void buscarInvitado(tLista lista);
int buscarPosicion(tLista lista);
void mostrarDatos(tLista lista, int posicion);
void confirmarAsistencia(tLista& lista);
void mostrarConfirmados(tLista lista);

void clearConsole()
{
    #ifdef __unix__
        system("clear");
    #elif __APPLE__
        system("clear");
    #elif defined(_WIN32) || defined(WIN32)
        system("cls");
    #endif // defined
}

void pauseConsole()
{
    cin.ignore();
    cin.get();
}

int main()
{
    clearConsole();

    cout << "\n\t\t\t\tBien venido a la\n";
    cout << "\t\tFiesta Aniversario de Studio 54 en New York!\n";
    cout << "\t------------------------------------------------------------\n\n";
    cout << "Precione ENTER para continuar";
    pauseConsole();

    menu();

    return 0;
}
void menu()
{
    int opcion = 0;
    tLista lista;

    cargarDatos(lista);

    do
    {
        clearConsole();

        cout << "\t\t\tMenu Principal\n\n";
        cout << "Opciones del Menu\n";
        cout << "1. Agregar un Invitado\n";
        cout << "2. Eliminar un Invitado\n";
        cout << "3. Modificar datos de un Invitado\n";
        cout << "4. Buscar Invitado\n";
        cout << "5. Modificar Asistencia\n";
        cout << "6. Mostrar lista de Invitados Confimados\n";
        cout << "0. Salir\n";
        cout << "Ingrese su opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                agregarInvitado(lista);
                break;
            case 2:
                eliminarInvitado(lista);
                break;
            case 3:
                modificarInvitado(lista);
                break;
            case 4:
                buscarInvitado(lista);
                break;
            case 5:
                confirmarAsistencia(lista);
                break;
            case 6:
                mostrarConfirmados(lista);
                break;
            case 0:
                cout << "\n\t\tPrograma Finalizado!\n\n";
                break;
            default :
                cout << "Opcion no valida!\n\n";
                break;
        }

    }while(opcion != 0);

    guardarDatos(lista);

}
void cargarDatos(tLista& lista)
{
    
    ifstream archivo;
    
    archivo.open("listainvitados.csv");

    if(archivo.is_open())
    {

        string linea;

        while (getline(archivo, linea)) 
        {
            if(lista.contador >= limite)
            {
                return;
            }

            istringstream iss(linea);
            string campo;
            
            getline(iss, campo, ',');
            lista.elemento[lista.contador].ticket = stoi(campo);

            getline(iss, campo, ',');
            lista.elemento[lista.contador].apellido = campo;

            getline(iss, campo, ',');
            lista.elemento[lista.contador].nombre = campo;

            getline(iss, campo, ',');
            lista.elemento[lista.contador].dni = stoi(campo);

            getline(iss, campo, ',');
            lista.elemento[lista.contador].asistencia = stoi(campo);

            lista.contador++;
        }

        archivo.close();
    }
    else
    {
        cout << "No se encontro el archivo!";
    }
}
void agregarInvitado(tLista& lista)
{
    clearConsole();

    tInvitado invitado;

    if(lista.contador >= limite)
    {
        cout << "\nNo se puede agregar mas Invitados\n";
        return;
    }

    cout << "\n\t\t~~~Agregar Invitado~~~\n\n";

    invitado.ticket = lista.contador + 1000;

    if(invitado.ticket == lista.elemento[lista.contador - 1].ticket)
    {
        invitado.ticket++;
    }

    cout << "Ingresa el apellido del Invitado: ";
    cin.ignore();
    getline(cin, invitado.apellido);
    cout << "Ingresa el nombre del Invitado: ";
    getline(cin, invitado.nombre);
    cout << "Ingrese el DNI del invitado: ";
    cin >> invitado.dni;
    cout << "El numero de Ticket es: " << invitado.ticket << endl;
    cout << "\nInvitado agregado a la lista!";

    lista.elemento[lista.contador] = invitado;
    lista.contador++;

    cout << "\n\nPrecione ENTER para continuar";
    pauseConsole();
    
}
void eliminarInvitado(tLista& lista)
{
    clearConsole();

    cout << "\n\t\t~~~Eliminar Invitado de la lista~~~\n\n";

    int posicion = buscarPosicion(lista);

    if(posicion != -1)
    {
        bool opcion;
        
        mostrarDatos(lista, posicion);
        
        cout << "Es el Invitado que quiere eliminar?\n";
        cout << "Para si ingrese '1'\n";
        cout << "Para no ingrese '0'\n";
        cout << "opcion: ";
        cin >> opcion;

        if(opcion)
        {
            for(int i = posicion; i < lista.contador - 1; i++)
            {
                lista.elemento[i] = lista.elemento[i + 1];
            }
            lista.contador--;
            cout << "Invitado eliminado correctamente!\n";
        }
        else
        {
            cout << "No se dio de Baja al Invitado!\n";
        }
    }
    cout << "\n\nPrecione ENTER para continuar";
    pauseConsole();
}
void modificarInvitado(tLista& lista)
{
    clearConsole();

    cout << "\n\t\t~~~Modificar Invitado~~~\n\n";
    int posicion = buscarPosicion(lista);

    if(posicion != -1)
    {
        bool opcion;
        
        mostrarDatos(lista, posicion);

        cout << "Es el Invitado que quiere Modificar?\n";
        cout << "Para si ingrese '1'\n";
        cout << "Para no ingrese '0'\n";
        cout << "opcion: ";
        cin >> opcion;

        if(opcion)
        {
            cout << "Ingrese el nuevo Apellido del Invitado: ";
            cin.ignore();
            getline(cin, lista.elemento[posicion].apellido);
            cout << "Ingrese el nuevo Nombre del Invitado: ";
            getline(cin, lista.elemento[posicion].nombre);
            cout << "Ingrese el nuevo DNI del Invitado: ";
            cin >> lista.elemento[posicion].dni;
            cout << "Invitado modificado correctamente!\n";
        }
        else
        {
            cout << "No se Modifico el Invitado!\n";
        }
    }
    
    cout << "\n\nPrecione ENTER para continuar";
    pauseConsole();
}
void buscarInvitado(tLista lista)
{
    clearConsole();

    cout << "\n\t\t~~~Buscar Invitado~~~\n\n";

    int posicion = buscarPosicion(lista);

    if(posicion != -1)
    {
        cout << "El invitado:\n"; 
        mostrarDatos(lista, posicion);

        if(lista.elemento[posicion].asistencia == 1)
        {
            cout << "Confirmo la Asistencia";
        }
        else
        {
            cout << "No conrfimo la Asistencia";
        }
    }
    cout << "\n\nPrecione ENTER para continuar";
    pauseConsole();
}
void mostrarDatos(tLista lista, int posicion)
{
    cout << "Ticket del Invitado: " << lista.elemento[posicion].ticket << endl;
    cout << "Apellido del Invitado: " << lista.elemento[posicion].apellido << endl;
    cout << "Nombre del Invitado: " << lista.elemento[posicion].nombre << endl;
    cout << "DNI del Invitado: " << lista.elemento[posicion].dni << endl;
}
int buscarPosicion(tLista lista)
{
    int posicion = -1, ticket = 0;

    cout << "Ingrese el ticket del cliente: ";
    cin >> ticket;

    
    for (int i = 0; i < lista.contador; i++) 
    {
        if(ticket == lista.elemento[i].ticket)
        {
            posicion = i;
            break;
        }
    }
    if(posicion != -1)
    {
        return posicion;
    }
    else
    {
        cout << "Cliente no encontrado!\n";
        return -1;
    }
}
void confirmarAsistencia(tLista& lista)
{
    clearConsole();

    int posicion = buscarPosicion(lista);

    if(posicion != -1)
    {
        bool opcion;

        mostrarDatos(lista, posicion);

        cout << "Es el Invitado que quiere Modificar?\n";
        cout << "Para si ingrese '1'\n";
        cout << "Para no ingrese '0'\n";
        cout << "opcion: ";
        cin >> opcion;

        if(opcion)
        {
            cout << "Para confiar asistencia ingrese '1'\n";
            cout << "Para denegar asistencia ingrese '0'\n";
            cout << "Opcion: ";
            cin >> lista.elemento[posicion].asistencia;

            cout << "\n\nEstado de la asistencia establecido!\n\n";
        }
        else
        {
            cout << "No se establecido un estado de la sistencia!";
        }
    }

    cout << "\n\nPrecione ENTER para continuar";
    pauseConsole();
}
void mostrarConfirmados(tLista lista)
{
    clearConsole();

    cout << "\n\t\t~~~Lista de Invitados Confirmados~~~\n\n";
    cout << setw(6) << "Ticket";
    cout << setw(16) << "Apellido/s" << setw(4);
    cout << setw(20) << "Nombre/s" << setw(5);
    cout << setw(14) << "DNI\n";

for (int i = 0; i < lista.contador; i++)
{
    if(lista.elemento[i].asistencia == 1)
    {
        cout << setw(6) << lista.elemento[i].ticket << " "; 
        cout << setw(20) << lista.elemento[i].apellido << " ";
        cout << setw(20) << lista.elemento[i].nombre << " ";
        cout << setw(9) << lista.elemento[i].dni << endl;
    }
}

    cout << "\n\nPrecione ENTER para continuar";
    pauseConsole();
}
void guardarDatos(tLista lista)
{
    ofstream archivo;

    archivo.open("listainvitados.csv");

    if(archivo.is_open())
    {
        for(int i = 0; i < lista.contador; i++)
        {
            archivo << lista.elemento[i].ticket << "," << lista.elemento[i].apellido << "," 
            << lista.elemento[i].nombre << "," << lista.elemento[i].dni << "," 
            << lista.elemento[i].asistencia << endl;
        }
        archivo.close();
    }
}