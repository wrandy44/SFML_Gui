/*
** Label.hh for Label.hh in /home/debrau_c/my/Mia/Gui2.0
**
** Made by debrau_c
** Login <debrau_c>
**
** Started tomorrow
*/
#ifndef __LABEL__HH_
# define __LABEL__HH_

# include <string>
# include "Object.hh"

namespace gui{
  class Label : public Object{
  protected:
    std::string _data;
   public:
    Label(unsigned int, unsigned int, std::string const &);
    Label(const Label &obj);
    Label	&operator=(const Label &obj);
    ~Label();
    std::string getData()const;
    void setData(std::string const &s);
  };
}// !gui
#endif /* !Label*/
