#include"action.hh"
#include"run.hh"

MyActionInitialization::MyActionInitialization(){}

MyActionInitialization::~MyActionInitialization(){}

void MyActionInitialization::Build() const
{
    // We now implement the generator
    MyPrimaryGenerator *generator = new MyPrimaryGenerator();
    SetUserAction(generator);
    
    // Store the data in a ROOT file
    MyRunAction  *runAction = new MyRunAction();
    SetUserAction(runAction);

}
