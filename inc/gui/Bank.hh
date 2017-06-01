/*
** Bank.hh for Bank.hh in /home/debrau_c/my/Mia/Client
**
** Made by debrau_c
** Login <debrau_c>
**
** Started tomorrow
*/
#ifndef __Bank__HH_
# define __Bank__HH_

# include <string>
# include <SFML/Graphics.hpp>

namespace gui{
  class Bank{
    std::map<std::string, sf::Texture> imgs;
    sf::Font font;
    sf::RenderTexture notFoundImage;

    int loadDir(std::string);
    void addImg(std::string, std::string);
  public:
    Bank(std::string);

    Bank(const Bank &obj);
    Bank	&operator=(const Bank &obj);
    ~Bank();
    const sf::Texture &getFromPath(std::string);
    const sf::Font &getFont()const;
  };
}
#endif /* !Bank*/
