//
// Created by spaceba on 6/04/24.
//

#ifndef PROYECTO_1_PAGINA_H
#define PROYECTO_1_PAGINA_H

#include "Cancion.h"
#include <filesystem>
#include <fstream>
#include "iostream"
#include "INIReader.h"

using namespace std;
namespace fs = filesystem;



class Pagina {
private:
    // Cargar el archivo INI
    INIReader ini_reader = INIReader("/home/spaceba/CLionProjects/Proyecto_1/config.ini");
    string filename_admin = ini_reader.GetString("BIN", "directorio", "/home/spaceba/CLionProjects/Proyecto_1/archivo.bin");
    Cancion* canciones; // Arreglo dinámico de canciones
    int tamanoMaximo; // Tamaño máximo de la página
    int id; //Identidicador de la pagina
    bool cargada;

public:
    Pagina() {}
    // Constructor
    Pagina(int tamano) : tamanoMaximo(tamano) {
        canciones = new Cancion[tamanoMaximo]; // Inicializa el arreglo dinámico con el tamaño deseado
    }

    // Destructor
    ~Pagina() {
        delete[] canciones; // Libera la memoria del arreglo dinámico
    }

    int get_id(){
        return id;
    }
    void set_id(int _id){
        id = _id;
    }
    int get_tamanoMaximo(){
        return tamanoMaximo;
    }
    void set_tamanoMaximo(int _tamanoMaximo){
        tamanoMaximo = _tamanoMaximo;
    }

    Cancion* get_canciones(){
        return canciones;
    }

    void set_canciones(Cancion* _canciones){
        canciones = _canciones;
    }

    bool get_state(){
        return cargada;
    }

    bool set_state(bool _state){
        cargada = _state;
    }

    void cargarContenidoDesdeArchivo();

    void descargarContenidoDesdeArchivo();

};


#endif //PROYECTO_1_PAGINA_H
