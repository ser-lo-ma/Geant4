#ifndef DETECTOR_HH
#define DETECTOR_HH

#include"G4VSensitiveDetector.hh"
#include"G4String.hh"
#include"G4Step.hh"
#include"G4TouchableHistory.hh"

class MySensitiveDetector: public G4VSensitiveDetector{
    public:
    MySensitiveDetector(G4String);
    ~MySensitiveDetector();

private:
    virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);

};

#endif
