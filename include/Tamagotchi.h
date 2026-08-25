#ifndef Tamagotchi_h
#define Tamagotchi_h
#include <SFML/Graphics.hpp>

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

class Tamagotchi {
private:
    Estado estadoActual;
    int hambre;
    int energia;
    int suciedad;
    float tiempoComiendo;
    float tiempoDefecando;

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

    void actualizar();
    void acariciar();
    void comer();
    void defecar();
    void dormir();
    void enfermar();
    void morir();
    void nacer();
    void dibujar(sf::RenderWindow& ventana);

    Estado getEstado() const;
    int getHambre() const;
    int getEnergia() const;
    int getSuciedad() const;
};
#endif // Tamagotchi_h