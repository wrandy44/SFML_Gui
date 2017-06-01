/*
** BoxScrollable.hh for BoxScrollable.hh in /home/debrau_c/my/Mia/Gui2.0
**
** Made by debrau_c
** Login <debrau_c>
**
** Started tomorrow
*/
#ifndef __BOXSCROLLABLE__HH_
# define __BOXSCROLLABLE__HH_

# include "Box.hh"
# include "Button.hh"


namespace gui{
  class BoxScrollable : public Box{
    Button _upButton;
    Button _downButton;
    Button _cursorScroll;
    int   _cursorPos;
    int   _cursorMax;
    int   _cursorMin;
    unsigned int _cursorJump;

    void upCursor();
    void downCursor();
   public:
    BoxScrollable(unsigned int, unsigned int);
    BoxScrollable(const BoxScrollable &obj);
    BoxScrollable	&operator=(const BoxScrollable &obj);
    ~BoxScrollable();
    virtual void draw(sf::RenderTarget &, Bank &);
    virtual bool event(sf::Event const &, sf::Vector2i const &parent = sf::Vector2i(0,0));
    virtual void alignVertical();
    virtual void updateCursorScroll();
  };
}// !gui
#endif /* !BoxScrollable*/
