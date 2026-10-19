// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Diseño e implementación de un simulador de DFAs
// Autor: Nichole Arboleda Louis
// Correo: alu0101796697@ull.edu.es
// Fecha: 16/10/2026
// Archivo automaton.h
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 16/10/2026 - Creación (primera versión) del código

#ifndef automata_H
#define automata_H
#include <string>
#include <ostream>
#include <vector>
#include <set>
#include "alphabet.h"
#include "state.h"

class Automata {
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
    friend std::ostream &operator<<(std::ostream &os, const Automata &state);

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
  };
#endif