#include <SFML/Graphics.hpp>

int main(){
int x=0;
// ------------------------Spirites and Initiation--------------
sf::RenderWindow window(sf::VideoMode(800,800), "DVD Logo", sf::Style::Close | sf::Style::Titlebar);
window.clear();
sf::RectangleShape dvd(sf::Vector2f(140.0f,70.0f));
sf::Texture dvdtex;
dvdtex.loadFromFile("dvd_logo.png");
dvd.setTexture(&dvdtex);
dvd.setPosition(0,340);



//------------------------ Windows Events------------
while(window.isOpen()){
    sf::Event event;
    while(window.pollEvent(event)){
        if(event.type==sf::Event::Closed){
            window.close();
        }
    }

    // -------------------Collision Detection-----------------


    if(dvd.getPosition().x<0){
        if(dvd.getPosition().y<=365)
        x=1;
        if(dvd.getPosition().y>365)
        x=0;
    }

    if(dvd.getPosition().y<0){
        if(dvd.getPosition().x<=330)
        x=2;
        if(dvd.getPosition().x>330)
        x=1;
    }

    if(dvd.getPosition().x>(800-140)){
        if(dvd.getPosition().y<=435)
        x=2;
        if(dvd.getPosition().y>435)
        x=3;
    }

    if(dvd.getPosition().y>800-75){
        if(dvd.getPosition().x<=470)
        x=3;
        if(dvd.getPosition().x>470)
        x=0;
    }
// --------------------------Movement-------------------------
    if (x==0){
        dvd.move(0.02f,-0.02f);
    }
    if (x==1){
        dvd.move(0.02f,0.02f);
    }
    if (x==2){
        dvd.move(-0.02f,0.02f);
    }
    if (x==3){
        dvd.move(-0.02f,-0.02f);
    }






window.draw(dvd);
window.display();
window.clear();
}
}