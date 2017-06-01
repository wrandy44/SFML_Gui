/*
** Button.cpp for Button.cpp in /home/debrau_c/my/Mia/Gui2.0
**
** Made by debrau_c
** Login <debrau_c>
**
** Started tomorrow
*/
# include <iostream>
#include "gui/Button.hh"

namespace gui{
  Button::Button(unsigned int w, unsigned int h, std::string const &s)
  :LabelImg(w, h, s)
  {}
  Button::Button(const Button &obj) : LabelImg(obj)
  {
    _func = obj._func;
  }
  Button::Button(int x, int y, unsigned int w, unsigned int h, std::string const &s)
  :LabelImg(w, h, s)
  {
    _pos.x = x;
    _pos.y = y;
  }
  Button &Button::operator=(const Button &obj){
    LabelImg::operator=(obj);
    return *this;
  }
  Button::~Button(){}
  bool Button::event(sf::Event const &e, sf::Vector2i const &parent)
  {
    if (!_display) return false;
    sf::Vector2i tmpMin(_pos + parent);
    sf::Vector2i tmpMax(tmpMin + sf::Vector2i(_size));

    if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left)
      {
        if (tmpMin.x < e.mouseButton.x && tmpMin.y < e.mouseButton.y && tmpMax.x > e.mouseButton.x && tmpMax.y > e.mouseButton.y)
            {
              if (_func)
                _func();
              return true;
            }
      }
    return false;
  }

}
