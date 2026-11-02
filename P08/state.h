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
#ifndef state_H
#define state_H
#include <string>
#include <map>
#include "string.h"
#include <ostream>

class State
{
public:
  State(const std::string &line);
  /**
   * @brief Devuelve el ID del estado.
   * @return Identidficador del estado.
   */
  int GetId() const;
  /**
   * @brief Devuelve el estado destino de la transición con un símbolo.
   * @param symbol Símbolo del alfabeto que se lee.
   * @return Identidficador del estado siguiente.
   */
  int GetNextState(char symbol) const;
  /**
   * @brief Indica si el estado es de aceptación.
   * @return true si es un estado de aceptación, false si no lo es.
   */
  bool IsAccepting() const;
  /**
   * @brief Devuelve las transiciones del estado.
   * @return Map que asocia cada símbolo con el identificador del
   * estado siguiente.
   */
  std::multimap<char, int> GetTransitions() const;
  bool operator<(const State &state) const;
  friend std::ostream &operator<<(std::ostream &os, const State &state);

private:
  /// Id del estado
  int id_ = 0;
  /// True si es estado de aceptación
  bool accepting_state_;
  /// Tansiciones del estado
  std::multimap<char, int> transitions_;
};
#endif