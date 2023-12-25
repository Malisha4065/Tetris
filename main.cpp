#include <SFML/Graphics.hpp>
#include "Block.h"
//#include "Blocks/IShape.h"
//#include "Blocks/JShape.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML L Shape Example");

        // Set the position and color
    Block iShape(0, 0, IShape);
    Block jShape(100, 250, JShape);
    Block jShape2(300, 200, JShape);
    Block lShape(500, 200, LShape);
    //IShape iShape(0, 0);

    //JShape jShape(150, 200);
    //RectangleShape* jShapeRecs = jShape.getShape();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        //window.draw(iShape.getShape());
//
//        for (int i = 0; i < 4; i++) {
//
//            window.draw(jShapeRecs[i]);
//        }
        window.draw(iShape.getShape());
        window.draw(jShape.getShape());
        window.draw(jShape2.getShape());
        window.draw(lShape.getShape());
        window.display();
    }

    return 0;
}