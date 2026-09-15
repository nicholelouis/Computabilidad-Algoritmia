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

#include "student.h"

Student::Student(const std::string& alu): alu_(alu) {
  std::string aluu = alu_.substr(3);
  int num = std::stoi(aluu);
  numAlu_=num;
}

std::string Student::GetAlu() const {
  return alu_;
}

double Student::GetGrade() const {
  return grade_;
}

void Student::SetGrade(double grade) {
  if (grade > grade_){
    grade_ = grade;
  }
}

std::ostream& operator<<(std::ostream& os, const Student& student){
  os << student.GetAlu() << " " ;
  return os;
}

bool Student::operator<(const Student& other) const {
  return numAlu_ < other.numAlu_;
}

bool Student::operator==(const Student& other) const {
  return numAlu_ == other.numAlu_;
}

bool Student::operator>(const Student& other) const {
  return numAlu_ > other.numAlu_;
}