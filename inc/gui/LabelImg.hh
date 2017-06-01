/*
** LabelImg.hh for LabelImg.hh in /home/debrau_c/my/Mia/Gui2.0
**
** Made by debrau_c
** Login <debrau_c>
**
** Started tomorrow
*/
#ifndef __LABELIMG__HH_
# define __LABELIMG__HH_

# include "Label.hh"

namespace gui{
  class LabelImg : public Label{
  protected:
    virtual void fillBuffer(Bank &);
   public:
    LabelImg(unsigned int, unsigned int,std::string const &);
    LabelImg(const LabelImg &obj);
    LabelImg	&operator=(const LabelImg &obj);
    ~LabelImg();
    virtual void draw(sf::RenderTarget &, Bank &);
  };
}// !gui
#endif /* !LabelImg*/
