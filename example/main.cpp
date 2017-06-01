//
// main.cpp for azd in /home/debrau_c/my/Mia/GUI/exemple
//
// Made by debrau_c
// Login   <carl.debrauwere@epitech.eu>
//
// Started on  Thu May 25 12:12:28 2017 debrau_c
// Last update Fri May 26 00:41:15 2017 debrau_c
//

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
# include "Gui.hh"

void talk_me()
{
  std::cout << "ok" << std::endl;
}

int main()
{
  gui::Bank	gbi("ressources/Gui");
  gui::Object obj(100, 100);
  gui::Button butt(100, 50, "buttazdazdon1.png");
  gui::LabelTxt lblTxt(200, 60, "Un label ici");
  gui::LabelImg lblImg(150, 40, "button1.png");
  gui::BoxClosable box(200, 500);
  gui::BoxScrollable bScroll(200, 500);
  gui::Input inp(200, 30);
  butt.setFunction(&talk_me);
  box.addChild(lblTxt);
  box.addChild(obj);
  box.addChild(butt);
  box.addChild(lblImg);
  box.addChild(inp);
  box.alignVertical();

  bScroll.addChild(lblTxt);
  bScroll.addChild(obj);
  bScroll.addChild(butt);
  bScroll.addChild(lblImg);
  bScroll.addChild(inp);
  bScroll.alignVertical();
  bScroll.setPosition(sf::Vector2i(250, 0));

  sf::RenderWindow window(sf::VideoMode(1200, 900), "SFML window");

  while (window.isOpen())
    {
      sf::Event event;
      while (window.pollEvent(event))
      {
        bScroll.event(event);
        box.event(event);

        if (event.type == sf::Event::Closed)
        window.close();
      }
      window.clear(sf::Color::Blue);
      bScroll.draw(window, gbi);
      box.draw(window, gbi);
      window.display();
    }
  return EXIT_SUCCESS;
}
