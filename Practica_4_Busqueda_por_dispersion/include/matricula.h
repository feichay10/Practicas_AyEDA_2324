#ifndef MATRICULA_H
#define MATRICULA_H

#include <iostream>

class Matricula {
  public:
    Matricula();
    Matricula(std::string matricula);

    bool operator==(const Matricula& matricula) const;
    bool operator!=(const Matricula& matricula) const;
    // operator = 
    Matricula &operator=(const Matricula &matricula);
    Matricula &operator=(const int &matricula);
    operator long() const;
    // operator[]
    unsigned operator[](unsigned i) const;

    friend std::ostream& operator<<(std::ostream& os, const Matricula& matricula);
    friend std::istream& operator>>(std::istream& is, Matricula& matricula);

    auto begin() const { return matricula_.begin(); }
    auto end() const { return matricula_.end(); }

  private:
    std::string matricula_;
};

#endif  // MATRICULA_H