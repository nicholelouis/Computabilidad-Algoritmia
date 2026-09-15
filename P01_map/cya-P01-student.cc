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
#include <map>
#include <string>
#include "student.h"
#include "fstream"

void ShowHelp() {
  std::cout << "Grades\n";
  std::cout << "The program allows you to read grades files,\n";
  std::cout << "insert the grades individually, and view them (it saves the highest grade)\n";
  std::cout << "File format:\n";
  std::cout << "alu grade example -> alu0101010101 9.25\n";
}

void AddStudentGrade(std::map <Student, double>& students, Student student, double grade){
  auto s = students.find(student);
  if (s == students.end()) {
    student.SetGrade(grade);
    students[student]=grade;
  } else if (s->second < grade) {
      s->second = grade;
  }
}

void ShowGrades(std::map <Student, double> students){
  for (const auto& student : students){
    std::cout << student.first << student.second  << std::endl;
  }
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "Instructions: ./p01_single_grades grades.txt \n Try ’p01_single_grades --help’ for more information.";
    return 1;
  }
  if (std::string(argv[1]) == "--help") {
    ShowHelp();
    return 0;
  }
  std::string name = argv[1];
  std::fstream ficc(name);
  if (!ficc.is_open()) std::cout << "Error: File not found" << std::endl;

  std::map <Student, double> students;

  std::string line;
  while(std::getline(ficc, line)){

    std::stringstream l(line);
    std::string alu, _, grade_str;
    l >> alu >> grade_str >> _;

    double grade = std::stod(grade_str);
    Student student(alu);
    AddStudentGrade(students, student, grade);
  }
  ficc.close();

  int option;
  do {
    std::cout << "\n1. Insert new grade" << std::endl;
    std::cout << "2. Show grades" << std::endl;
    std::cout << "0. Go out" << std::endl;
    std::cout << "Option: ";
    std::cin >> option;

    switch (option) {

      case 1: {
        std::string alu;
        double grade;

        std::cout << "Alu ID: ";
        std::cin >> alu;
        std::cout << "Grade: ";
        std::cin >> grade;

        Student student(alu);
        AddStudentGrade(students, student, grade);
        ShowGrades(students);
        break;
      }

      case 2:
        ShowGrades(students);
        break;

      case 0:
        break;
    }
  } while (option != 0);

  return 0;
}