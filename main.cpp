#include <iostream>
#include <windows.h>
#include <filesystem>
#include <limits>
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
                archivo << "Esta es la línea " << r << " del documento che " << i << endl;
            }
            archivo.close();
        } else {
            cerr << "No se pudo crear el archivo pa, sorry " << nombre_archivo << endl;
        }
    }
}

fs::path buscar_archivo_mas_pequeno(string directorio) {
    fs::path archivo_mas_pequeno;
    uintmax_t tamano_mas_pequeno = std::numeric_limits<uintmax_t>::max();
    for (const auto& archivo : fs::directory_iterator(directorio)) {
        if (fs::is_regular_file(archivo)) {
            uintmax_t tamano_archivo = fs::file_size(archivo);
            if (tamano_archivo < tamano_mas_pequeno) {
                archivo_mas_pequeno = archivo.path();
                tamano_mas_pequeno = tamano_archivo;
            }
        }
    }
    return archivo_mas_pequeno;
}

int main() {
    int cantidad_archivos;
    cout << "Cuantos archivos desea crear paa?" << endl;
    cin >> cantidad_archivos;
    crear_archivos(cantidad_archivos);

    string directorio_destino;
    if (cantidad_archivos % 2 == 0) {
        directorio_destino = "C:/Users/IONI RODAS/Documents/Par/";
    } else {
        directorio_destino = "C:/Users/IONI RODAS/Desktop/Impar/";
    }
    fs::path archivo_mas_pequeno = buscar_archivo_mas_pequeno(directorio_destino);

    if (!archivo_mas_pequeno.empty()) {
        cout << "El archivo mas chiquito en " << directorio_destino << " es " << archivo_mas_pequeno << endl;
    } else {
        cerr << "No se encontraron archivos en " << directorio_destino << endl;
    }

    return 0;
}
