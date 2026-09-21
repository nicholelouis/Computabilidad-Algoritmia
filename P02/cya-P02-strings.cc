// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Cadenas y lenguajes
// Autor: Nichole Arboleda Louis
// Correo: alu0101796697@ull.edu.es
// Fecha: 18/09/2026
// Archivo cya-P02-strings.cc: programa cliente.
// Contiene la función main del proyecto que usa la clase Student y tres funciones adicionales
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 18/09/2026 - Creación (primera versión) del código

#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include "alphabet.h"
#include "string.h"
#include "language.h"

// ShowHelp Muestra el modo de uso del programa.
void ShowHelp() {
  std::cout << "Alphabets & Strings\n";
  std::cout << "This program takes a file containing strings and alphabets to work with them\n";
  std::cout << "and provides several options. The output is saved in a file called file_out.txt.\n";
  std::cout << "File format:\n";
  std::cout << "\"String alphabet\" example -> abbab ab\n";
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
    std::cout << "Instructions: ./cya-P02-strings file_in.txt \n Try ’cya-P02-strings --help’ for more information.";
    return 1;
  }
  if (std::string(argv[1]) == "--help") {
    ShowHelp();
    return 0;
  }
  std::string name = argv[1];
  std::ifstream file_in(name);
  std::ofstream file_out("file_out.txt");
  if (!file_in.is_open()) std::cout << "Error: File not found" << std::endl;

  int option;
    std::cout << "\n1. Alphabet" << std::endl;
    std::cout << "2. String Lenght" << std::endl;
    std::cout << "3. String Reverse" << std::endl;
    std::cout << "4. String Prefix" << std::endl;
    std::cout << "5. String Suffix" << std::endl;
    std::cout << "6. String Validation" << std::endl;
    std::cout << "0. Go out" << std::endl;
    std::cout << "Option: ";
    std::cin >> option;
    std::cout << "\n";

    std::string line;
    while (getline(file_in, line)){
      std::stringstream l(line);
      std::string s, a;
      l >> s >> a;

      Str str(s);
      Alphabet alphabet(a);

      switch (option) {
        
        case 1: {
          file_out << str << ": " << alphabet << std::endl;
          break;
      }
        case 2:
          file_out << str.GetLenght() << std::endl;
          break;

        case 3:
          file_out << str.ReverseStr() << std::endl;
          break;

        case 4: {
          Language language(alphabet, str.StrPrefix());
          file_out << language << std::endl;
          break;
        }
        case 5: {
          Language language(alphabet, str.StrSuffix());
          file_out << language << std::endl;
          break;
        }
        case 6:
          file_out << alphabet.BelongsToAlphabet(str) << std::endl;
          break;

        case 0:
          break;

        default:
          std::cout << "Invalid argument" << std::endl;
          break;
      }
   }
  file_in.close();
  file_out.close();
  return 0;
}