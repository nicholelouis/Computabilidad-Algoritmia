// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Diseño e implementación de un simulador de DFAs
// Autor: Nichole Arboleda Louis
// Correo: alu0101796697@ull.edu.es
// Fecha: 16/10/2026
// Archivo state.cc
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 16/10/2026 - Creación (primera versión) del código
#include <string>
#include <map>
#include <sstream>
#include <string>
#include <stdexcept>
#include "state.h"

State::State(const std::string& line){
  std::istringstream iss(line);

  int accepting;
  if (!(iss >> id_ >> accepting)) {
    throw std::invalid_argument("Línea de estado mal formada: " + line);
  }
  accepting_state_ = (accepting == 1);

  char symbol;
  int destination;
  while (iss >> symbol >> destination) {
    transitions_[symbol] = destination;
  }
}

int State::GetId() const {
  return id_;
}

int State::GetNextState(char symbol) const {
  return transitions_.at(symbol);
}

bool State::IsAccepting() const{
  return accepting_state_;
}
std::map<char, int> State::GetTransitions() const{
  return transitions_;
}

bool State::operator<(const State& other) const{
  return id_ < other.id_;
}

std::ostream& operator<<(std::ostream& os, const State& state){
  os << "ID: " << state.id_ << " Acceptance: " << state.accepting_state_;
  os << " {";
  const char* space = "";
  for (const auto& elem : state.transitions_) {
    os << space << elem.first << "->" << elem.second;
    space = ", ";
  }
  os <<  "}";
  return os;
}


