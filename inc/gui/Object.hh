/*
** Object.hh for Object.hh in /home/debrau_c/my/Mia/Gui2.0
**
** Made by debrau_c
** Login <debrau_c>
**
** Started tomorrow
*/
#ifndef __OBJECT__HH_
# define __OBJECT__HH_

# include <iostream>
# include <SFML/Graphics.hpp>
# include "Bank.hh"

namespace gui{
  class Object{
  protected:
    sf::Vector2i  _pos;
    sf::Vector2u  _size;
    bool          _display;
    sf::RenderTexture _bufferImg;

    //_bufferImg
    virtual void fillBuffer(Bank &);
    virtual void clearBuffer(){ _bufferImg.clear(sf::Color::Transparent);  }
   public:
    Object();
    Object(unsigned int w, unsigned int h);
    Object(int, int, unsigned int, unsigned int);
    Object(const Object &obj);
    Object	&operator=(const Object &obj);
    ~Object();
    virtual void draw(sf::RenderTarget &, Bank &);
    virtual bool event(sf::Event const &, sf::Vector2i const &parent = sf::Vector2i(0,0));

    //size
    void setSize(sf::Vector2u const &);
    sf::Vector2u const &getSize() const;

    //pos
    void setPosition(sf::Vector2i const &);
    void setPosition(int, int);

    sf::Vector2i const &getPosition() const;

    //display
    void displayOn();
    void displayOff();
    void displayInverse();
  };
}// !gui
#endif /* !Object*/
