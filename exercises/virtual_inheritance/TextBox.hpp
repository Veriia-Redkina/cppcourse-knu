#pragma once

#include <string>

class Drawable {
public:
    Drawable(int id);
    void draw() const;
private:
    int m_id;
};

class Rectangle : public virtual Drawable {  //Віртуальне успадкування щоб Drawable буде успадковано лише один раз, незалежно від 
public:                              //кількості разів інших класів (як Rectangle або Text), які будуть його наслідувати    
    Rectangle(int id, float width, float height);
protected:
    float m_width;
    float m_height;
};

class Text : public virtual Drawable {
public:
    Text(int id, std::string content);           //використовувати копію рядка замість посилання
protected:
    std::string m_content;
};

class TextBox : public Rectangle, public Text {
public:
    TextBox(std::string content,
            float width, float height);
};