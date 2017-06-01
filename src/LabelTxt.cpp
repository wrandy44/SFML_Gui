/*
** LabelTxt.cpp for LabelTxt.cpp in /home/debrau_c/my/Mia/Gui2.0
**
** Made by debrau_c
** Login <debrau_c>
**
** Started tomorrow
*/

#include <iostream>
#include "gui/LabelTxt.hh"

namespace gui{
  LabelTxt::LabelTxt(unsigned int w, unsigned int h, std::string const &d): Label(w, h, d){}
  LabelTxt::LabelTxt(const LabelTxt &obj) : Label(obj){}
  LabelTxt &LabelTxt::operator=(const LabelTxt &obj){
    Label::operator=(obj);
    return *this;
  }
  LabelTxt::~LabelTxt(){}
  void LabelTxt::fillBuffer(Bank &b)
  {
    sf::Text text(_data, b.getFont());
    text.setCharacterSize(30);
    text.setColor(sf::Color::Black);
    _bufferImg.draw(text);
    _bufferImg.display();
  }

  void LabelTxt::draw(sf::RenderTarget &w, Bank &b)
  {
    if (!_display) return ;
    fillBuffer(b);
    sf::Sprite spr(_bufferImg.getTexture());
    spr.setPosition(_pos.x, _pos.y);
    w.draw(spr);
  }
}// !gui
