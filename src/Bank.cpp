/*
** Bank.cpp for Bank.cpp in /home/debrau_c/my/Mia/Client
**
** Made by debrau_c
** Login <debrau_c>
**
** Started tomorrow
*/

#include <dirent.h>
#include <iostream>
#include "gui/Bank.hh"

namespace gui{
  static bool check_extension(std::string s)
  {
    const unsigned int nb_exts = 3;
    const std::string exts[] = {".png", ".bmp", ".jpeg"};

    for (unsigned int k = 0; k < nb_exts; k++)
    {
      int i = s.size() -1;
      int j = exts[0].size() - 1;
      while (j >= 0 && i >= 0 && s[i] == exts[0][j])
      {
        --j;
        --i;
      }
      if (j == -1)
      return true;
    }
    return false;
  }

  void Bank::addImg(std::string path, std::string name)
  {
    sf::Texture tmp;
    if (!tmp.loadFromFile(path))
    std::cout << "Fail to load [" << path << "]" << std::endl;
    imgs.insert(std::pair<std::string, sf::Texture>(name, tmp));
  }

  int Bank::loadDir(std::string path)
  {
    DIR   *dir = opendir(path.c_str());
    struct dirent *pp;
    path += "/";
    if (!dir)
    return 1;
    while ((pp = readdir(dir)))
    {
      if (pp->d_type == DT_DIR && std::string(pp->d_name) != ".." && std::string(pp->d_name) != ".")
      loadDir(path + pp->d_name);
      else if (pp->d_type == DT_REG
        && check_extension(pp->d_name))
        addImg(path + pp->d_name, pp->d_name);
      }
      return 0;
    }

    Bank::Bank(std::string pathToFile)
    {
      notFoundImage.create(100, 100);
      notFoundImage.clear(sf::Color::White);
      notFoundImage.display();
      font.loadFromFile(pathToFile + "/font/police1.ttf");
      loadDir(pathToFile);
    }

    Bank::Bank(const Bank &obj){}

    Bank &Bank::operator=(const Bank &obj){ return *this; }

    Bank::~Bank()
    {

    }

    const sf::Texture &Bank::getFromPath(std::string s)
    {
      if (s == ""){
        return notFoundImage.getTexture();
      }
      sf::Texture tmp;
      if (imgs.find(s) != imgs.end()){
        return imgs.at(s);
      }
      return notFoundImage.getTexture();
    }
    const sf::Font &Bank::getFont()const { return font; }
}
