//
// Created by Admin on 12/25/2023.
//

#ifndef TETRIS_BLOCK_H
#define TETRIS_BLOCK_H

#include <SFML/Graphics.hpp>

using namespace sf;

enum BlockType { IShape, JShape, LShape, OShape, ZShape, TShape, SShape };

class Block {
private:
    Vector2f position;
    RectangleShape rectangles[4];
    VertexArray shapeVertexArray;

public:
    Block(float x, float y, BlockType blockType);
    VertexArray& getShape();

    void BlockShape(RectangleShape *rectangles, BlockType type);
};


#endif //TETRIS_BLOCK_H
