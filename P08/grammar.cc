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
#include "grammar.h"
#include <fstream>
#include <stdexcept>

Grammar::Grammar(const Alphabet &terminals, const std::vector<std::string> &non_terminals,
                 const std::string &start_symbol, const std::vector<Production> &productions)
    : terminals_(terminals), non_terminals_(non_terminals), start_symbol_(start_symbol), productions_(productions) {}

void Grammar::WriteToFile(const std::string &filename) const
{
  std::ofstream file(filename);
  if (!file.is_open())
  {
    throw std::invalid_argument("No se puede crear el fichero " + filename);
  }
  file << *this;
}

std::ostream &operator<<(std::ostream &os, const Grammar &grammar)
{
  os << grammar.terminals_.GetSize() << "\n";
  for (char symbol : grammar.terminals_.GetAlphabet())
  {
    os << symbol << "\n";
  }
  os << grammar.non_terminals_.size() << "\n";
  for (const std::string &non_terminal : grammar.non_terminals_)
  {
    os << non_terminal << "\n";
  }
  os << grammar.start_symbol_ << "\n";
  os << grammar.productions_.size() << "\n";
  for (const Production &production : grammar.productions_)
  {
    os << production << "\n";
  }
  return os;
}