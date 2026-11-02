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

#ifndef automata_H
#define automata_H
#include <string>
#include <ostream>
#include <vector>
#include <set>
#include "alphabet.h"
#include "state.h"
#include "grammar.h"

/**
 * @brief Autómata finito M = (Σ, Q, s, F, δ).
 */
class Automata
{
public:
  Automata(const Alphabet &alphabet, int num_states, int start_state, const std::string &);
  /**
   * @brief Comprueba que el conjunto de estados es valido.
   *
   * Verifica que el número de estados leídos coincide con el
   * declarado y que el estado de arranque existe.
   * @throw std::invalid_argument si el número de estados no coincide
   * o el estado de arranque no existe.
   */
  void ValidateStates() const;
  /**
   * @brief Comprueba que las transiciones de los estados son validas.
   *
   * Verifica que los simbolos de las transicones pertenecen al alfabeto,
   * que el estado siguiente existe y que cada estado tiene transición
   * para todos los simbolos del alfabeto.
   * @throw std::invalid_argument si los simbolos de las transicones
   * no pertenecen al alfabeto, si el estado siguiente no existe o el
   * si a algún estado le falta una transición para algun simbolo del
   * alfabeto.
   */
  void ValidateTransitions() const;
  /**
   * @brief Devuelve el estado de arranque del autómata.
   * @return output Estado de arranque.
   */
  State GetStartSatate() const;
  /**
   * @brief Simula el autómata sobre una cadena y escribe la traza.
   *
   * Recorre la cadena símbolo a símbolo desde el estado inicial,
   * escribiendo en cada paso el estado actual, el símbolo leído y
   * el estado destino. Si encuentra un símbolo que no pertenece al
   * alfabeto, la cadena se rechaza.
   *
   * @param input Cadena a evaluar.
   * @param trace Flujo de salida donde se escribe la traza.
   * @return true si la cadena es aceptada, false en caso contrario.
   */
  bool Accepts(const std::string &input, std::ostream &trace) const;
  /// @brief Comprueba que no haya transiciones & ni símbolos repetidos en un estado.
  bool IsDFA() const;
  friend std::ostream &operator<<(std::ostream &os, const Automata &state);
  /**
   * @brief Genera una gramática regular equivalente al DFA.
   * @return Gramática G tal que L(G) = L(M).
   * @throw std::logic_error si el autómata no es un DFA.
   */
  Grammar ConvertToGrammar() const;

private:
  /// Alfabeto de entrada del autómata
  Alphabet alphabet_;
  /// Número de estados totales del autómata
  int num_states_;
  /// Estados del autómata
  std::map<int, State> states_;
  /// Id del estado de arranque del autómata
  int start_state_id_;
  /// Estados de aceptación del autómata
  std::set<State> accept_states_;
  /// Nombre del no terminal asociado a un estado
  std::string StateToNonTerminal(int state_id) const;
  /// No terminales de la gramática
  std::vector<std::string> BuildNonTerminals() const;
  /// Producciones
  std::vector<Production> BuildProductions() const;
};
#endif