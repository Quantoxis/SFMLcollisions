#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std; 



int main()
{
    sf::Texture spriteTexture;
    sf::Texture worldTexture;

    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    sf::RectangleShape sprite(sf::Vector2f(30.f,30.f));
    sf::RectangleShape building(sf::Vector2f(200, 100));
    //define a 200 by 200 rectangle for the overworld
    sf::RectangleShape world(sf::Vector2f(500,500));
    sprite.setSize(sf::Vector2f(30.f, 30.f));
    world.setSize(sf::Vector2f(500,500));
    building.setSize(sf::Vector2f(200, 100));
    if (!worldTexture.loadFromFile("image\\grass.jpg"))
    {
        // error...
    }
    if (!spriteTexture.loadFromFile("image\\wood.jpg"))
    {
        //error
    }
    //add attributes to building
    building.setFillColor(sf::Color(150, 150, 150));
    building.setPosition(250, 250);
    //add attributes to sprite
    sprite.setTexture(&spriteTexture);
    sprite.setPosition(201, 101);
    //sprite.setFillColor(sf::Color::Red);
    sprite.setOutlineThickness(2.f);
    sprite.setOutlineColor(sf::Color(255, 255, 255));
    //add attributes to overworld
    world.setTexture(&worldTexture);
    world.setFillColor(sf::Color::Green);
    world.setOutlineThickness(7.f);
    world.setOutlineColor(sf::Color(210, 105, 30));
   


    ////check collision
    //sf::Vector2f point = { 2,2 };
    //    if(playerBoundingBox.contain)
    //    {
    //        //collision
    //    }


    

    int playerSpeed = 7;



    struct structPos{
        float x = 0.f;
        float y = 0.f;

    } newPosition;


    while (window.isOpen())
    {
        //get the bounding box of the player sprite entity
        sf::FloatRect playerBoundingBox = sprite.getGlobalBounds();
        //get the bounding box of the building sprite
        sf::FloatRect buildingBoundingBox = building.getGlobalBounds();
        sf::FloatRect intersection;

        sf::Event event;
        newPosition = { sprite.getPosition().x, sprite.getPosition().y };
    
        //make building fall
        building.setPosition(building.getPosition().x, building.getPosition().y + 0.1f);
        if (building.getPosition().y > 500)
        {
            building.setPosition(250, 0);
        }
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                //sprite.setPosition(sprite.getPosition().x+ playerSpeed,sprite.getPosition().y);
                newPosition.x += playerSpeed;
                
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                //sprite.setPosition(sprite.getPosition().x - playerSpeed, sprite.getPosition().y);
                newPosition.x -= playerSpeed;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                //sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y- playerSpeed);
                newPosition.y -= playerSpeed;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                //sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y+ playerSpeed);
                newPosition.y += playerSpeed;
            }

            if (sf::Joystick::isConnected(0))
            {
                unsigned int btnCount = sf::Joystick::getButtonCount(0);
            }

            //sf::View view1(sf::FloatRect(200, 200, 200, 200));
            //sf::View view2(sf::Vector2f(200.f, 200.f), sf::Vector2f(200.f, 200.f));

            //window.setView(view1);

            //window.draw(world);

            //sf::View currentView = window.getView();
            //// rotate the view at 20 degrees
            //view1.setRotation(20.f);

            //// rotate the view by 5 degrees relatively to its current orientation (so its final orientation is 25 degrees)
            //view1.rotate(5.f);

            //sf::FloatRect buildingInterectDimension = building.getGlobalBounds();


            ////check for collisions
            //if (sprite.getPosition().x < building.getPosition().x + buildingBoundingBox.width &&
            //    sprite.getPosition().x + playerBoundingBox.width > building.getPosition().x &&
            //    sprite.getPosition().y < building.getPosition().y + buildingBoundingBox.height &&
            //    buildingBoundingBox.height + sprite.getPosition().y > building.getPosition().y)
            //{
            //    std::cout << "collision detected!" << std::endl;
            //        
            //}
            //else {
            //    std::cout << "no collision detected" << std::endl;
            //}



            
            

            std::cout <<  "sprite x: " << sprite.getPosition().x << std::endl;
            std::cout << " sprite y: " << sprite.getPosition().y << std::endl;

        }

        if (playerBoundingBox.intersects(buildingBoundingBox, intersection))
        {
            std::cout << "player is inside" << std::endl;



            if (intersection.width <= intersection.height)
            {
                //if (sprite.getPosition().x <= building.getPosition().x)
                if (newPosition.x <= building.getPosition().x)
                {
                    //sprite.setPosition(sprite.getPosition().x - intersection.width, sprite.getPosition().y);
                    newPosition.x -= intersection.width;
                }
                else
                {
                    //sprite.setPosition(sprite.getPosition().x + intersection.width, sprite.getPosition().y);
                    newPosition.x += intersection.width;
                }
            }
            else
            {
                //if (sprite.getPosition().y <= building.getPosition().y)
                if (newPosition.y <= building.getPosition().y)
                {
                    //sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - intersection.height);
                    newPosition.y -= intersection.height;
                }
                else
                {
                    //sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + intersection.height);
                    newPosition.y += intersection.height;
                }
            }



        }
        sprite.setPosition(newPosition.x,newPosition.y);
        window.clear();
        window.draw(world);
        window.draw(building);
        window.draw(sprite);
        
        window.display();
        
    }


    return 0;
}

