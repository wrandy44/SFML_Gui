/*
** Object.cpp for Object.cpp in /home/debrau_c/my/Mia/Gui2.0
**
** Made by debrau_c
** Login <debrau_c>
**
** Started tomorrow
*/
#include "gui/Object.hh"

namespace gui{
  Object::Object(int x, int y, unsigned int w, unsigned int h)
  :_pos(x, y), _size(w, h), _display(true)
  {
    _bufferImg.create(_size.x, _size.y);
  }
  Object::Object()
  :Object(0, 0, 0, 0)
  {
  }

  Object::Object(unsigned int w, unsigned int h)
  :Object(0, 0,w, h)
  {
  }

  Object::Object(const Object &obj)
  {
    _size = obj._size;
    _pos = obj._pos;
    _display = obj._display;
    _bufferImg.create(_size.x, _size.y);
  }

  Object &Object::operator=(const Object &obj){
    _size = obj._size;
    _pos = obj._pos;
    _display = obj._display;
    _bufferImg.create(_size.x, _size.y);
    return *this;
  }

  Object::~Object(){}

  void Object::draw(sf::RenderTarget &w, Bank &b)
  {
    if (!_display) return ;
    _bufferImg.clear(sf::Color::Blue);
    sf::Sprite tmp(_bufferImg.getTexture());
    tmp.setPosition(_pos.x, _pos.y);
    w.draw(tmp);
  }

  void Object::fillBuffer(Bank &b)
  {
    sf::Sprite tmp(_bufferImg.getTexture());
    _bufferImg.draw(tmp);
  }

  bool Object::event(sf::Event const &r, sf::Vector2i const &parent)
  {
    return false;
  }
  //_size
  void Object::setSize(sf::Vector2u const &n){ _size = n; };
  sf::Vector2u const &Object::getSize() const{ return _size; };

  //_pos
  void Object::setPosition(sf::Vector2i const &n){ _pos = n; };
  void Object::setPosition(int x, int y){ setPosition(sf::Vector2i(x, y)); }

  sf::Vector2i const &Object::getPosition() const{ return _pos; };

  //_display
  void Object::displayOn(){ _display = true; }
  void Object::displayOff(){ _display = false; }
  void Object::displayInverse(){ _display = !_display; }
}// !gui
