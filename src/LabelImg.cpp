/*
** LabelImg.cpp for LabelImg.cpp in /home/debrau_c/my/Mia/Gui2.0
**
** Made by debrau_c
** Login <debrau_c>
**
** Started tomorrow
*/

#include <iostream>
#include "gui/LabelImg.hh"

namespace gui{
  LabelImg::LabelImg(unsigned int w, unsigned int h, std::string const &data)
  :Label(w, h, data)
  {}
  LabelImg::LabelImg(const LabelImg &obj):Label(obj)
  {}
  LabelImg &LabelImg::operator=(const LabelImg &obj){
    Label::operator=(obj);
    return *this;
  }
  LabelImg::~LabelImg(){}


  void LabelImg::draw(sf::RenderTarget &w, Bank &b)
  {
    if (!_display) return ;
    sf::Sprite tmp(b.getFromPath(_data));
    sf::IntRect rect = tmp.getTextureRect();
    tmp.setPosition(static_cast<float>(_pos.x), static_cast<float>(_pos.y));
    sf::Vector2f scale( static_cast<float>(_size.x) / static_cast<float>(rect.width),
                        static_cast<float>(_size.y) / static_cast<float>(rect.height));
    tmp.setScale(scale);
    w.draw(tmp);
  }
  void LabelImg::fillBuffer(Bank &b)
  {
    if (!_display) return ;
    sf::Sprite tmp(b.getFromPath(_data));
    sf::IntRect rect = tmp.getTextureRect();
    sf::Vector2f scale( static_cast<float>(_size.x) / static_cast<float>(rect.width),
                        static_cast<float>(_size.y) / static_cast<float>(rect.height));
    tmp.setScale(scale);
    _bufferImg.draw(tmp);
  }
}// !gui
