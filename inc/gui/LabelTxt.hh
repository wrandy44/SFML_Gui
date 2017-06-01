/*
** LabelTxt.hh for LabelTxt.hh in /home/debrau_c/my/Mia/Gui2.0
**
** Made by debrau_c
** Login <debrau_c>
**
** Started tomorrow
*/
#ifndef __LABELTXT__HH_
# define __LABELTXT__HH_

# include "Label.hh"

namespace gui{
  class LabelTxt : public Label{
  protected:
    virtual void fillBuffer(Bank &);
   public:
    LabelTxt(unsigned int w, unsigned int h, std::string const &);
    LabelTxt(const LabelTxt &obj);
    LabelTxt	&operator=(const LabelTxt &obj);
    ~LabelTxt();
    virtual void draw(sf::RenderTarget &, Bank &);

  };
}// !gui
#endif /* !LabelTxt*/
