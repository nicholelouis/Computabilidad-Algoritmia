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

#include "html.h"
#include "tag.h"
#include "comment.h"
#include <string>
#include <vector>
#include <regex>
#include <sstream>
#include <iostream>
#include <algorithm>

// Crea un objeto Html a partir de su nombre de fichero y de su contenido,
// analiza el texto recibido y crea los objetos Tag correspondientes
Html::Html(std::string name, std::string text): name_(name) {
  std::regex target_sequence_open(R"(^<(\w+)[^>]*>)");
  std::regex target_sequence_close(R"(</(\w+)>)");

  int num_line = 0;
  std::stringstream ss(text);
  std::string line;
  std::smatch match;

  while (std::getline(ss, line)){
    num_line += 1;
    line.erase(0, line.find_first_not_of(" \t"));
    if (line.empty()) continue;
    if (std::regex_search(line, match, target_sequence_open)) {
      std::string tag = match[0].str();
      if (std::find(target_tags_.begin(), target_tags_.end(), match[1].str()) != target_tags_.end()) {
        Tag t(tag, 1, num_line);
        tags_.push_back(t);
      }
    }
    if (std::regex_search(line, match, target_sequence_close)) {
      std::string tag = match[0].str();
      if (std::find(target_tags_.begin(), target_tags_.end(), match[1].str()) != target_tags_.end()) {
        Tag t(tag, 0, num_line);
        tags_.push_back(t);
      }
    }
  }
  ProcessComments(text);
}
// Devuelve el nombre del objeto Html
std::string Html::GetName() const{
  return "PROGRAM: " + name_ + "\n";
}
// Devuelve la descripción del objeto Html (el primer comentario del objeto)
std::string Html::HtmlDescription() const {
  std::string result = "\nDESCRIPTION: \n";
  result += comments_.front().GetContent() + "\n";
  return result;
}
// Devuelve un texto con la presencia de las etiquetas html,
// head y body, y el tipo de documento
std::string Html::HtmlStructure() const {
  std::string result = "\nSTRUCTURE:\n";
  std::string html = TagIsOn("html") ? "TRUE" : "FALSE";
  std::string head = TagIsOn("head") ? "TRUE" : "FALSE";
  std::string body = TagIsOn("body") ? "TRUE" : "FALSE";
  result += "HTML : " + html + "\n";
  result += "HEAD : " + head + "\n";
  result += "BODY : " + body + "\n";
  result += "DOCTYPE : HTML5 \n";
  return result;
}

std::vector<Tag> Html::GetTags() const {
  return tags_;
}
// Devuelve un texto con los atributos de las etiquetas y su contenido
std::string Html::TagsAttibutes() const {
  std::string result = "\nATTRIBUTES: \n";
  for (Tag t : tags_){
    if (t.Attributes()){
      result += t.GetLine() + " " + t.GetName() + "\n" + t.GetAttributes();
      result += "\n";
    }
  }
  return result;
}
// Devuelve un texto con las etiquetas del html y el número de línea de cada una
std::string Html::TagsAnalize() const {
  std::string result = "\nTAGS: \n";
  for( Tag t : tags_ ){
    result += t.GetLine() + " " + t.GetName() + "\n";
  }
  return result;
}
// Analiza el texto de entrada, busca los comentarios de una o varias líneas
// y crea los objetos Comment correspondientes
void Html::ProcessComments(const std::string& text) {
  std::regex target_sequence_comments(R"(<!--([\s\S]*?)-->)");
  auto begin = std::sregex_iterator(text.begin(), text.end(), target_sequence_comments);
  auto end = std::sregex_iterator();

  size_t last_pos = 0;
  int current_line = 1;

  for (std::sregex_iterator i = begin; i != end; ++i) {
    std::smatch match = *i;
    size_t current_pos = match.position();
    current_line += std::count(text.begin() + last_pos, text.begin() + current_pos, '\n');
    last_pos = current_pos;
    std::string comment_content = match[0].str();
    Comment c(comment_content, current_line);
    comments_.push_back(c);
  }
}
// Devuelve un texto con los comentarios y el número de línea de cada uno
std::string Html::GetComments() const {
  std::string result = "COMMENTS: \n";
  int i = 0;
  std::string new_line;
  for (Comment c : comments_) { 
    if (i == 0){
      new_line = " DESCRIPTION\n";
    } else {
      new_line = "\n";
    }
    result += c.Line() + new_line + "<!--" + c.GetContent() + "-->\n" + "\n";
    i++;
  }
  return result;
}
// Devuelve true si la etiqueta está presente en el objeto
bool Html::TagIsOn(const std::string& tag) const {
  bool result = false;
  for (Tag t : tags_) {
    if (t.GetName() == tag) {
        result = true;
    }
  }
  return result;
}

std::ostream& operator<<(std::ostream& os, const Html& html){
  os << "{";
  const char* space = "";
  for(Tag w : html.tags_) {
    os << space << w;
    space = ", ";   
  }
  os <<  "}";
  return os;
};