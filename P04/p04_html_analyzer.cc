// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Expresiones regulares en C++
// Autor: Nichole Arboleda Louis
// Correo: alu0101796697@ull.edu.es
// Fecha: 01/10/2026
// Archivo p04_html_analyzer: programa cliente.
// Contiene la función main del proyecto que usa la clase Html, Tag y Comment
// El programa acepta como argumentos un fichero de entrada .html que se analizará 
// y un fichero de salida donde se almacenará el resultado.
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 01/10/2026 - Creación (primera versión) del código

#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include "html.h"
#include "tag.h"
#include "comment.h"

// ShowHelp Muestra el modo de uso del programa.
void ShowHelp() {
  std::cout << "Regular Expresions C++\n";
  std::cout << "The program accepts as arguments an input .html file to be analyzed\n";
  std::cout << "and an output file where the result will be stored.\n";
  std::cout << "Input format:\n";
  std::cout << "./p04_html_analyzer file_in.html file_out.txt\n";
}

int main(int argc, char* argv[]) {
  if (argc == 2 && std::string(argv[1]) == "--help") {
    ShowHelp();
    return 0;
  }
  if (argc != 3 && argc != 4) {
    std::cout << "Instructions: ./p04_html_analyzer file_in.html file_out.txt [--option]\n"
    << "Try 'p04_html_analyzer --help' for more information.\n";
    return 1;
  }
  std::string ficc_in = argv[1];
  std::string ficc_out = argv[2];

  bool extra_option = false;
  if (argc == 4) {
    std::string option = argv[3];
    if (option == "--option") {
      extra_option = true;
    } else {
      std::cerr << "Error: unknown option '" << option << "'\n"
      << "Try 'p04_html_analyzer --help' for more information.\n";
      return 1;
    }
  }
  
  std::ifstream file_in(ficc_in);
  std::ofstream file_out(ficc_out);
  if (!file_in.is_open()) std::cout << "Error: File not found" << std::endl;
  // Extrae el contenido del fichero de entrada y lo guarda en la variable content
  std::ostringstream buffer;
  buffer << file_in.rdbuf();
  std::string content = buffer.str();
  // Crea un objeto Html mediante el nombre del fichero de entrada y su contenido
  Html html(ficc_in, content);
  // Crea el fichero de salida mediante los métodos del objeto html
  if (file_out.is_open()) {    
    file_out << html.GetName();
    file_out << html.HtmlDescription();
    file_out << html.HtmlStructure();
    file_out << html.TagsAnalize();
    file_out << html.TagsAttibutes();
    file_out << html.GetComments();
    file_out.close();
    } else {
      std::cout << "Error\n";
    }
  file_in.close();
  return 0;
}