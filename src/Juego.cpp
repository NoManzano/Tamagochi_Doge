#include "Juego.h"

// 1. Corrección en sf::VideoMode para SFML 3
Juego::Juego() : ventana(sf::VideoMode({1408, 768}), "Tamagotchi") {
    tiempoTranscurrido = 0.0f;
}

void Juego::ejecutar() {
    while (ventana.isOpen()) {
        procesarEventos();

        float dt = reloj.restart().asSeconds();
        tiempoTranscurrido += dt;

        if (tiempoTranscurrido >= 1.0f) {
            tiempoTranscurrido = 0.0f;
            actualizar(); // <-- Se llama sin pasarle 'dt'
        }

        dibujar();
    }
}

void Juego::procesarEventos() {
    // 2. Nueva sintaxis de eventos en SFML 3
    while (const auto evento = ventana.pollEvent()) {
        
        // Evento de cerrar la ventana
        if (evento->is<sf::Event::Closed>()) {
            ventana.close();
        }

        // Evento de presionar una tecla
        if (const auto* keyPressed = evento->getIf<sf::Event::KeyPressed>()) {
            if (keyPressed->code == sf::Keyboard::Key::A) {
                mascota.acariciar();
            } else if (keyPressed->code == sf::Keyboard::Key::C) {
                mascota.comer();
            } else if (keyPressed->code == sf::Keyboard::Key::D) {
                mascota.defecar();
            } else if (keyPressed->code == sf::Keyboard::Key::S) {
                mascota.dormir();
            }
            else if (keyPressed->code == sf::Keyboard::Key::E) {
                mascota.enfermar();
            } else if (keyPressed->code == sf::Keyboard::Key::M) {
                mascota.morir();
            } else if (keyPressed->code == sf::Keyboard::Key::N) {
                mascota.nacer();
            }
        }
    }
}

void Juego::actualizar() {
    mascota.actualizar();
}

void Juego::dibujar() {
    ventana.clear(sf::Color(230, 230, 230)); // Limpia con un fondo gris claro
    mascota.dibujar(ventana);
    ventana.display();
}