/*
** Box.cpp for Box.cpp in /home/debrau_c/my/Mia/Gui2.0
**
** Made by debrau_c
** Login <debrau_c>
**
** Started tomorrow
*/
#include "gui/Box.hh"

namespace gui{
  Box::Box(unsigned int w, unsigned int h)
  : LabelImg(w, h, "Box1.png")
  {
  }
  Box::Box(const Box &obj)
  : LabelImg(obj)
  {
    _child = obj._child;
  }

  Box &Box::operator=(const Box &obj)
  {
    LabelImg::operator=(obj);
    _child = obj._child;
    return *this;
  }
  Box::~Box(){}
  void Box::draw(sf::RenderTarget &w, Bank &b)
  {
    if (!_display)
      return ;
    clearBuffer();
    if (_data.size())
    LabelImg::fillBuffer(b);
    for (std::vector<std::shared_ptr<Object> >::iterator i = _child.begin(); i != _child.end(); i++)
    (*i)->draw(_bufferImg, b);
    _bufferImg.display();
    sf::Sprite tmp(_bufferImg.getTexture());
    tmp.setPosition(_pos.x, _pos.y);
    w.draw(tmp);
  }

  bool Box::event(sf::Event const &e, sf::Vector2i const &parent)
  {
    if (!_display) return false;
    for (std::vector<std::shared_ptr<Object> >::iterator i = _child.begin(); i != _child.end(); i++)
      if ((*i)->event(e, _pos))
        return true;
    return false;
  }
  void Box::alignVertical()
  {
    sf::Vector2i pos(5,5);

    pos.x += 5;
    pos.y += 5;
    for (std::vector<std::shared_ptr<Object> >::iterator i = _child.begin(); i != _child.end(); i++)
    {
      (*i)->setPosition(pos);
      pos.y += (*i)->getSize().y + 5;
    }
  }
}// !gui
