#include "TextBox.hpp"
#include <iostream>

Drawable::Drawable(int id) : m_id(id) {};

void Drawable::draw() const {
    std::cout << "Drawing " << m_id << '\n';
};

Rectangle::Rectangle(int id, float width, float height) :
    Drawable(id), m_width(width), m_height(height) {}

Text::Text(int id, std::string content) : // прибираємо const щоб передавалася копія рядка, а не посилання на нього
    Drawable(id), m_content(content) {}

TextBox::TextBox(std::string content,     // прибираємо const
                 float width, float height) :         
                 Drawable(3), Rectangle(1, width, height), Text(2, content) {}   //додаємо Drawable(3), що дозволяє задавати правильний ID для кожного елемента при створенні об'єкта TextBox