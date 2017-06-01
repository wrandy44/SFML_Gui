/*
** BoxClosable.cpp for BoxClosable.cpp in /home/debrau_c/my/Mia/Gui2.0
**
** Made by debrau_c
** Login <debrau_c>
**
** Started tomorrow
*/
#include "gui/BoxClosable.hh"

namespace gui{
  BoxClosable::BoxClosable(unsigned int w, unsigned int h)
  : Box(w, h), _closeButton(20, 20, "buttonClose.png")
  {
    _closeButton.setPosition(sf::Vector2i(w - 20, 0));

  }
  BoxClosable::BoxClosable(const BoxClosable &obj): Box(obj), _closeButton(obj._closeButton){
  }

  BoxClosable &BoxClosable::operator=(const BoxClosable &obj){
    Box::operator=(obj);
    _closeButton = obj._closeButton;
    return *this;
  }
  BoxClosable::~BoxClosable(){}

  void BoxClosable::draw(sf::RenderTarget &w, Bank &b)
  {
    if (!_display) return ;
    Box::draw(w, b);
      _closeButton.draw(_bufferImg, b);
      _bufferImg.display();
    /*
    for (std::vector<std::shared_ptr<Object> >::iterator i = _child.begin(); i != _child.end(); i++)
      (*i)->draw(_bufferImg, b);
      */
    sf::Sprite tmp(_bufferImg.getTexture());
    tmp.setPosition(_pos.x, _pos.y);
    w.draw(tmp);
  }

  bool BoxClosable::event(sf::Event const &e, sf::Vector2i const &parent)
  {
    if (!_display)
      return false;
    if (_closeButton.event(e, _pos))
    {
      _display = false;
      return true;
    }
    return Box::event(e, parent);
  }
}// !gui
