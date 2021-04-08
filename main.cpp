#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
int main() {
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    window.setFramerateLimit(60);
	const double PARTICLE_SPEED = 1;
	const double PARTICLE_PUSH = 2;
	const int PARTICLES = 10000;
	sf::VertexArray bugs(sf::Points,PARTICLES);
	for(int i = 0; i < PARTICLES; i++) {
		bugs[i].position = sf::Vector2f(rand()%200,rand()%200);
	}
    while (window.isOpen())
    {
		sf::Vector2i mouse = sf::Mouse::getPosition(window);
		
		for(int i = 0; i < PARTICLES; i++) {
			if(sqrt(pow(mouse.x-bugs[i].position.x,2)+pow(mouse.y-bugs[i].position.y,2))<30) {
				bugs[i].color=sf::Color(158, 218, 3);
				if(mouse.x>bugs[i].position.x) {
					bugs[i].position.x-=PARTICLE_PUSH;
					if(bugs[i].position.x < 0)
						bugs[i].position.x = 0;
				}
				if(mouse.x<bugs[i].position.x) {
					bugs[i].position.x+=PARTICLE_PUSH;
					if(bugs[i].position.x > window.getSize().x-1)
						bugs[i].position.x = window.getSize().x-1;
				}
				if(mouse.y>bugs[i].position.y) {
					bugs[i].position.y-=PARTICLE_PUSH;
					if(bugs[i].position.y < 0)
						bugs[i].position.y = 0;
				}
				if(mouse.y<bugs[i].position.y) {
					bugs[i].position.y+=PARTICLE_PUSH;
					if(bugs[i].position.y > window.getSize().y-1)
						bugs[i].position.y = window.getSize().y-1;
				}
			} else {
				bugs[i].color=sf::Color(0,0,0);
				if(rand()%2) {
					bugs[i].position.x-=PARTICLE_SPEED;
					if(bugs[i].position.x < 0)
						bugs[i].position.x = 0;
				} else {
					bugs[i].position.x+=PARTICLE_SPEED;
					if(bugs[i].position.x > window.getSize().x-1)
						bugs[i].position.x = window.getSize().x-1;
				}
				if(rand()%2) {
					bugs[i].position.y-=PARTICLE_SPEED;
					if(bugs[i].position.y < 0)
						bugs[i].position.y = 0;
				} else {
					bugs[i].position.y+=PARTICLE_SPEED;
					if(bugs[i].position.y > window.getSize().y-1)
						bugs[i].position.y = window.getSize().y-1;
				}
			}
		}
		
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
		window.draw(bugs);
        window.display();
    }

    return 0;
}