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

#include "alphabet.h"
#include <iostream>
#include <algorithm>
#include <set>

Alphabet::Alphabet(const std::string& sym) {
    for(char c : sym) {
        symbols_.insert(c);
    }
}

const std::set<char>& Alphabet::GetAlphabet() const {
    return symbols_;
}

std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet){
  os << "{";
  const char* space = "";
  for(char c : alphabet.symbols_) {
    os << space << c;
    space = ", ";   
  }
  os <<  "}";
  return os;
};

bool Alphabet::SymbolBelongs(char symbol) const{
  return symbols_.find(symbol) != symbols_.end();
}

std::string Alphabet::BelongsToAlphabet(const Str& str) const{
  const std::string& string = str.GetStr();
  for(char c : string) {
    if (!SymbolBelongs(c)){
        return "ERROR";
    }
  }
  return "OK";
}

/*



bool Alphabet::operator<(const Alphabet& alphabet) const{
    
};

bool Alphabet::operator==(const Alphabet& alphabet) const{
    
};

bool Alphabet::operator>(const Alphabet& alphabet) const{
    
};

*/
Alphabet::~Alphabet(){
    
};
