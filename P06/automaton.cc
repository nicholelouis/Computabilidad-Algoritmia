// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Diseño e implementación de un simulador de DFAs
// Autor: Nichole Arboleda Louis
// Correo: alu0101796697@ull.edu.es
// Fecha: 16/10/2026
// Archivo automaton.cc
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 16/10/2026 - Creación (primera versión) del código
#include "automaton.h"
#include "alphabet.h"
#include "state.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <map>

Automata::Automata(const Alphabet& alphabet, int num_states, int start_state,const std::string& states): 
alphabet_(alphabet), num_states_(num_states),start_state_id_(start_state) {
  std::istringstream states_stream(states);
  std::string line;
  while (std::getline(states_stream, line)) {
    State state(line);
    if (!states_.emplace(state.GetId(), state).second) {
      throw std::invalid_argument("Estado " + std::to_string(state.GetId()) + " repetido");
    }
  }
  ValidateStates();
  ValidateTransitions();
}

void Automata::ValidateStates() const {
  if (states_.size() != static_cast<std::size_t>(num_states_)) {
    throw std::invalid_argument(
        "El número de estados no coincide: se esperaban " +
        std::to_string(num_states_) + " y hay " +
        std::to_string(states_.size()));
  }
  if (states_.count(start_state_id_) == 0) {
    throw std::invalid_argument("El estado inicial " +
    std::to_string(start_state_id_) + " no existe");
  }
}

void Automata::ValidateTransitions() const {
  for (const auto& [id, state] : states_) {
    const std::map<char, int>& transitions = state.GetTransitions();
    for (const auto& [symbol, destination] : transitions) {
      if (!alphabet_.SymbolBelongs(symbol)) {
        throw std::invalid_argument("Estado " + std::to_string(id) +
            ": el símbolo '" + std::string(1, symbol) + "' no pertenece al alfabeto");
      }
      if (states_.count(destination) == 0) {
        throw std::invalid_argument("Estado " + std::to_string(id) +
            ": el destino " + std::to_string(destination) + " no existe");
      }
    }
    if (transitions.size() != alphabet_.GetSize()) {
      throw std::invalid_argument("Estado " + std::to_string(id) +
          ": no tiene transición para todos los símbolos del alfabeto");
    }
  }
}

State Automata::GetStartSatate() const {
    return states_.at(start_state_id_);
}

bool Automata::Accepts(const std::string& input, std::ostream& trace) const {
    bool accept = false;
    std::string status = "RECHAZADA";
    trace << "Est. Actual Entrada Nuevo Est.\n";
    int current_state_id = start_state_id_;
    for (char symbol : input){
        if (!alphabet_.SymbolBelongs(symbol)){
            trace << "El símbolo '" << symbol << "' no pertenece al alfabeto.\n";
            trace << "Cadena de entrada " + status + ".\n";
            return accept;
        }
        int next_state_id = states_.at(current_state_id).GetNextState(symbol);
        trace << current_state_id << " " << symbol << " " << next_state_id << "\n";
        current_state_id = next_state_id;
    }
    if (states_.at(current_state_id).IsAccepting()){
        status = "ACEPTADA";
        accept = true;
    }
    trace << "Cadena de entrada " + status + ".\n";
    return accept;
}

std::ostream& operator<<(std::ostream& os, const Automata& automata){
  os << "Alphabet: " << automata.alphabet_<< " States: " << automata.num_states_ << std::endl;
  os << "States: \n ";
  for (const auto& state : automata.states_) {
    os <<  state.second;
    os << "\n";
  }
  return os;
}