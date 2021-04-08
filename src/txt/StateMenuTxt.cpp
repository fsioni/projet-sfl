#include "StateMenuTxt.h"
#include "StateGameTxt.h"
#include <memory>
#include <iostream>

StateMenuTxt::StateMenuTxt(/* args */) 
{
    
}

StateMenuTxt::StateMenuTxt(std::shared_ptr<Context> &cContext) 
    : context(cContext)
{
    
}

StateMenuTxt::~StateMenuTxt() 
{
    
}

void StateMenuTxt::Init() 
{
    DisplayMenu();
}

void StateMenuTxt::ProcessInput() 
{

}

void StateMenuTxt::Update() 
{    
    switch (menu)
    {
    case 1 :
        system("clear");
        context->stateMan->Add(make_unique<StateGameTxt>(context), true);
        break;
    
    case 0 :
        system("clear");
        context->quit = true;
        break;

    default:
        DisplayMenu();
        break;
    }
}

void StateMenuTxt::Display() 
{
    
}

void StateMenuTxt::Pause() 
{
    
}

void StateMenuTxt::Start() 
{
    
}

void StateMenuTxt::DisplayMenu() 
{
    system("clear");
    cout << endl << "------------- MENU -------------" << endl<<
    "1. Lancer le jeu " << endl <<
    "0. Quitter" << endl <<
    "Choix : ";
    menu = -99999;
    cin >> menu;
    cout << endl;
}