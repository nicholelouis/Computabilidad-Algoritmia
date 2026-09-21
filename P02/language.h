// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Cadenas y lenguajes
// Autor: Nichole Arboleda Louis
// Correo: alu0101796697@ull.edu.es
// Fecha: 18/09/2026
// Archivo cya-P02-strings.cc: programa cliente.
// Contiene la función main del proyecto que usa la clase Language, Alphabet y Str
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 18/09/2026 - Creación (primera versión) del código

#ifndef language_H
#define language_H
#include <string>
#include <ostream>
#include <set>
#include "alphabet.h"

class Language{
  public:
    Language(Alphabet alphabet, const std::set<Str> string_set);
    std::set<Str> GetLanguage() const;
    friend std::ostream& operator<<(std::ostream& os, const Language& string_set);
    /*
    bool operator<(const Language& other) const;
    bool operator==(const Language& other) const;
    bool operator>(const Language& other) const;
    */
    ~Language();
  private:
    Alphabet alphabet_;
    std::set<Str> string_set_;
};
#endif