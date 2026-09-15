// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Inform´atica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Contenedores asociativos
// Autor: Nichole Arboleda Louis
// Correo: alu0101796697@ull.edu.es
// Fecha: 12/09/2026
// Archivo cya-P01-student.cc: programa cliente.
// Contiene la función main del proyecto que usa las clases X e Y
// para ... (indicar brevemente el objetivo)
// Referencias:
// Enlaces de interés
// Historial de revisiones
// 12/09/2026 - Creación (primera versión) del código

#include <iostream>
#include <cstdlib>
#include <map>
#include <sstream>
#include <set>
#include <string>
#include "student.h"
#include "fstream"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "Modo de empleo: ./p01_single_grades grades.txt \n Pruebe ’p01_single_grades --help’ para más información.";
    return 1;
  }
  std::string name = argv[1];
  std::fstream ficc(name);
  if (!ficc.is_open()) std::cout << "Error fichero no encontrado" << std::endl;

  std::set <Student> students;

  std::string line;
  while(std::getline(ficc, line)){

    std::stringstream l(line);
    std::string alu, x, grade;
    l >> alu >> grade >> x;

    double g = std::stod(grade);
    auto s = students.find(alu);
    
    if (s == students.end()) {
      Student student(alu);
      student.SetGrade(g);
      students.insert(student);
    } else {
      Student aux = *s;
      aux.SetGrade(g);
    }
    /*
    std::cout << grade << std::endl;
    std::cout << alu << std::endl;
    std::cout << x << std::endl;
    */
  }
  ficc.close();

  for (Student student : students){
    std::cout << student << std::endl;
  }

  return 0;
}