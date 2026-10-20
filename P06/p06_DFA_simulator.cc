// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Diseño e implementación de un simulador de DFAs
// Autor: Nichole Arboleda Louis
// Correo: alu0101796697@ull.edu.es
// Fecha: 16/10/2026
// Archivo p06_DFA_simulator.cc: programa cliente.
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 16/10/2026 - Creación (primera versión) del código

#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "alphabet.h"
#include "string.h"
#include "state.h"
#include "automaton.h"

/// Opciones de ejecución recibidas por línea de comandos.
struct Options
{
  /// Mostrar al final el recuento de cadenas aceptadas y rechazadas.
  bool show_summary = false;
};

void ShowHelp()
{
  std::cout << "DFA Simulator\n";
  std::cout << "The program accepts as arguments an input .html file to be analyzed\n";
  std::cout << "and an output file where the result will be stored.\n";
  std::cout << "Input format:\n";
  std::cout << "./p06_DFA_simulator file_in.dfa file_out.txt\n";
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
 * @param file Flujo de entrada con el contenido del fichero ficc.dfa
 * @return Autómata construido a partir de la especificación del fichero.
 * @throw std::invalid_argument Si el fichero está incompleto, algún
 * campo no es válido.
 */
Automata ReadAutomaton(std::istream &file) {
  std::string line;
  std::vector<std::string> dfa_lines;
  while (std::getline(file, line))
  {
    if (line.empty() || line.find("//") == 0) {
      continue;
    }
    dfa_lines.push_back(line);
  }
  if (dfa_lines.size() < 3) {
    throw std::invalid_argument("Fichero .dfa incompleto");
  }
  Alphabet alphabet(dfa_lines[0]);
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
void EvaluateInputStrings(const Automata &automata, std::istream &input_file, const Options &options) {
  int accepted = 0;
  int rejected = 0;
  std::string line;
  while (std::getline(input_file, line)) {
    if (line.find_first_not_of(" \t\r") == std::string::npos) {
      continue;
    }
    std::cout << "Cadena: " << line << '\n';
    if (line == "&") {
      line = "";
    }
    if (automata.Accepts(line, std::cout)){
      ++accepted;
    }
    else {
      ++rejected;
    }
    std::cout << '\n';
  }
  if (options.show_summary)
  {
    std::cout << "Resumen: " << accepted << " aceptadas, " << rejected
              << " rechazadas.\n";
  }
}

int main(int argc, char *argv[]) {
  if (argc == 2 && std::string(argv[1]) == "--help") {
    ShowHelp();
    return 0;
  }
  if (argc < 3) {
    std::cout << "Instructions: ./p06_DFA_simulator file_in.dfa file_out.txt [--summary]\n"
              << "Try 'p06_DFA_simulator --help' for more information.\n";
    return 1;
  }
  std::ifstream ficc_dfa(argv[1]);
  std::ifstream ficc_txt(argv[2]);

  if (!ficc_dfa.is_open() || !ficc_txt.is_open()) {
    std::cerr << "Error opening file\n";
    return 1;
  }

  try {
    const Options options = ParseOptions(argc, argv);
    Automata automata = ReadAutomaton(ficc_dfa);
    EvaluateInputStrings(automata, ficc_txt, options);
  }
  catch (const std::exception &error) {
    std::cerr << "Error: " << error.what() << '\n';
    return 1;
  }

  return 0;
}
