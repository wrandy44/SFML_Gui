/*
** BoxScrollable.cpp for BoxScrollable.cpp in /home/debrau_c/my/Mia/Gui2.0
**
** Made by debrau_c
** Login <debrau_c>
**
** Started tomorrow
*/
#include "gui/BoxScrollable.hh"

namespace gui{
  BoxScrollable::BoxScrollable(unsigned int w, unsigned int h)
  : Box(w, h), _upButton(20, 20, "buttonUp.png"), _downButton(20, 20, "buttonDown.png"), _cursorScroll(20, 20, "cursorScroll.png")
  {
    _upButton.setPosition(sf::Vector2i(w - 20, 0));
    _upButton.setFunction(&BoxScrollable::downCursor, this);
    _downButton.setPosition(sf::Vector2i(w - 20, h - 20));
    _downButton.setFunction(&BoxScrollable::upCursor, this);
    _cursorScroll.setPosition(sf::Vector2i(w - 20, 0));
    _cursorPos = 0;
    _cursorMax = 50;
    _cursorMin = 0;
    _cursorJump = 10;
    updateCursorScroll();
  }
  BoxScrollable::BoxScrollable(const BoxScrollable &obj)
  : Box(obj), _upButton(obj._upButton), _downButton(obj._downButton), _cursorScroll(obj._cursorScroll)
  {}
  BoxScrollable &BoxScrollable::operator=(const BoxScrollable &obj){
    Box::operator=(obj);
    _upButton = obj._upButton;
    _downButton = obj._downButton;
    return *this;
  }
  BoxScrollable::~BoxScrollable(){}
  void BoxScrollable::draw(sf::RenderTarget &w, Bank &b)
  {
    if (!_display) return ;
    Box::draw(w, b);
    _upButton.draw(_bufferImg, b);
    _downButton.draw(_bufferImg, b);
    _cursorScroll.draw(_bufferImg, b);
    _bufferImg.display();
    sf::Sprite tmp(_bufferImg.getTexture());
    tmp.setPosition(_pos.x, _pos.y);
    w.draw(tmp);
  }

  bool BoxScrollable::event(sf::Event const &e, sf::Vector2i const &parent)
  {
    if (!_display)
      return false;
    if (_upButton.event(e, _pos) || _downButton.event(e, _pos))
    {
      alignVertical();
      updateCursorScroll();
      return true;
    }
    for (std::vector<std::shared_ptr<Object> >::iterator i = _child.begin(); i != _child.end(); i++)
      if ((*i)->event(e, _pos))
        return true;
    return false;
  }
  void BoxScrollable::upCursor(){ _cursorPos += (_cursorPos + 1 < _cursorMax)? 1 : 0; }
  void BoxScrollable::downCursor(){ _cursorPos -= (_cursorPos - 1 > _cursorMin)? 1 : 0; }
  void BoxScrollable::alignVertical()
  {
    sf::Vector2i pos(5,5);

    pos.x += 5;
    pos.y += (5 - (_cursorPos * _cursorJump));
    for (std::vector<std::shared_ptr<Object> >::iterator i = _child.begin(); i != _child.end(); i++)
    {
      (*i)->setPosition(pos);
      pos.y += (*i)->getSize().y + 5;
    }
  }
  void BoxScrollable::updateCursorScroll()
  {
    sf::Vector2i newPos = _cursorScroll.getPosition();
    int tmpCurrent = (_cursorPos < 0) ? _cursorPos * -1 : _cursorPos;
    int ecart = (_cursorMin < 0) ? _cursorMin * -1 : _cursorMin;
    ecart += (_cursorMax < 0) ? _cursorMax * -1 : _cursorMax;
    unsigned int size = _size.y - _downButton.getSize().y - _upButton.getSize().y - _cursorScroll.getSize().y;
    newPos.y = (size * tmpCurrent / ecart) + _upButton.getSize().y;
    _cursorScroll.setPosition(newPos);
  }
}// !gui
