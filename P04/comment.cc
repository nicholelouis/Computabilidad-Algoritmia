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

#include "comment.h"
#include <algorithm>
#include <string>
#include <iostream>
#include <regex>

Comment::Comment(std::string content, int line): content_(content), starting_line_(line) {
  int num_lines = content_.empty() ? 0 : std::count(content_.begin(), content_.end(), '\n') + 1;
  if (num_lines > 1) {
    finish_line_ = starting_line_ + num_lines - 1;
  } 
}

std::string Comment::GetContent() const{
  std::regex target_sequence_comments(R"(<!--([\s\S]*?)-->)");
  std::smatch match;
  std::regex_search(content_, match, target_sequence_comments);
  std::string comment = match[1].str();
  return comment;
}

std::string Comment::Line() const {
  std::string result = "[Line " + std::to_string(starting_line_);
  if (finish_line_ != 0){
    result += "-" + std::to_string(finish_line_);
  }
  result += "]";
  return result;
}

std::ostream& operator<<(std::ostream& os, const Comment& comment){
  os << comment.Line() << "\n" << comment.GetContent();
  return os;
}