#include "StatePauseSFML.h"
StatePauseSFML::StatePauseSFML(/* args */) 
{
    
}

StatePauseSFML::StatePauseSFML(std::shared_ptr<Context> &cContext)
    : context(cContext)
{
    
}

StatePauseSFML::~StatePauseSFML() 
{
    
}

void StatePauseSFML::Init() 
{
    
}

void StatePauseSFML::ProcessInput() 
{
    sf::Event event;
    
    while (context->renderWin->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            context->renderWin->close();
        }else if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::Escape:
                context->stateMan->PopCurrent();
                break;
            
            default:
                break;
            }
        }
        
    }
    
}

void StatePauseSFML::Update() 
{
    
}

void StatePauseSFML::Display() 
{
    context->renderWin->display();
}

void StatePauseSFML::Pause() 
{
    
}

void StatePauseSFML::Start() 
{
    
}
