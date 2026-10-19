// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Diseño e implementación de un simulador de DFAs
// Autor: Nichole Arboleda Louis
// Correo: alu0101796697@ull.edu.es
// Fecha: 16/10/2026
// Archivo alphabet.h
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 16/10/2026 - Creación (primera versión) del código

#ifndef alphabet_H
#define alphabet_H
#include <string>
#include <ostream>
#include <vector>
#include <set>
#include "string.h"

class Alphabet{
  public:
    Alphabet(const std::string& symbols);
    const std::set<char>& GetAlphabet() const;
    std::size_t GetSize() const;
    std::string BelongsToAlphabet (const Str& str) const;
    bool SymbolBelongs(char symbol) const;
    friend std::ostream& operator<<(std::ostream& os, const Alphabet& alphabet);
    bool operator<(const Alphabet& alphabet) const;
    bool operator==(const Alphabet& alphabet) const;
    bool operator>(const Alphabet& alphabet) const;
    ~Alphabet();
  private:
    std::set<char> symbols_;
};
#endif