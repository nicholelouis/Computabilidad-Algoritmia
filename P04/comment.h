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

#ifndef comment_H
#define comment_H
#include <string>

class Comment{
  public:
  Comment(std::string content, int line);
  std::string GetContent() const;
  std::string Line() const;
  friend std::ostream& operator<<(std::ostream& os, const Comment& comment);
  private:
  std::string content_;
  int starting_line_;
  int finish_line_ = 0;
};
#endif