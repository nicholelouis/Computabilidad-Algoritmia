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
#ifndef GRAMMAR_H
#define GRAMMAR_H
#include <iostream>
#include <string>
#include <vector>
#include "alphabet.h"
#include "production.h"

/**
 * @brief Gramática G = (Σ, V, S, P).
 */
class Grammar
{
public:
  /**
   * @param terminals Alfabeto de símbolos terminales.
   * @param non_terminals Símbolos no terminales.
   * @param start_symbol Símbolo de arranque, debe estar en non_terminals.
   * @param productions Reglas de producción.
   */
  Grammar(const Alphabet &terminals, const std::vector<std::string> &non_terminals,
          const std::string &start_symbol, const std::vector<Production> &productions);

  /**
   * @brief Escribe la especificación de la gramática en un fichero .gra
   * @param filename Ruta del fichero de salida.
   */
  void WriteToFile(const std::string &filename) const;

  friend std::ostream &operator<<(std::ostream &os, const Grammar &grammar);

private:
  /// Alfabeto de símbolos terminales.
  Alphabet terminals_;
  /// Símbolos no terminales.
  std::vector<std::string> non_terminals_;
  /// Símbolo de arranque de la gramática.
  std::string start_symbol_;
  /// Reglas de producción de la gramática.
  std::vector<Production> productions_;
};

#endif