/*
** Label.cpp for Label.cpp in /home/debrau_c/my/Mia/Gui2.0
**
** Made by debrau_c
** Login <debrau_c>
**
** Started tomorrow
*/
#include "gui/Label.hh"

namespace gui{
  Label::Label(unsigned int w, unsigned int h, std::string const &data) : Object(w, h)
  {
    _data = data;
  }
  Label::Label(const Label &obj)
  : Object(obj)
  {
    _data = obj._data;
  }
  Label &Label::operator=(const Label &obj){
    Object::operator=(obj);
    _data = obj._data;
    return *this;
  }
  Label::~Label(){}
  std::string Label::getData() const { return _data; }
  void Label::setData(std::string const &s){ _data = s; }
}// !gui
