#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h> // Header para el sleep
#include <typeinfo.h>

#include "Serie.h"
#include "Videos.h"
#include "Pelicula.h"
#include "Episodio.h"

void mostrarLosVideos(Videos *listaVideos[], int cantVideos_)
{
    cout << "Los videos disponibles son:" << endl;
    for (int i = 0; i < cantVideos_; i++)
    {
        listaVideos[i]->muestraInformacion();
        cout << endl;
        sleep(1);
    }
}

void mostrarVideosConCalif(Videos *listaVideos[], int cantVideos_)
{

    int calificacionB;
    cout << "¿Qué calificación (1-5) quieres que busquemos?" << endl;
    cout << "Calificacion: ";
    cin >> calificacionB;
    while ((calificacionB <= 0) || (calificacionB > 5))
    {
        cout << endl;
        cout << "Introduce una calificacion valida, porfavor: ";
        cin >> calificacionB;
    }
    cout << "A continuación veras los videos con calificacion: " << calificacionB << endl;
    cout << endl;
    for (int i = 0; i < cantVideos_; i++)
    {
        if (listaVideos[i]->getCalificacion() == calificacionB)
        {
            cout << "- " << listaVideos[i]->getNombre() << endl;
            cout << endl;
            sleep(1);
        }
    }
}

void mostrarVideosConGenero(Videos *listaVideos[], int cantVideos_)
{
    string opgenero = "";
    cout << "¿Qué genero deseas consultar?" << endl;
    cout << "1. Ciencia_ficcion " << endl;
    cout << "2. Accion" << endl;
    cout << "3. Drama " << endl;
    cout << "4. Animacion" << endl;
    cout << "5. Comedia" << endl;
    cout << "Genero: ";
    cin >> opgenero;
    cout << endl;
    cout << "A continuación veras los videos con el genero: " << opgenero << endl;
    cout << endl;
    for (int j = 0; j < cantVideos_; j++)
    {
        if (listaVideos[j]->getGenero() == opgenero)
        {
            cout << "- " << listaVideos[j]->getNombre() << endl;
            cout << endl;
            sleep(1);
        }
    }
}

void mostrarEpisodiosDeSeries(Videos *listaVideos[], Serie *arrSeries[], int cantVideos_, int cantSeries)
{
    string conserie = "";
    Episodio *episode;
    int califEpisodio = 0;
    cout << "¿Qué serie quieres consultar? Serie: " << endl;
    cin >> conserie;
    cout << "'¿Qué calificación quieres que despleguemos? Calificación: ";
    cin >> califEpisodio;

    for (int i = 0; i < cantVideos_; i++)
    {
        if (arrSeries[i]->getNombreSerie() == conserie)
        {
            arrSeries[i]->imprimir(califEpisodio);
        }
    }
}

void peliculasConCalif(Videos *listaVideos[], int cantVideos)
{
    int calificacionP = 0;
    Pelicula *unaPeli;
    cout << "¿Que calificacion (1-5) quieres para desplegar las peliculas? Calificacion: ";
    cin >> calificacionP;
    while ((calificacionP <= 0) || (calificacionP > 5))
    {
        cout << endl;
        cout << "Introduce una calificacion valida, porfavor: ";
        cin >> calificacionP;
    }

    for (int i = 0; i < cantVideos; i++)
    {
        if (typeid(*listaVideos[i]) == typeid(Pelicula))
        {
            unaPeli = (Pelicula *)listaVideos[i];
            if (unaPeli->getCalificacion() == calificacionP)
            {
                unaPeli->muestraInformacion();
                sleep(1);
                cout << endl;
            }
        }
    }
}

void despliegaSeries(Serie *arrSeries[], int cantSeries)
{
    cout << endl;
    for (int s = 0; s < cantSeries; s++)
    {
        cout << "iD:" << arrSeries[s]->getId() << ", "
             << "Serie: " << arrSeries[s]->getNombreSerie() << endl;
        cout << endl;
    }
}

void seriesYepisodios(Serie *arrSeries[], int cantSeries)
{
    for (int s = 0; s < cantSeries; s++)
    {
        cout << endl;
        arrSeries[s]->mostrar();
        cout << endl;
    }
}

int main()
{
    char t;

    //Arreglos de Apuntadores
    Videos *listaVideos[60];
    Serie *arrSeries[60];
    //Para Videos
    int cantVideos_;
    //Para Peliculas
    int contPeliculas;
    //Para Series
    int cantSeries;
    //Misc
    char opcionMenu;

    //Videos en General
    string iD_, nombre_, duracion_, genero_, titulo_;
    //Mas para episodios
    string nombreSerie_, nombreS_, iDD_;
    //Casting para serie
    Episodio *unEpi;
    //MISC
    int calificacion_, calificacionEp_;
    int temporada_, cantEpisodios_;
    char tipoVideo;
    cout << "Iniciando carga" << endl;

    ifstream datosSeries;
    datosSeries.open("datosSeries.txt");
    while (datosSeries >> iDD_ >> nombreSerie_)
    {
        arrSeries[cantSeries] = new Serie(iDD_, nombreSerie_);
        cantSeries += 1;
    }
    datosSeries.close();

    ifstream datosVideos("datostest.txt");
    while (datosVideos >> tipoVideo)
    {
        if (tipoVideo == 'e')
        {
            datosVideos >> iD_ >> nombre_ >> genero_ >> duracion_ >> calificacion_ >> titulo_ >> temporada_ >> calificacionEp_;
            //¿Como definiria el array de apuntadores de episodio aqui de la clase serie
            unEpi = new Episodio(iD_, nombre_, genero_, duracion_, calificacion_, titulo_, temporada_, calificacionEp_);
            listaVideos[cantVideos_] = unEpi;
            cantVideos_ += 1;
            for (int i = 0; i < cantSeries; i++)
            {
                if (arrSeries[i]->getNombreSerie() == titulo_)
                {
                    arrSeries[i]->agregaEpisodio(unEpi);
                }
            }
        }
        else if (tipoVideo == 'p')
        {
            datosVideos >> iD_ >> nombre_ >> genero_ >> duracion_ >> calificacion_;
            listaVideos[cantVideos_] = new Pelicula(iD_, nombre_, genero_, duracion_, calificacion_);
            cantVideos_ += 1;
        }
    }

    datosVideos.close();

    do
    {
        cout << endl;
        cout << "a) Cargar archivos" << endl;
        cout << "b) Mostrar todos los videos" << endl;
        cout << "c) Mostrar Videos con Cierta Calificación " << endl;
        cout << "d) Mostrar Videos con Cierto Género" << endl;
        cout << "e) Mostrar Episodios de Serie con Calificación Determinada " << endl;
        cout << "f) Mostrar peliculas con cierta calificacion " << endl;
        cout << "g) Despliega todas las series" << endl;
        cout << "h) Despliega Series y con Episodios" << endl;
        cout << "i) Calificar un Video" << endl;
        cout << "j) Terminar Sesión " << endl;
        cout << endl;
        cout << "Opcion -> ";
        cin >> opcionMenu;
        cout << endl;
        switch (opcionMenu)
        {
        case 'a':
        {
            cout << "Los archivos se han cargado correctamente" << endl;
            break;
        }
        case 'b':
        {
            mostrarLosVideos(listaVideos, cantVideos_);
            cout << endl;
            break;
        }

        case 'c':
        {
            mostrarVideosConCalif(listaVideos, cantVideos_);
            break;
        }
        case 'd':
        {
            mostrarVideosConGenero(listaVideos, cantVideos_);
            break;
        }
        case 'e':
        {
            mostrarEpisodiosDeSeries(listaVideos, arrSeries, cantVideos_, cantSeries);
            break;
        }
        case 'f':
        {
            peliculasConCalif(listaVideos, cantVideos_);
            break;
        }
        case 'g':
        {
            despliegaSeries(arrSeries, cantSeries);
            break;
        }

        case 'h':
        {
            seriesYepisodios(arrSeries, cantSeries);
            break;
        }
        case 'i':
        {
            //Promedio
        }
        case 'j':
        {
            cout << endl;
            cout << "Gracias por preferir nuestro servicio. ¡Vuelva pronto!" << endl;
            cout << endl;
            return 0;
        }
        }
    } while (opcionMenu != 'z');
    return 0;
}
