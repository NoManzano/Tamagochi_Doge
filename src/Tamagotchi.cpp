#include "Tamagotchi.h"
#include <iostream>

Tamagotchi::Tamagotchi() : sprite(texFeliz) {
    if (!texFeliz.loadFromFile("assets/feliz.png")) std::cout << "[ERROR] feliz.png" << std::endl;
    if (!texHambriento.loadFromFile("assets/hambriento.png")) std::cout << "[ERROR] hambriento.png" << std::endl;
    if (!texDurmiendo.loadFromFile("assets/durmiendo.png")) std::cout << "[ERROR] durmiendo.png" << std::endl;
    if (!texMuerto.loadFromFile("assets/muerto.png")) std::cout << "[ERROR] muerto.png" << std::endl;
    if (!texComiendo.loadFromFile("assets/comiendo.png")) std::cout << "[ERROR] comiendo.png" << std::endl;
    if (!texDefecando.loadFromFile("assets/defecando.png")) std::cout << "[ERROR] defecando.png" << std::endl;

    sprite.setTexture(texFeliz, true);
    sprite.setPosition({.0f, .0f});

    nacer();
}

void Tamagotchi::nacer() {
    estadoActual = Estado::NACIENDO;
    hambre = 0;
    energia = 100;
    suciedad = 0;
}

void Tamagotchi::comer() {
    if (estadoActual != Estado::DURMIENDO && estadoActual != Estado::MUERTO) {
        hambre -= 30;
        if (hambre < 0) hambre = 0;
        suciedad += 25;

        estadoActual = Estado::COMIENDO;
    }
}

void Tamagotchi::defecar() {
    if (estadoActual != Estado::MUERTO) {
        estadoActual = Estado::DEFECANDO;
    }
}

void Tamagotchi::dormir() {
    if (estadoActual != Estado::MUERTO) {
        estadoActual = Estado::DURMIENDO;
    }
}

void Tamagotchi::enfermar() { estadoActual = Estado::ENFERMO; }
void Tamagotchi::morir() { estadoActual = Estado::MUERTO; }

void Tamagotchi::acariciar() {
    if (estadoActual != Estado::MUERTO) {
        estadoActual = Estado::FELIZ;
    }
}

void Tamagotchi::actualizar() {
    if (estadoActual == Estado::MUERTO) return;

    // Si estuvo comiendo o defecando en el segundo anterior, avanza de estado
    if (estadoActual == Estado::COMIENDO) {
        if (suciedad >= 50) {
            estadoActual = Estado::DEFECANDO;
            return;
        } else {
            estadoActual = Estado::FELIZ;
        }
    } else if (estadoActual == Estado::DEFECANDO) {
        estadoActual = Estado::SUCIO;
        return;
    }

    if (estadoActual == Estado::NACIENDO) {
        estadoActual = Estado::FELIZ;
    }

    hambre += 2;
    energia -= 1;

    if (hambre >= 100) {
        morir();
        return;
    }

    switch (estadoActual) {
        case Estado::FELIZ:
            if (hambre >= 50) estadoActual = Estado::HAMBRIENTO;
            else if (energia <= 20) estadoActual = Estado::DURMIENDO;
        break;

        case Estado::HAMBRIENTO:
            if (energia <= 10) estadoActual = Estado::DURMIENDO;
        break;

        case Estado::DURMIENDO:
            energia += 5;
            if (energia > 100) energia = 100;
            if (energia >= 100) estadoActual = Estado::FELIZ;
        break;

        case Estado::SUCIO:
            if (suciedad >= 80) enfermar();
        break;

        case Estado::ENFERMO:
            energia -= 2;
            if (energia <= 0) morir();
        break;

        default:
        break;
    }
}

void Tamagotchi::dibujar(sf::RenderWindow& ventana) {
    if (estadoActual == Estado::FELIZ || estadoActual == Estado::NACIENDO) {
        sprite.setTexture(texFeliz, true);
    } 
    else if (estadoActual == Estado::HAMBRIENTO) {
        sprite.setTexture(texHambriento, true);
    } 
    else if (estadoActual == Estado::DURMIENDO) {
        sprite.setTexture(texDurmiendo, true);
    } 
    else if (estadoActual == Estado::MUERTO) {
        sprite.setTexture(texMuerto, true);
    } 
    else if (estadoActual == Estado::COMIENDO) {
        sprite.setTexture(texComiendo, true);
    } 
    else if (estadoActual == Estado::DEFECANDO) {
        sprite.setTexture(texDefecando, true);
    } 
    else {
        sprite.setTexture(texFeliz, true); 
    }

    ventana.draw(sprite);
}

Estado Tamagotchi::getEstado() const { return estadoActual; }
int Tamagotchi::getHambre() const { return hambre; }
int Tamagotchi::getEnergia() const { return energia; }
int Tamagotchi::getSuciedad() const { return suciedad; }