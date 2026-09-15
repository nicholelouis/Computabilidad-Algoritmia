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

#ifndef student_H
#define student_H
#include <string>
#include <ostream>

class Student{
  public:
    Student(const std::string& alu);
    std::string GetAlu() const;
    double GetGrade() const;
    void SetGrade(double grade);
    friend std::ostream& operator<<(std::ostream& os, const Student& student);
    bool operator<(const Student& student) const;
    bool operator==(const Student& student) const;
    bool operator>(const Student& student) const;
    ~Student();
  private:
    std::string alu_;
    int numAlu_;
    double grade_ = 0;
};
#endif