//
// Created by Admin on 12/25/2023.
//

#include "Block.h"

#define BLOCKSIZE 50

Block::Block(float startX, float startY, BlockType blockType) {
    position.x = startX;
    position.y = startY;

    shapeVertexArray.setPrimitiveType(sf::Quads);
    shapeVertexArray.resize(4 * 4);

    for (RectangleShape& rectangle: rectangles) {
        rectangle.setSize(Vector2f(BLOCKSIZE, BLOCKSIZE));
    }

    rectangles[0].setFillColor(Color::Blue);
    rectangles[1].setFillColor(Color::Red);
    rectangles[2].setFillColor(Color::Cyan);
    rectangles[3].setFillColor(Color::Green);

    BlockShape(rectangles, blockType);

    for (int i = 0; i < 4; i++) {
        shapeVertexArray[i * 4 + 0].position = rectangles[i].getTransform().transformPoint(rectangles[i].getPoint(0));
        shapeVertexArray[i * 4 + 1].position = rectangles[i].getTransform().transformPoint(rectangles[i].getPoint(1));
        shapeVertexArray[i * 4 + 2].position = rectangles[i].getTransform().transformPoint(rectangles[i].getPoint(2));
        shapeVertexArray[i * 4 + 3].position = rectangles[i].getTransform().transformPoint(rectangles[i].getPoint(3));

        for (int j = 0; j < 4; j++) {
            shapeVertexArray[i * 4 + j].color = rectangles[i].getFillColor();
        }
    }

}

VertexArray& Block::getShape() {
    return shapeVertexArray;
}

void Block::BlockShape(RectangleShape* rectangles, BlockType type) {
    switch(type) {
        case IShape:
            for (int i = 0; i < 4; i++) {
                rectangles[i].setPosition(position + Vector2f(0, i * BLOCKSIZE));
            }
            break;
        case JShape:
            rectangles[0].setPosition(position + Vector2f(0, 2 * BLOCKSIZE));
            for (int i = 1; i < 4; i++) {
                rectangles[i].setPosition(position + Vector2f(BLOCKSIZE, (i - 1) * BLOCKSIZE));
            }
            break;
        case LShape:
            for (int i = 0; i < 3; i++) {
                rectangles[i].setPosition(position + Vector2f(0, i * BLOCKSIZE));
            }
            rectangles[3].setPosition(position + Vector2f(BLOCKSIZE, 2 * BLOCKSIZE));
            break;
        //case OShape:

    }
}