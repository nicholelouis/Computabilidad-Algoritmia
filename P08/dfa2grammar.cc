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

#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "alphabet.h"
#include "string.h"
#include "state.h"
#include "automaton.h"
#include "production.h"
#include "grammar.h"

/// Opciones de ejecución recibidas por línea de comandos.
struct Options
{
  /// Mostrar al final el recuento de cadenas aceptadas y rechazadas.
  bool show_summary = false;
};

/**
 * @brief Muestra el modo de uso del programa
 */
void ShowHelp()
{
  std::cout << "DFA to Regular Grammar converter\n";
  std::cout << "The program accepts as arguments an input .dfa file containing a DFA\n";
  std::cout << "and an output .gra file where the equivalent regular grammar will be stored.\n";
  std::cout << "Input format:\n";
  std::cout << "./dfa2grammar input.dfa output.gra\n";
}

/**
 * @brief Interpreta las opciones que siguen a los dos ficheros.
 *
 * @param argc Número de argumentos.
 * @param argv Vector de argumentos.
 * @return Opciones activadas.
 * @throw std::invalid_argument Si alguna opción no se reconoce.
 */
Options ParseOptions(int argc, char *argv[])
{
  Options options;
  for (int i = 3; i < argc; ++i)
  {
    const std::string option = argv[i];
    if (option == "--summary")
    {
      options.show_summary = true;
    }
    else
    {
      throw std::invalid_argument("Opción desconocida: " + option);
    }
  }
  return options;
}

/**
 * @brief Lee de un file el DFA y construye el autómata.
 *
 * Ignora las líneas vacías y las de comentario.
 * Las tres primeras líneas son el alfabeto, el número de estados
 * y el estado de arranque, el resto cada estado.
 *
 * @param file Flujo de entrada con el contenido del fichero input.dfa
 * @return Autómata construido a partir de la especificación del fichero.
 * @throw std::invalid_argument Si el fichero está incompleto, algún
 * campo no es válido.
 */
Automata ReadAutomaton(std::istream &file)
{
  std::string line;
  std::vector<std::string> dfa_lines;
  while (std::getline(file, line))
  {
    if (line.empty() || line.find("//") == 0)
    {
      continue;
    }
    dfa_lines.push_back(line);
  }
  if (dfa_lines.size() < 3)
  {
    throw std::invalid_argument("Fichero .dfa incompleto");
  }
  std::string alphabet_symbols;
  for (char character : dfa_lines[0])
  {
    if (character != ' ' && character != '\t' && character != '\r')
    {
      alphabet_symbols += character;
    }
  }
  Alphabet alphabet(alphabet_symbols);
  int total_states = std::stoi(dfa_lines[1]);
  int start_state_id = std::stoi(dfa_lines[2]);
  std::string states;
  for (std::size_t i = 3; i < dfa_lines.size(); ++i)
  {
    states += dfa_lines[i] + '\n';
  }

  Automata automata(alphabet, total_states, start_state_id, states);
  return automata;
}

/**
 * @brief Simula el autómata sobre cada cadena de un fichero de entrada.
 *
 * Lee línea por línea, ignorando las líneas en blanco, e imprime
 * por pantalla la traza de cada simulación.
 *
 * @param automata Autómata con el que se evalúan las cadenas.
 * @param input_file Flujo de entrada con las cadenas, una por línea.
 * @param options Opciones de ejecución activadas.
 */
void EvaluateInputStrings(const Automata &automata, std::istream &input_file, const Options &options)
{
  int accepted = 0;
  int rejected = 0;
  std::string line;
  while (std::getline(input_file, line))
  {
    if (line.find_first_not_of(" \t\r") == std::string::npos)
    {
      continue;
    }
    std::cout << "Cadena: " << line << '\n';
    if (line == "&")
    {
      line = "";
    }
    if (automata.Accepts(line, std::cout))
    {
      ++accepted;
    }
    else
    {
      ++rejected;
    }
    std::cout << '\n';
  }
  if (options.show_summary)
  {
    std::cout << "Resumen: " << accepted << " aceptadas, " << rejected << " rechazadas.\n";
  }
}

int main(int argc, char *argv[])
{
  if (argc == 2 && std::string(argv[1]) == "--help")
  {
    ShowHelp();
    return 0;
  }
  if (argc < 3)
  {
    std::cout << "Instructions: ././dfa2grammar output.dfa input.gra [--summary]\n"
              << "Try './dfa2grammar --help' for more information.\n";
    return 1;
  }
  std::ifstream ficc_dfa(argv[1]);
  std::string ficc_out(argv[2]);

  if (!ficc_dfa.is_open())
  {
    std::cerr << "Error opening file\n";
    return 1;
  }

  try
  {
    Automata automata = ReadAutomaton(ficc_dfa);
    if (!automata.IsDFA())
    {
      std::cerr << "Error: el autómata de " << argv[1]
                << " no es un DFA, no se puede generar la gramática." << std::endl;
      return 1;
    }
    Grammar grammar = automata.ConvertToGrammar();
    grammar.WriteToFile(ficc_out);
  }
  catch (const std::exception &error)
  {
    std::cerr << "Error: " << error.what() << std::endl;
    return 1;
  }
  return 0;
}
