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

#ifndef tag_H
#define tag_H
#include <string>
#include <map>

class Tag{
  public:
  Tag(std::string name, bool open, int line);
  std::string GetName()const;
  std::string GetAttributes()const;
  std::string GetLine()const;
  bool Attributes()const;
  bool isOpenTag()const;
  void ProcessTagAttributes(const std::string& text);
  friend std::ostream& operator<<(std::ostream& os, const Tag& tag);
  private:
  std::string str_;
  std::string name_;
  bool open_;
  int line_;
  std::string content_;
  std::map<std::string, std::string> attributes_;
};
#endif