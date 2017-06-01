/*
** Input.cpp for Input.cpp in /home/debrau_c/my/Mia/Gui2.0
**
** Made by debrau_c
** Login <debrau_c>
**
** Started tomorrow
*/
#include "gui/Input.hh"

namespace gui{
  Input::Input(unsigned int w, unsigned int h): LabelTxt(w, h, "")
  {
    _onfocus = false;
  }
  Input::Input(const Input &obj): LabelTxt(obj){
    _onfocus = obj._onfocus;
  }
  Input &Input::operator=(const Input &obj){
    LabelTxt::operator=(obj);
    return *this; }
  Input::~Input(){}

  static void checkTextEntered(std::string &val, char code)
  {
    if (code == 8 && val.size() > 0)
    val.pop_back();
    else if (code != 8)
    val.push_back(code);
  }

  bool Input::event(sf::Event const &e, sf::Vector2i const &parent)
  {
    if (!_display) return false;
    sf::Vector2i tmpMin(_pos + parent);
    sf::Vector2i tmpMax(tmpMin + sf::Vector2i(_size));

    if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left)
      {
        if (tmpMin.x < e.mouseButton.x && tmpMin.y < e.mouseButton.y && tmpMax.x > e.mouseButton.x && tmpMax.y > e.mouseButton.y)
          return _onfocus = true, _onfocus;
        else _onfocus = false;
      }
    else if (_onfocus && e.type == sf::Event::TextEntered)
    {
      if (e.text.unicode == 8 && _data.size() > 0)
        _data.pop_back();
      else if (e.text.unicode != 8)
        _data += e.text.unicode;
      return true;
    }
    return false;
  }
  void Input::fillBuffer(Bank &b)
  {
    _bufferImg.clear(sf::Color::White);
    LabelTxt::fillBuffer(b);
    _bufferImg.display();
  }
  void Input::draw(sf::RenderTarget &w, Bank &b)
  {
    if (!_display) return ;
    fillBuffer(b);
    sf::Sprite spr(_bufferImg.getTexture());
    spr.setPosition(_pos.x, _pos.y);
    w.draw(spr);
  }
  void Input::cleanValue()
  {
    _data = "";
  }
}// !gui
