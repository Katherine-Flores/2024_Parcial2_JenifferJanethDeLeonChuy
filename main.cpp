#include <iostream>
#include <filesystem>
#include <fstream> // tuve que agregar la libreria fstream ya q se me hace ,as facil
#include <windows.h>
namespace fs = std::filesystem;



void crearArchivos(int cantidad, const  fs::path& directory  )  { //Funcion de crear archivos

          fs::create_directory(directory); //directorio principal
          fs::create_directory(directory / "par"); // directorio Par
          fs::create_directory(directory / "impar"); // directorio Impar

        for (int i = 1; i <= cantidad; ++i) {
        fs::path filePath;
        if (i % 2 == 0) {   // // Si es par se  almacena en el directorio par
            filePath = directory / "par" / ("file" + std::to_string(i) + ".txt");
        } else {
            filePath = directory / "impar" / ("file" + std::to_string(i) + ".txt"); // si es impar se almacena en el directorio impar
        }
        std::ofstream file(filePath); //Se crea el archivo
            for (int j = 0; j < i; ++j) { // lo de crear las lineas por el numero del archivo
                file << "Línea " << j + 1 << " del archivo " << i << std::endl;
            }
        file.close(); // Cerramos el archivo después de crearlo
    }

    std::cout << "Archivos creados correctamente.\n";
}
int main() {
    int cantidad;
    std::cout << "Ingrese la cantidad de archivos que quiere crear: ";
    std::cin >> cantidad;

    fs::path directory = "C:\\Users\\Kathe\\Desktop\\Archivos";
    crearArchivos(cantidad, directory); // aqui se llama a la funcio de CrearArchivos

    return 0;
}
