#include "action.hh"

MyActionInitialization::MyActionInitialization(){}

MyActionInitialization::~MyActionInitialization(){}

void MyActionInitialization::Build() const
{
// We now implement the generator
    MyPrimaryGenerator *generator = NewMyPrimaryGenerator();
    SetUserAction(generator);
}
