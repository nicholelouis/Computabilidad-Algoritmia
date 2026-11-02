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
#include <string>
#include <map>
#include <sstream>
#include <string>
#include <stdexcept>
#include "state.h"

State::State(const std::string &line)
{
  std::istringstream iss(line);

  int accepting;
  int num_transitions;
  if (!(iss >> id_ >> accepting >> num_transitions))
  {
    throw std::invalid_argument("Línea de estado mal formada: " + line);
  }
  accepting_state_ = (accepting == 1);

  for (int i = 0; i < num_transitions; ++i)
  {
    char symbol;
    int destination;
    if (!(iss >> symbol >> destination))
    {
      throw std::invalid_argument("Estado " + std::to_string(id_) + ": faltan transiciones");
    }
    transitions_.emplace(symbol, destination);
  }
}

int State::GetId() const
{
  return id_;
}

int State::GetNextState(char symbol) const
{
  auto transition = transitions_.find(symbol);
  if (transition == transitions_.end())
  {
    throw std::out_of_range("Estado " + std::to_string(id_) + ": no hay transición con '" + std::string(1, symbol) + "'");
  }
  return transition->second;
}

bool State::IsAccepting() const
{
  return accepting_state_;
}
std::multimap<char, int> State::GetTransitions() const
{
  return transitions_;
}

bool State::operator<(const State &other) const
{
  return id_ < other.id_;
}

std::ostream &operator<<(std::ostream &os, const State &state)
{
  os << "ID: " << state.id_ << " Acceptance: " << state.accepting_state_;
  os << " {";
  const char *space = "";
  for (const auto &elem : state.transitions_)
  {
    os << space << elem.first << "->" << elem.second;
    space = ", ";
  }
  os << "}";
  return os;
}
