#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std; 



int main()
{
    sf::Texture spriteTexture;
    sf::Texture worldTexture;

    sf::RenderWindow window(sf::VideoMode(600, 500), "SFML works!");
    sf::RectangleShape sprite(sf::Vector2f(30.f,30.f));
    sf::RectangleShape startBlock(sf::Vector2f(50, 50));
    sf::RectangleShape block1(sf::Vector2f(200, 100));
    sf::RectangleShape block2(sf::Vector2f(150, 100));
    //define a 200 by 200 rectangle for the overworld
    sf::RectangleShape world(sf::Vector2f(500,500));

    sprite.setSize(sf::Vector2f(30.f, 30.f));
    world.setSize(sf::Vector2f(500,500));
    startBlock.setSize(sf::Vector2f(50, 50));
    block1.setSize(sf::Vector2f(200, 100));
    block2.setSize(sf::Vector2f(150, 100));
    if (!worldTexture.loadFromFile("image\\grass.jpg"))
    {
        // error...
    }
    if (!spriteTexture.loadFromFile("image\\wood.jpg"))
    {
        //error
    }
    startBlock.setFillColor(sf::Color(0, 0, 170));
    startBlock.setPosition(50, 200);
    //add attributes to block1
    block1.setFillColor(sf::Color(150, 150, 150));
    block1.setPosition(350, 250);
    //add attributes to block
    block2.setFillColor(sf::Color(150, 0, 0));
    block2.setPosition(150, 200);
    //add attributes to sprite
    sprite.setTexture(&spriteTexture);
    sprite.setPosition(50, 10);
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

    struct structPos2 {
        float x = 0.f;
        float y = 0.f;

    } newBlockPosition;

    struct structPos3 {
        float x = 0.f;
        float y = 0.f;
    } newStartBlockPosition;

    while (window.isOpen())
    {
        //get the bounding box of the player sprite entity
        sf::FloatRect playerBoundingBox = sprite.getGlobalBounds();
        //get the bounding box of the blocks
        sf::FloatRect startBlockBoundingBox = startBlock.getGlobalBounds();
        sf::FloatRect block1BoundingBox = block1.getGlobalBounds();
        sf::FloatRect block2BoundingBox = block2.getGlobalBounds();
        sf::FloatRect intersection;

        sf::Event event;
        newPosition = { sprite.getPosition().x, sprite.getPosition().y };
        newBlockPosition = { block2.getPosition().x, block2.getPosition().y };
        newStartBlockPosition = { startBlock.getPosition().x, startBlock.getPosition().y };
        //make building fall

        
        
            
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();


                
            
            //make sprite be affected by gravity
            newPosition.y += 0.2f;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
          
                newPosition.x += playerSpeed;
                
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
     
                newPosition.x -= playerSpeed;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
              
                newPosition.y -= playerSpeed;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
             
                //newPosition.y += playerSpeed;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                newPosition.y -= 6;
                sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y - 3.f);
            }

            if (sf::Joystick::isConnected(0))
            {
                unsigned int btnCount = sf::Joystick::getButtonCount(0);
            }



            


        }

        

        if (playerBoundingBox.intersects(block1BoundingBox, intersection))
        {
            



            if (intersection.width <= intersection.height)
            {
                
                if (newPosition.x <= block1.getPosition().x)
                {
                    
                    newPosition.x -= intersection.width;
                }
                else
                {
                    
                    newPosition.x += intersection.width;
                }
            }
            else
            {
               
                if (newPosition.y <= block1.getPosition().y)
                {
                 
                    newPosition.y -= intersection.height;
                }
                else
                {
                   
                    newPosition.y += intersection.height;
                }
            }




        }
        if (playerBoundingBox.intersects(block2BoundingBox, intersection))
        {
            if (intersection.width <= intersection.height)
            {
                
                if (newPosition.x <= block2.getPosition().x)
                {
                    
                    newPosition.x -= intersection.width;
                }
                else
                {
                   
                    newPosition.x += intersection.width;
                }
            }
            else
            {
                
                if (newPosition.y <= block2.getPosition().y)
                {
                    
                    newPosition.y -= intersection.height;
                }
                else
                {
                    
                    newPosition.y += intersection.height;
                }
            }
        }

        if (playerBoundingBox.intersects(startBlockBoundingBox, intersection))
        {




            if (intersection.width <= intersection.height)
            {

                if (newPosition.x <= startBlock.getPosition().x)
                {

                    newPosition.x -= intersection.width;
                }
                else
                {

                    newPosition.x += intersection.width;
                }
            }
            else
            {

                if (newStartBlockPosition.y <= startBlock.getPosition().y)
                {

                    newPosition.y -= intersection.height;
                }
                else
                {

                    newPosition.y += intersection.height;
                }
            }




        }
        sprite.setPosition(newPosition.x,newPosition.y+0.01f);
        block2.setPosition(newBlockPosition.x, newBlockPosition.y + 0.01f);
        window.clear();
        window.draw(world);
        window.draw(startBlock);
        window.draw(block2);
        window.draw(block1);
        window.draw(sprite);
        
        window.display();
        
    }


    return 0;
}

