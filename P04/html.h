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

#ifndef html_H
#define html_H
#include <string>
#include <vector>
#include "tag.h"
#include "comment.h"

class Html{
  public:
  Html(std::string name, std::string text);
  std::string GetName() const;
  std::vector<Tag> GetTags() const;
  std::string HtmlStructure() const;
  std::string HtmlDescription() const;
  std::string TagsAttibutes() const;
  std::string TagsAnalize() const;
  std::string GetComments() const;
  void ProcessComments(const std::string& text);
  bool TagIsOn(const std::string& tag) const;
  friend std::ostream& operator<<(std::ostream& os, const Html& html);
  private:
  std::string name_;
  std::vector<Tag> tags_;
  std::vector<Comment> comments_;
  std::vector<std::string> target_tags_ = {"html", "head", "title", "body", "h1", "p", "a", "img"};
};
#endif