/*
** BoxClosable.hh for BoxClosable.hh in /home/debrau_c/my/Mia/Gui2.0
**
** Made by debrau_c
** Login <debrau_c>
**
** Started tomorrow
*/
#ifndef __BOXCLOSABLE__HH_
# define __BOXCLOSABLE__HH_

# include "Box.hh"
# include "Button.hh"

namespace gui{
  class BoxClosable : public Box{
    Button _closeButton;
   public:
    BoxClosable(unsigned int, unsigned int);
    BoxClosable(const BoxClosable &obj);
    BoxClosable	&operator=(const BoxClosable &obj);
    ~BoxClosable();
    virtual void draw(sf::RenderTarget &, Bank &);
    virtual bool event(sf::Event const &, sf::Vector2i const &parent = sf::Vector2i(0,0));
  };
}// !gui
#endif /* !BoxClosable*/
