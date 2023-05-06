#include <iostream>
#include <windows.h>
#include <filesystem>
#include <fstream>
using namespace std;
namespace fs = std::filesystem;

void crear_archivos(int cantidad_archivos) {
    string directorio_destino;
    if (cantidad_archivos % 2 == 0) {
        directorio_destino = "C:/Users/IONI RODAS/Documents/Par/";
    } else {
        directorio_destino = "C:/Users/IONI RODAS/Desktop/Impar/";
    }
    fs::create_directories(directorio_destino);
    for (int i = 1; i <= cantidad_archivos; i++) {
        string nombre_archivo = directorio_destino + "documento" + to_string(i) + ".txt";
        ofstream archivo(nombre_archivo);
        if (archivo.is_open()) {
            for (int r = 1; r <= i; r++) {
                archivo << "Esta es la línea " << r << " del documento, y cualquier otra cosa xd " << i << endl;
            }
            archivo.close();
        } else {
            cerr << "No se pudo crear el archivo " << nombre_archivo << endl;
        }
    }
}

int main() {
    int cantidad_archivos;
    cout << "Cuantos archivos desea crear paa?" << endl;
    cin >> cantidad_archivos;
    crear_archivos(cantidad_archivos);
    return 0;
}