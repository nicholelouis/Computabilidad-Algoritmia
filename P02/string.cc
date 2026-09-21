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
// Contiene la función main del proyecto que usa la clase Language, Alphabet y Str
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 18/09/2026 - Creación (primera versión) del código

#include "string.h"
#include "algorithm"
#include <vector>

std::string empty_string = "&";

Str::Str(const std::string& sequence): sequence_(sequence){
  lenght_ = sequence_.length();
}

std::string Str::GetStr() const {
  return sequence_;
}

int Str::GetLenght() const {
  return lenght_;
}

std::string Str::ReverseStr(){
  std::string reverse_str (sequence_.rbegin(), sequence_.rend());
  return sequence_ + " -> " + reverse_str;
}

std::set<Str> Str::StrPrefix(){
  std::set<Str> prefix{empty_string};
  std::string aux;
  for (int i = 0; i < lenght_; ++i){
    aux += sequence_[i];
    prefix.insert(Str(aux));
  }
  return prefix;
}

std::set<Str> Str::StrSuffix(){
  std::set<Str> suffix{empty_string};
  std::string aux;
  for (int i = lenght_ -1; i >= 0; --i){
    aux += sequence_[i];
    std::string reverse_aux (aux.rbegin(), aux.rend());
    suffix.insert(Str(reverse_aux));
  }
  return suffix;
}

std::ostream& operator<<(std::ostream& os, const Str& sequence){
  os << sequence.GetStr();
  return os;
}

bool Str::operator<(const Str& other) const {
  if (lenght_ != other.lenght_) {
    return lenght_ < other.lenght_;
  }
  return sequence_ < other.sequence_;
}

bool Str::operator==(const Str& other) const {
  if (lenght_ == other.lenght_){
    for( int i = 0; i < lenght_; ++i){
      if(sequence_[i] != other.sequence_[i]){
        return false;
      }
    }
    return true;
  }
  return false;
}

bool Str::operator>(const Str& other) const {
  return lenght_ > other.lenght_;
}

Str::~Str() {
}