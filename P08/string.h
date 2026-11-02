// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 8: Gramática Regular a partir de un DFA
// Autor: Nichole Arboleda Louis
// Correo: alu0101796697@ull.edu.es
// Fecha: 29/10/2026
// Archivo dfa2grammar.cc: programa cliente.
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 29/10/2026 - Creación (primera versión) del código

#ifndef string_H
#define string_H
#include <string>
#include <ostream>
#include <set>

class Str
{
public:
  Str(const std::string &sequence);
  std::string GetStr() const;
  int GetLenght() const;
  std::string ReverseStr();
  std::set<Str> StrPrefix();
  std::set<Str> StrSuffix();
  friend std::ostream &operator<<(std::ostream &os, const Str &sequence);
  bool operator<(const Str &sequence) const;
  bool operator==(const Str &sequence) const;
  bool operator>(const Str &sequence) const;
  ~Str();

private:
  std::string sequence_;
  int lenght_;
};
#endif