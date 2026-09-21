// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Inform´atica
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

#include "language.h"
#include <set>

Language::Language(Alphabet alphabet, const std::set<Str> string_set): alphabet_(alphabet), string_set_(string_set){}

std::string Language::GetLanguage() const {
    return " ";
}

std::ostream& operator<<(std::ostream& os, const Language& language){
  os << "{";
  const char* space = "";
  for(Str c : language.string_set_) {
    os << space << c;
    space = ", ";   
  }
  os <<  "}";
  return os;
};

Language::~Language() {
}