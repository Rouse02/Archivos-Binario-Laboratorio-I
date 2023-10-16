#include <stdio.h>
#include <stdlib.h>
#include "strings.h"
#include "pila.h"

//Variables Globales
#define DIM 40

//Estructuras
typedef struct {
int legajo;
char nombreApellido[DIM];
int edad;
int anioCurso;
}Alumno;

//Prototipado
void cargarMenu();//Menú
void cargarIntFinal(char archivoInt[DIM]);//1
void mostrarFunc1(char archivoInt[DIM]);//2
int cantidadRegistrosArchivo1(char archivoInt[]);//3
void cargarAlumnos(char alumnos[DIM]);//4
Alumno cargarAlumno();//4
void mostrarArchivoAlumnos(char alumnos[DIM]);//5
void mostrarAlumno();//5
void cargarAlumnoAlFinal(char alumnos[DIM]);//6
void pasajePila(char alumnos[DIM]);//7
int alumnosXedadEspecifica(char alumnos[DIM], int edadEspecifica);//8
void mostrarAlumnosRango(char alumnos[DIM], int desde, int hasta);//9
int mostrarAlumnoMayorEdad(char alumnos[DIM]);//10
void mostrarAlumnoMayor(char alumnos[DIM], int mayor);//10
int retornaAlumnosXcurso(char alumnos[DIM], int anio);//11
int cargarArrayAlumnos(Alumno array[]);//12
Alumno cargarArrayAlumno();//12
void copiarArrayAlumnosAlArchivo(char archivo[], Alumno alumnos[], int validos);//12
void pasajeArchivosAlArray(char archivo[], int anio);//12
int contabilizarRegistros(char archivo[]);//13
void mostrarAlumnoRegistro(char archivo[], int numRegistro);//14
void cargarAlumnosWB(char alumnos[DIM]);//15
void sobreescribirRegistro(char archivo[], int numRegistro);//15
void invertirArchivo(char archivo[], int registros);//16
/*---------------------------------------------------------------------------------------------------------------------------------------------------*/
int main() {

char eleccion = 's';
int ejercicio;
int flag = 0;

do {

cargarMenu();

do {
    printf("Ingrese el numero de ejercicio a dirigirse ---> ");
    fflush(stdin);

    if(scanf("%i", &ejercicio) == 1) {
        printf("\nDirigiendose al ejercicio Numero %i \n\n", ejercicio);
        flag = 1;
    }
    else {
        printf("\nNo se ingreso un numero entero. Vuelva a intentarlo \n\n");
    }
}while(flag == 0);

//Variables que se utilizarán en el Switch
char archivoInt[DIM] = {"archivoInt.bin"};
char archivoAlumnos[DIM] = {"alumnos.bin"};

switch(ejercicio) {

case 1:

    cargarIntFinal(archivoInt);

break;



case 2:

    mostrarFunc1(archivoInt);

break;


case 3:

    int cantRegistrosInt;
    cantRegistrosInt = cantidadRegistrosArchivo1(archivoInt);
    printf("La cantidad de Registros es de %i \n\n", cantRegistrosInt);

break;


case 4:

    cargarAlumnos(archivoAlumnos);

break;


case 5:

    mostrarArchivoAlumnos(archivoAlumnos);

break;


case 6:

    cargarAlumnoAlFinal(archivoAlumnos);
    mostrarArchivoAlumnos(archivoAlumnos);

break;


case 7:

    pasajePila(archivoAlumnos);

break;


case 8:

    int edadFiltro;
    int numEdades;

    printf("Ingrese un numero de edad especifica para contabilizar los alumnos ---> ");
    fflush(stdin);
    scanf("%i", &edadFiltro);
    printf("\n");

    numEdades = alumnosXedadEspecifica(archivoAlumnos, edadFiltro);

    printf("La cantidad de alumnos a partir de la edad especificada es %i \n\n", numEdades);

break;


case 9:

    int desde;
    int hasta;

    printf("Ingrese el rango de edad para mostrar a los Alumnos (Desde-Hasta)\n\n");
    fflush(stdin);
    printf("Desde ---> ");
    scanf("%i", &desde);
    fflush(stdin);
    printf("\n");
    printf("Hasta ---> ");
    scanf("%i", &hasta);
    printf("\n");

    printf("Mostrando alumnos entre el rango de edades \n\n");
    mostrarAlumnosRango(archivoAlumnos, desde, hasta);


break;


case 10:

    int edadMayor;
    edadMayor = retornarAlumnoMayorEdad(archivoAlumnos);
    printf("MOSTRANDO ALUMNO CON MAYOR EDAD\n");
    mostrarAlumnoMayor(archivoAlumnos, edadMayor);

break;


case 11:

    int cantAlum;
    int anioCursada;
    printf("Ingrese el año para saber la cantidad de Alumnos que cursan (1-6) ---> ");
    scanf("%i", &anioCursada);
    printf("\n");

    cantAlum = retornaAlumnosXcurso(archivoAlumnos, anioCursada);
    printf("La cantidad de alumnos que cursan %i anio son ---> %i \n\n", anioCursada, cantAlum);

break;


case 12:

    Alumno arrayAlum[DIM];
    int validosArrayAlumnos;
    int anioFiltrado;

    validosArrayAlumnos = cargarArrayAlumnos(arrayAlum);
    printf("Se ingresaron %i alumnos/as \n\n", validosArrayAlumnos);

    printf("Copiando elementos del arreglo al archivo... \n\n");

    copiarArrayAlumnosAlArchivo(archivoAlumnos, arrayAlum, validosArrayAlumnos);

    printf("Mostrando los datos cargados dentro del Archivo... \n\n");

    mostrarArchivoAlumnos(archivoAlumnos);

    printf("Ingrese el anio de Filtrado de alumnos ---> ");
    fflush(stdin);
    scanf("%i", &anioFiltrado);
    printf("\n");

    pasajeArchivosAlArray(archivoAlumnos, anioFiltrado);

break;


case 13:
    int cantidadAlumnos;
    cantidadAlumnos = contabilizarRegistros(archivoAlumnos);
    printf("Cantidad de registros ---> %i \n \n", cantidadAlumnos);

break;


case 14:

    int flag = 0;
    int registroNum;
    int cantAlumnos;
    int ubicacionRegistro;
    int tamanioStruct = 52;

    do {
        printf("Ingrese un numero de registro (1-10) ---> ");
        fflush(stdin);

        //Validación del tipo de dato
        if(scanf("%i", &registroNum) == 1) {
                printf("\n");
                flag = 1;

            //Validación del rango pedido
            if(registroNum >= 1 && registroNum <= 10) {
                flag = 1;
            }else {
                printf("\n");
                printf("El numero ingresado no se encuentra dentro del rango. Vuelva a intentarlo \n\n");
                flag = 0;
            }

        } else {
            printf("\n");
            printf("El numero ingresado no es de tipo Entero. Vuelva a intentarlo \n\n");
            flag = 0;
        }
    }while(flag == 0);

    cantAlumnos = contabilizarRegistros(archivoAlumnos);

    ubicacionRegistro = registroNum * tamanioStruct;

    mostrarAlumnoRegistro(archivoAlumnos, registroNum);
break;


case 15:

    printf("Pulse 's' si desea modificar por completo el Archivo de alumnos (s/n) ---> ");
    fflush(stdin);
    scanf("%c", &eleccion);
    printf("\n");

    if(eleccion == 's') {
        cargarAlumnosWB(archivoAlumnos);
    }

    printf("Pulse 's' si desea modificar solo un resgistro del Archivo (s/n) ---> ");
    fflush(stdin);
    scanf("%c", &eleccion);
    printf("\n");

    if(eleccion == 's') {

        int cantAlum = contabilizarRegistros(archivoAlumnos);
        int registro;

        printf("Hay %i registros cargados \n\n", cantAlum);

        printf("Indique que numero de registro desea modificar ---> ");
        fflush(stdin);
        scanf("%i", &registro);
        printf("\n");

        sobreescribirRegistro(archivoAlumnos, registro);
    }
break;


case 16:

    int registros;


    registros = contabilizarRegistros(archivoAlumnos);
    printf("Existen %i registros cargados \n\n", registros);

    mostrarArchivoAlumnos(archivoAlumnos);

    invertirArchivo(archivoAlumnos, registros);

    mostrarArchivoAlumnos(archivoAlumnos);

break;

default:

    printf("El numero de ejercicio no es valido. Por favor vuelva a intentarlo \n \n");

break;

}//Fin switch

printf("Pulse 's' para volver al menu (s/n) ---> ");
fflush(stdin);
scanf("%c", &eleccion);
printf("\n");
}while(eleccion == 's');

}//Fin del main

//FUNCIONES

//Menú
void cargarMenu() {
printf("1)Hacer una funcion que agregue un elemento al final de un archivo \n \n");
printf("2)Hacer una funcion que muestre por pantalla el contenido de un archivo \n \n");
printf("3)Hacer una funcion que retorne la cantidad de registros que contiene un archivo \n\n");
printf("4)Crear una funcion que cargue un archivo de alumnos. Abrirlo de manera tal de verificar si el archivo ya esta creado previamente. Cargar el archivo con 5 datos. Cerrarlo dentro de la funcion \n\n");
printf("5)Crear una funcion que muestre por pantalla los registros de un archivo de alumnos. Modularizar \n\n");
printf("6)Crear una funcion que permita agregar de a un elemento al final del archivo. O sea, se debeabrir el archivo, se piden los datos (se llena una variable de tipo struct alumno), se escribe en el archivo y se cierra \n\n");
printf("7)Crear una funcion que pase a una pila los numeros de legajo de los alumnos mayores de edad \n\n");
printf("8)Dado un archivo de alumnos, hacer una funcion que cuente la cantidad de alumnos mayores a edad especifica que se envia por parametro \n\n");
printf("9)Dado un archivo de alumnos, mostrar por pantalla el nombre de todos los alumnos entre un rango de edades especifico (por ejemplo, entre 17 y 25 años). Dicho rango debe recibirse por parametro. Modularizar \n\n");
printf("10)Dado un archivo de alumnos, mostrar los datos del alumno de mayor edad. Modularizar \n\n");
printf("11)Crear una funcion que retorne la cantidad de alumnos que cursan un determinado año. El año buscado se pasa por parametro \n\n");
printf("12)Crear una funcion que reciba como parametro un arreglo de tipo alumno y lo copie en el archivo. Asimismo, realice otra funcion que pase los elementos del archivo a un arreglo de alumnos, filtrando los estudiantes de un año en particular \n\n");
printf("13)Crear una funcion que retorne la cantidad de registros que tiene el archivo. Usar fseek y ftell. Puede pensar la funcion para uso genérico, que sirva para averiguar la cantidad de registros de cualquier archivo \n\n");
printf("14)Dado un archivo de alumnos, que tenga al menos 10 registros, hacer una funcion que muestre el contenido de un registro, cuyo numero (entre 0 y 9) se pase por parametro. Controlar no sobrepasar los limites del archivo \n\n");
printf("15)Realice una (o varias) funciones que permitan modificar un registro registro en el archivo de alumnos. La misma debe permitir modificar uno o todos los campos de la estructura y sobreescribir el registro existente en el archivo \n\n");
printf("16)Dado un archivo de alumnos, hacer una funcion que invierta los elementos del mismo. No se puede usar otro archivo auxiliar  ni un arreglo auxiliar. Debe trabajar sobre el archivo.Puede utilizar variables de tipo alumno auxiliares \n\n");
}

//Exercise 1
void cargarIntFinal(char archivoInt[DIM]) {

int num;

FILE *exercise1; //Declaración del Puntero donde se almacenará la dirección en memoria del archivo

exercise1 = fopen(archivoInt, "ab");//Apertura del archivo

if(exercise1 != NULL) { //Verificación si existe el archivo o no

printf("Ingrese un numero entero ---> ");
fflush(stdin);
scanf("%i", &num);
printf("\n");

fwrite(&num,sizeof(int),1,exercise1); //Guarda la información en el Buffer

fclose(exercise1); //Toma la información del Buffer y la pasa al archivo
}
}

//Exercise 2
void mostrarFunc1(char archivoInt[DIM]) {

int num; //Me ayuda al pasaje de datos entre el disco y el Buffer

FILE *exercise1;

exercise1 = fopen(archivoInt, "rb");

if(exercise1 != NULL) {

while(!feof(exercise1)) { //Recorre la totalidad del archivo hasta llegar al End Of File

fread(&num, sizeof(int), 1, exercise1); //Parámetros: 1- dirección en memoria de la variable intermediaria. 2- Tamaño en bytes de lo que quiero leer. 3- Cantidad de elementos a leer (Siempre 1). 4- Puntero File, dodne está el archivo

if(!feof(exercise1)) { //Doble comprobación. Si tengo datos por leer, entonces printeo lo que quiero mostrar

    printf("El num cargado es: %i \n \n", num);
            }
        }//Fin del While. Fuera del While Cierro el Archivo

        fclose(exercise1);

    } //Dentro de la Primera Comprobación del EOF cierro el archivo
}

//Exercise 3
int cantidadRegistrosArchivo1(char archivoInt[]) {

int num;
int i = 0;

FILE *exercise1;

exercise1 = fopen(archivoInt, "rb");

if(exercise1 != NULL) {

    while(!feof(exercise1)) {

        fread(&num, sizeof(int), 1, exercise1);

        if(!feof(exercise1)) {

            i++; //Va a incrementar en cada iteración

            }
        }
    }

    return i;
}

//Exercise 4
void cargarAlumnos(char alumnos[DIM]) {

char eleccion = 's';

Alumno alum;

FILE *archivoAlum;

archivoAlum = fopen(alumnos, "ab");

if(archivoAlum != NULL) {

    while(eleccion == 's'){

        alum =  cargarAlumno();
        fwrite(&alum, sizeof(Alumno), 1, archivoAlum);

        printf("Pulse 's' si desea ingresar otro Registro ---> ");
        fflush(stdin);
        scanf("%c", &eleccion);
        printf("\n\n");
    }

    fclose(archivoAlum);

    printf("Registro cargado con exito \n\n");
    }
}

//Exercise 4 (Carga un solo alumno)
Alumno cargarAlumno() {

Alumno nuevoAlumno;
int flag = 0;

printf("Ingrese su Nombre y Apellido ---> ");
fflush(stdin);
gets(nuevoAlumno.nombreApellido);
printf("\n");

do {
   printf("Ingrese su Numero de Legajo ---> ");
    fflush(stdin);

    if(scanf("%i", &nuevoAlumno.legajo) == 1) {
        printf("\n");
        flag = 1;
    }
    else {
        printf("\nNo se ingreso un numero entero. Vuelva a intentarlo \n\n");
    }
}while(flag == 0);


do {
    printf("Ingrese el anio que cursa ---> ");
    fflush(stdin);

    if(scanf("%i", &nuevoAlumno.anioCurso) == 1) {
        printf("\n");
        flag = 1;
    }

    else {
        printf("\nNo se ingreso un numero entero. Vuelva a intentarlo \n\n");
        flag = 0;
    }

}while(flag == 0);

do {
    printf("Ingrese su edad ---> ");
    fflush(stdin);

    if(scanf("%i", &nuevoAlumno.edad) == 1) {
        printf("\n");
        flag = 1;
    }

    else {
        printf("\nNo se ingreso un numero entero. Vuelva a intentarlo \n\n");
        flag = 0;
    }

}while(flag == 0);

return nuevoAlumno;
}

//Exercise 5
void mostrarArchivoAlumnos(char alumnos[DIM]) {

int i = 0;

Alumno alum;

FILE *archivoAlum;
archivoAlum = fopen(alumnos, "rb");

if(archivoAlum != NULL) {

     printf("\n\n             MOSTRANDO ALUMNOS REGISTRADOS                  \n\n");

    while(!feof(archivoAlum)) {

        fread(&alum, sizeof(Alumno), 1, archivoAlum);

        if(!feof(archivoAlum)) {

            mostrarAlumno(alum);
                }
            }
            fclose(archivoAlum);
        }
    }

//Exercise 5
void mostrarAlumno(Alumno alumm) {
printf("---------------------------------------------------------\n");
printf("Nombre y Apellido ---> %s \n\n", alumm.nombreApellido);
printf("Numero de Legajo ---> %i \n\n", alumm.legajo);
printf("Anio que Cursa ---> %i \n\n", alumm.anioCurso);
printf("Edad ---> %i \n\n", alumm.edad);
printf("---------------------------------------------------------\n\n");
}

//Exercise 6
void cargarAlumnoAlFinal(char alumnos[DIM]) {

    Alumno nuevoAlum;

    FILE *archivoAlum;

    archivoAlum = fopen(alumnos, "ab");

    if(archivoAlum != NULL) {


        nuevoAlum = cargarAlumno();
        fwrite(&nuevoAlum, sizeof(Alumno), 1, archivoAlum);
        fclose(archivoAlum);

        printf("Se agrego exitosamente un nuevo Alumno \n\n");
    }
}
//Exercise 7
void pasajePila(char alumnos[DIM]) {

Pila alumnoMayoresEdad;
inicpila(&alumnoMayoresEdad);


Alumno alum;

FILE *archivoAlum;

archivoAlum = fopen(alumnos, "rb");

if(archivoAlum != NULL) {


    while(!feof(archivoAlum)) {

        fread(&alum, sizeof(Alumno), 1, archivoAlum);

        if(!feof(archivoAlum)) {

            if(alum.edad >= 18) {

                apilar(&alumnoMayoresEdad, alum.legajo);
                }
            }
        }

        fclose(archivoAlum);
}

    mostrar(&alumnoMayoresEdad);
}

//Exercise 8
int alumnosXedadEspecifica(char alumnos[DIM], int edadEspecifica) {

int i = 0;

Alumno alum;

FILE *archivoAlum;

archivoAlum = fopen(alumnos, "rb");

if(archivoAlum != NULL){

    while(!feof(archivoAlum)) {

    fread(&alum, sizeof(Alumno), 1, archivoAlum);

    if(!feof(archivoAlum)) {

        if(alum.edad >= edadEspecifica) {
            i++;
        }
    }
    }

    fclose(archivoAlum);
}
    return i;
}

//Exercise 9
void mostrarAlumnosRango(char alumnos[DIM], int desde, int hasta) {

Alumno alum;

FILE *archivoAlum;

archivoAlum = fopen(alumnos, "rb");

if(archivoAlum != NULL) {

    while(!feof(archivoAlum)) {

        fread(&alum, sizeof(Alumno), 1, archivoAlum);

        if(!feof(archivoAlum)) {

            if(alum.edad >= desde && alum.edad <= hasta) {
                    printf("Nombre y Apellido del Alumno/a ---> %s \n\n", alum.nombreApellido);
                }
                }
            }
            fclose(archivoAlum);
        }

    }

//Exercise 10
int retornarAlumnoMayorEdad(char alumnos[DIM]) {

Alumno alum;
int mayorEdad = 10;

FILE *archivoAlum;

archivoAlum = fopen(alumnos, "rb");

if(archivoAlum != NULL) {

    while(!feof(archivoAlum)) {

        fread(&alum, sizeof(Alumno), 1, archivoAlum);


        if(!feof(archivoAlum)) {

            if(alum.edad > mayorEdad) {

                mayorEdad = alum.edad;

                    }
                }
            }

        fclose(archivoAlum);
    }
    return mayorEdad;
}

//Exercise 10
void mostrarAlumnoMayor(char alumnos[DIM], int mayor) {

Alumno alum;

FILE *archivoAlum;

archivoAlum = fopen(alumnos, "rb");

if(archivoAlum != NULL) {


    while(!feof(archivoAlum)) {

        fread(&alum, sizeof(Alumno), 1, archivoAlum);

        if(!feof(archivoAlum)) {

            if(alum.edad == mayor) {

                mostrarAlumno(alum);
                    }
                }
            }
        fclose(archivoAlum);
    }
}

//Exercise 11
int retornaAlumnosXcurso(char alumnos[DIM], int anio) {

int i = 0;
Alumno alum;
FILE *archivoAlum;
archivoAlum = fopen(alumnos, "rb");

if(archivoAlum != NULL) {

        while(!feof(archivoAlum)) {

            fread(&alum, sizeof(Alumno), 1, archivoAlum);

            if(!feof(archivoAlum)) {

                if(alum.anioCurso == anio) {
                    i++;
                }
            }
        }
    fclose(archivoAlum);
}
    return i;
}

//Exercise 12 Cargar Arreglo de Alumnos

int cargarArrayAlumnos(Alumno array[]) {

int i = 0;
char eleccion = 's';

    printf("Pulse 's' para agregar un alumno (s/n) ---> ");
    fflush(stdin);
    scanf("%c", &eleccion);
    printf("\n");

    while(eleccion == 's' && i < DIM) {

        array[i] = cargarAlumno();

        i++;


        printf("Pulse 's' para ingresar otro Alumno ---> ");
        fflush(stdin);
        scanf("%c", &eleccion);
        printf("\n");
        }

return i;
}

//Exercise 12 Cargar un nuevo alumno
Alumno cargarArrayAlumno() {

    Alumno nuevoAlum;

    printf("Ingrese su Nombre y Apellido ---> ");
    fflush(stdin);
    gets(nuevoAlum.nombreApellido);
    printf("\n");

    printf("Ingrese su Numero de Legajo ---> ");
    fflush(stdin);
    scanf("%i", &nuevoAlum.legajo);
    printf("\n");

    printf("Ingrese su anio de Cursada ---> ");
    fflush(stdin);
    scanf("%i", &nuevoAlum.anioCurso);
    printf("\n");

    printf("Ingrese su edad ---> ");
    fflush(stdin);
    scanf("%i", &nuevoAlum.edad);
    printf("\n");

    return nuevoAlum;
}

//Exercise 12 Copia los elementos del archivo previamente cargados al archivo

void copiarArrayAlumnosAlArchivo(char archivo[], Alumno alumnos[], int validos) {
int i;
FILE *archivoAlum;
archivoAlum = fopen(archivo, "ab");

if(archivoAlum != NULL) {


    for(i = 0; i < validos; i++) {

        fwrite(&alumnos[i], sizeof(Alumno), 1, archivoAlum);
    }
    fclose(archivoAlum);
    }
}

//Exercise 12
void pasajeArchivosAlArray(char archivo[], int anio) {

Alumno arrayAuxiliar[DIM];
int i;
Alumno alum;
FILE *archivoAlum;
archivoAlum = fopen(archivo, "rb");

if(archivoAlum != NULL) {

    i = 0;

    while(!feof(archivoAlum)) {

        fread(&alum, sizeof(Alumno), 1, archivoAlum);

        if(!feof(archivoAlum)) {

            if(alum.anioCurso == anio) {

                strcpy(arrayAuxiliar[i].nombreApellido, alum.nombreApellido);
                arrayAuxiliar[i].legajo = alum.legajo;
                arrayAuxiliar[i].anioCurso = alum.anioCurso;
                arrayAuxiliar[i].edad = alum.edad;

                i++;
            }
            else {
                printf("No hay Alumnos registrados en ese anio \n\n");
            }
        }
    }
    fclose(archivoAlum);
}

    int validos = i;

    //Mostrar el arreglo (Solo para corroborar que anda bien)

    for(i = 0; i < validos; i++) {

        printf("---------------------------------------------------------------------------\n");
        printf("Nombre y Apellido |%s| \n \n", arrayAuxiliar[i].nombreApellido);
        printf("Numero de legajo |%i| \n \n", arrayAuxiliar[i].legajo);
        printf("Año de cursada |%i| \n \n", arrayAuxiliar[i].anioCurso);
        printf("Edad |%i| \n \n", arrayAuxiliar[i].edad);
        printf("---------------------------------------------------------------------------\n");
    }
}

//Exercise 13

int contabilizarRegistros(char archivo[]) {


    int tamanioRegistro = 0;
    int cantidadRegistros = 0;

    Alumno alum;
    FILE *archivoAlum;
    archivoAlum = fopen(archivo, "rb");

    if (archivoAlum != NULL) {

        if(fseek(archivoAlum, 0, SEEK_END) != 0) {

            printf("Error al moverse al final del archivo.\n");
            fclose(archivoAlum);
            return;  // Se sale de la función en caso de error
        }

        int tamanio = ftell(archivoAlum);

        if (tamanio < 0) {
            printf("Error al obtener el tamanio del archivo.\n");
            fclose(archivoAlum);
            return;  // Se sale de la función en caso de error
        }

         tamanioRegistro = sizeof(Alumno);
//        printf("Cada registro de Alumno pesa: %i bytes \n\n", tamanioRegistro);
         cantidadRegistros = tamanio / tamanioRegistro;

        fclose(archivoAlum);

    }

    return cantidadRegistros;
}

//Exercise 14

void mostrarAlumnoRegistro(char archivo[], int numRegistro) {

int tamanioRegistro = sizeof(Alumno);

Alumno alum;
FILE *archivoAlum;
archivoAlum = fopen(archivo, "rb");

if(archivoAlum != NULL) {

        //Verificación para saber si se movió correctamente al inicio
        if(fseek(archivoAlum, (numRegistro - 1) * tamanioRegistro, SEEK_SET) != 0) {

//El parámetro de fseek (numRegistro - 1) * tamanio registro.
/*Si queremos acceder al registro 1, la posición de desplazamiento sería (0*52) = 0 bytes , porque es el primer elemento*/
/*Si queremos acceder al registro 2, la posición de desplazamiento sería (1*52) = 0 bytes, iniciará a leer el archivo desde el byte 52*/

            printf("Error al moverse al inicio del archivo.\n");
            fclose(archivoAlum);
            return;  // Se sale de la función en caso de error
        }

        fread(&alum, sizeof(Alumno), 1, archivoAlum);
        mostrarAlumno(alum);

   fclose(archivoAlum);
    }
}

//Exercise 15
void cargarAlumnosWB(char alumnos[DIM]) {

char eleccion = 's';

Alumno alum;

FILE *archivoAlum;

archivoAlum = fopen(alumnos, "wb");

if(archivoAlum != NULL) {

    while(eleccion == 's'){

        alum =  cargarAlumno();
        fwrite(&alum, sizeof(Alumno), 1, archivoAlum);

        printf("Pulse 's' si desea ingresar otro Registro ---> ");
        fflush(stdin);
        scanf("%c", &eleccion);
        printf("\n\n");
    }

    fclose(archivoAlum);

    printf("Registro cargado con exito \n\n");
    }
}

//Exercise 15
void sobreescribirRegistro(char archivo[], int numRegistro) {

int tamanioRegistro = sizeof(Alumno);

Alumno alum;
FILE *archivoAlum;
archivoAlum = fopen(archivo, "wb");

if(archivoAlum != NULL) {

        //Verificación para saber si se movió correctamente al inicio
        if(fseek(archivoAlum, (numRegistro - 1) * tamanioRegistro, SEEK_SET) != 0) {

//El parámetro de fseek (numRegistro - 1) * tamanio registro.
/*Si queremos acceder al registro 1, la posición de desplazamiento sería (0*52) = 0 bytes , porque es el primer elemento*/
/*Si queremos acceder al registro 2, la posición de desplazamiento sería (1*52) = 0 bytes, iniciará a leer el archivo desde el byte 52*/

            printf("Error al moverse al inicio del archivo.\n");
            fclose(archivoAlum);
            return;  // Se sale de la función en caso de error
        }

        fwrite(&alum, sizeof(Alumno), 1, archivoAlum);

        printf("Sobreescribiendo Registro... \n\n");
        cargarAlumno(alum);

        mostrarAlumnoRegistro(archivo, numRegistro);

   fclose(archivoAlum);
}
}
//Exercise 16

void invertirArchivo(char archivo[], int registros) {

Alumno auxiliar1, auxiliar2;

int contDecremento = registros;
int contIncremento = 0;

FILE *archivoAlumnos;
archivoAlumnos = fopen(archivo, "r+b");

if(archivoAlumnos != NULL) {


while(contIncremento < contDecremento) {

fseek(archivoAlumnos, contIncremento, SEEK_SET);

fread(&auxiliar1, sizeof(Alumno), 1, archivoAlumnos);


fseek(archivoAlumnos, sizeof(Alumno) * (contDecremento - 1), SEEK_SET);

fread(&auxiliar2, sizeof(Alumno), 1, archivoAlumnos);


fseek(archivoAlumnos, contIncremento, SEEK_SET);

fwrite(&auxiliar2, sizeof(Alumno), 1, archivoAlumnos);

fseek(archivoAlumnos, sizeof(Alumno) * (contDecremento - 1), SEEK_SET);

fwrite(&auxiliar1, sizeof(Alumno), 1, archivoAlumnos);

contIncremento++;

contDecremento--;

}
fclose(archivoAlumnos);
}
}




















