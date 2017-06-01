/*
** Box.hh for Box.hh in /home/debrau_c/my/Mia/Gui2.0
**
** Made by debrau_c
** Login <debrau_c>
**
** Started tomorrow
*/
#ifndef __BOX__HH_
# define __BOX__HH_

# include <vector>
# include <memory>
# include "LabelImg.hh"

namespace gui{
  class Box : public LabelImg{
  protected:
    std::vector<std::shared_ptr<Object> > _child;
   public:
    Box(unsigned int, unsigned int);
    Box(const Box &obj);
    Box	&operator=(const Box &obj);
    ~Box();
    template<typename T>
    T *addChild(T c){
      std::shared_ptr<T> newChild = std::make_shared<T>(T(c));

      _child.push_back(newChild);
      return newChild.get();
    };
    virtual void draw(sf::RenderTarget &, Bank &);
    virtual bool event(sf::Event const &, sf::Vector2i const &parent = sf::Vector2i(0,0));
    virtual void alignVertical();
  };
}// !gui
#endif /* !Box*/
