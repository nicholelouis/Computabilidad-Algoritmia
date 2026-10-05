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

#include "tag.h"
#include <string>
#include <sstream>
#include <iostream>
#include <regex>
#include <vector>
#include <map>

Tag::Tag(std::string str, bool open, int line): str_(str), open_(open), line_(line){
  std::regex target_sequence_open(R"(^<(/?\w+))");
  std::smatch match;
  std::regex_search(str, match, target_sequence_open);
  name_ = match[1].str();
  if (isOpenTag()){
    int pos = str.find(name_);
    std::string attributes(str.begin() + pos, str.end());
    ProcessTagAttributes(attributes);
  }
}

std::string Tag::GetName() const {
  return name_;
}

std::string Tag::GetAttributes() const {
  std::string result = "";
  for (const auto& [attribute, content] : attributes_) {
    result += attribute + " = " + content + "\n";
  }
  return result;
}

std::string Tag::GetLine() const {
  return "[Line " + std::to_string(line_) + "]";
}

bool Tag::Attributes() const {
  return not attributes_.empty();
}

bool Tag::isOpenTag() const {
  return open_;
}

void Tag::ProcessTagAttributes(const std::string& text){
  std::regex target_sequence(R"re((\w+)=("(?:[^"]*)"))re");
  std::vector<std::string> matchs;
  for (auto i = std::sregex_iterator(text.begin(), text.end(), target_sequence); i != std::sregex_iterator(); ++i) {
    matchs.push_back((*i).str());
  }
  for (std::string tag_class : matchs){
    std::smatch match;
    std::regex_search(tag_class, match, target_sequence);
    attributes_[match[1].str()] = match[2].str();
  }
}

std::ostream& operator<<(std::ostream& os, const Tag& tag){
    os << tag.name_;
    return os;
  };