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
#ifndef PRODUCTION_H
#define PRODUCTION_H
#include <iostream>
#include <string>

/**
 * @brief Regla de producción de una gramática: no terminal -> secuencia
 */
class Production
{
public:
  /**
   * @param left_side No terminal de la parte izquierda.
   * @param right_side Secuencia de la parte derecha.
   */
  Production(const std::string &left_side, const std::string &right_side);
  const std::string &GetLeftSide() const { return left_side_; }
  const std::string &GetRightSide() const { return right_side_; }

  friend std::ostream &operator<<(std::ostream &os, const Production &production);

private:
  /// No terminal de la parte izquierda de la regla.
  std::string left_side_;
  /// Parte derecha de la regla: terminales y no terminales o &.
  std::string right_side_;
};

#endif