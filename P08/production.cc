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
#include "production.h"

Production::Production(const std::string &left_side, const std::string &right_side)
    : left_side_(left_side), right_side_(right_side) {}

std::ostream &operator<<(std::ostream &os, const Production &production)
{
  os << production.left_side_ << " -> " << production.right_side_;
  return os;
}