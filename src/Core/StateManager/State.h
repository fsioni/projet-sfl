#ifndef __STATE_H__
#define __STATE_H__

class State
{
private:
    /* data */
public:
    State(/* args */);
    ~State();

    
    virtual void Init()=0; //Appelée une fois au début du State
    virtual void CleanUp()=0; //Appelée lorsque l'état est quitté

    virtual void Pause()=0;
    virtual void Resume()=0;
    virtual void GetEvents()=0; //Gère les inputs selon le state (Une touche peut ne pas faire la même chose sur deux états différents)
    virtual void Update()=0;
    
    virtual void DisplayText()=0;
    virtual void DisplayGUI()=0; 

    virtual void Test()=0;
};


#endif // __STATE_H__