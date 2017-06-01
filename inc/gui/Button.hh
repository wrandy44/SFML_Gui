/*
** Button.hh for Button.hh in /home/debrau_c/my/Mia/Gui2.0
**
** Made by debrau_c
** Login <debrau_c>
**
** Started tomorrow
*/
#ifndef __BUTTON__HH_
# define __BUTTON__HH_

# include <functional>
# include "LabelImg.hh"

namespace gui{
  class Button : public LabelImg{
    std::function<void()> _func;
   public:
    Button(unsigned int, unsigned int, std::string const &s);
    Button(const Button &obj);
    Button(int, int, unsigned int, unsigned int, std::string const &);

    Button	&operator=(const Button &obj);
    ~Button();
    template<typename F, typename... Args>
    void setFunction(F f, Args&&... args){
      _func = std::bind(f, std::forward<Args>(args)...);
    }
    virtual bool event(sf::Event const &, sf::Vector2i const &parent = sf::Vector2i(0,0));
  };
}// !gui
#endif /* !Button*/
