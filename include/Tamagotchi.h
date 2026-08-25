#ifndef Tamagotchi_h
#define Tamagotchi_h
#include <SFML/Graphics.hpp>

// 1. Definimos los estados posibles
enum class Estado { 
    NACIENDO,
    FELIZ, 
    HAMBRIENTO, 
    DURMIENDO,
    ENFERMO,
    SUCIO,
    MUERTO,
    COMIENDO,
    DEFECANDO
};

// 2. Declaramos la clase Tamagotchi (su "menu")
class Tamagotchi {
private:
    Estado estadoActual;
    int hambre;
    int energia;
    int suciedad;
    float tiempoComiendo;
    float tiempoDefecando;

    // SFML: Una textura por cada imagen y un sprite para dibujar
    sf::Texture texFeliz;
    sf::Texture texHambriento;
    sf::Texture texDurmiendo;
    sf::Texture texMuerto;
    sf::Texture texComiendo;
    sf::Texture texDefecando;
    sf::Sprite sprite;

public:
    // Constructor
    Tamagotchi();

    // Metodos de actualizacion y acciones
    void actualizar();
    void acariciar();
    void comer();
    void defecar();
    void dormir();
    void enfermar();
    void morir();
    void nacer();
    void dibujar(sf::RenderWindow& ventana);

    // Metodos para consultar valores (Getters)
    Estado getEstado() const;
    int getHambre() const;
    int getEnergia() const;
    int getSuciedad() const;
};
#endif // Tamagotchi_h