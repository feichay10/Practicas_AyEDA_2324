#include "Position.h" // Asegúrate de incluir la definición de Position si es necesario
#include <iostream> // Para std::ostream

enum State {
    DEAD,
    ALIVE
};

class Lattice; // Declaración anticipada de la clase Lattice

class Cell {
protected:
    const Position& position;
    State currentState;
    State nextStateValue;

public:
    // Constructor que acepta una posición y un estado
    Cell(const Position& pos, const State& state) : position(pos), currentState(state), nextStateValue(state) {}

    // Destructor virtual para permitir la destrucción polimórfica
    virtual ~Cell() {}

    // Método para obtener el estado actual de la célula
    State getState() const { return currentState; }

    // Método para establecer el estado de la célula
    void setState(State newState) { currentState = newState; }

    // Método virtual para actualizar el estado de la célula al siguiente estado calculado
    virtual void updateState();

    // Método virtual puro para calcular el siguiente estado basado en los estados de las células vecinas
    virtual void nextState(const Lattice&) = 0;

    // Método virtual nulo para la visualización en pantalla
    virtual std::ostream& display(std::ostream&) const = 0;

    // Operador de inserción en flujo como función amiga de la clase base
    friend std::ostream& operator<<(std::ostream& os, const Cell& cell) {
        return cell.display(os);
    }
};

// Implementación por defecto del método de actualización del estado
void Cell::updateState() {
    currentState = nextStateValue;
}

// Clase CellACE que representa un autómata celular elemental
class CellACE : public Cell {
public:
    // Constructor que acepta una posición y un estado
    CellACE(const Position& pos, const State& state) : Cell(pos, state) {}

    // Método para calcular el siguiente estado basado en las reglas del autómata celular elemental
    void nextState(const Lattice&);

    // Método para mostrar el estado actual del autómata celular elemental
    std::ostream& display(std::ostream&) const;
};

// Clase CellACE110 que representa un autómata celular elemental con reglas 110
class CellACE110 : public CellACE {
public:
    // Constructor que acepta una posición y un estado
    CellACE110(const Position& pos, const State& state) : CellACE(pos, state) {}

    // Método para calcular el siguiente estado basado en las reglas del autómata celular elemental 110
    void nextState(State leftState, State rightState);

    // Método para mostrar el estado actual del autómata celular elemental 110
    std::ostream& display(std::ostream&) const;
    
};
