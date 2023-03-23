#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <time.h>

int main()
{

    errno = 0;
    int filec, cdir;
    // create directories
    //  /home/claveroox/Desktop/SISTEMASOPERATIVOS/PracticandoComandos

    char dirName[350], path[255], CreateDIrectory[350];
    // char array[] = {"hi good afternoon","Hola que hace","Pendejo copetezzzz"}; //char inside file
    char array[10][50] = {"hi good afternoon", "Hola que hace", "Me guta brenda", "Me gusta el pavo", "Me gusta el elote", "Pedro Pica Piedra", "Elote en vaso","Atole de nuez","Perico y tachas","NO se que poner, no se enoje"}; // char inside file

    srand(time(0));
    int r = (rand() % 10) + 1; // random number
    printf("\narchivos a crear%d", r);

    // creating directory

    printf("\ntype path: "); // path for new directory
    scanf("%s", dirName);

    // recuperamos el nombre del directorio a crear
    char *dir = strrchr(dirName, '/');
    if (dir == NULL)
    {
        printf("Error: no se ha encontrado el directorio");
        return 1;
    }
    // imprimimos el nombre del directorio
    printf("Directorio: %s\n", dir);

    // recuperamos la direccion del directorio
    char *DDIrectory = strndup(dirName, dir - dirName);
    if (DDIrectory == NULL)
    {
        printf("Error: no se ha encontrado la direccion del directorio");
        return 1;
    }

    // imprimimos la direccion del directorio
    printf("Direccion: %s\n", DDIrectory);

    // verificamos si el directorio ya existe
    if (access(dirName, F_OK) != -1)
    {
        printf("\nEl directorio ya existe");
        return 1;
    }
    else
    {
        printf("\nEl directorio no existe");

        // creamos el directorio
        cdir = mkdir(dirName, 0777);      // directory permissions & name
        if (cdir != 0 && errno == EEXIST) // check whether directory exists
            printf("directory already exists");
        else
        {
            printf("directory created!");
        }

        // creamos los archivos en la ruta especificada
        for (int i = 1; i <= r; i++)
        {
            char fileName[255];
            char auxdirName[350];
            strcpy(auxdirName, dirName);
            //pedimos el nombre del archivo
            printf("\ntype file name: "); // name for new file
            scanf("%s", fileName);
            //concatenamos la direccion del directorio con el nombre del archivo
            strcat(auxdirName, "/");
            strcat(auxdirName, fileName);
            strcat(auxdirName, ".txt");
            printf("Direccion del archivo: %s\n", auxdirName);

            int archivo;
            archivo = open(auxdirName, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR); // Abrir o crear archivo en modo escritura
            if (archivo < 0)
            {
                printf("No se pudo crear el archivo.\n");
                return 1;
            }

            for (int i = 0; i < 6; i++)
            {
                 int n = (rand() % 10) + 1;
                write(archivo, array[n-1], strlen(array[n-1]));
                //le ponemos un salto de linea
                write(archivo, "\n", strlen("\n"));
            }   

            printf("Archivo creado correctamente.\n");

            // Cerrar el archivo
            close(archivo);
        }
    }

  
    return 0;
}

