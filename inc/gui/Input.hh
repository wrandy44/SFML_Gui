/*
** Input.hh for Input.hh in /home/debrau_c/my/Mia/Gui2.0
**
** Made by debrau_c
** Login <debrau_c>
**
** Started tomorrow
*/
#ifndef __INPUT__HH_
# define __INPUT__HH_

# include "LabelTxt.hh"

namespace gui{
  class Input : public LabelTxt{
  private:
    bool _onfocus;
   public:
    Input(unsigned int, unsigned int);
    Input(const Input &obj);
    Input	&operator=(const Input &obj);
    ~Input();
    virtual bool event(sf::Event const &r, sf::Vector2i const &parent);
    virtual void draw(sf::RenderTarget &w, Bank &b);
    virtual void fillBuffer(Bank &);
    void cleanValue();
  };
}// !gui
#endif /* !Input*/
