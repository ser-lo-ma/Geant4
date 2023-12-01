#include"detector.hh"

MySensitiveDetector::MySensitiveDetector(G4String name): G4VSensitiveDetector(name){}

MySensitiveDetector::~MySensitiveDetector(){}

G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist)
{
    G4Track *track = aStep->GetTrack();
    
    track->SetTrackStatus(fStopAndKill);    
    
    G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
    G4StepPoint *postStepPoint = aStep->GetPostStepPoint();
    
    G4ThreeVector posPhoton = preStepPoint->GetPosition();
    
    // This line is useful but gives information about exact position, which is not available in reality
    //G4cout << "Photon position:" << posPhoton << G4endl;
    const G4VTouchable *touchable = aStep->GetPreStepPoint()->GetTouchable();
    G4int copyNo = touchable->GetCopyNumber();
    // This prints the detector number
    G4cout << "The copy number is:" << copyNo << G4endl;
    // This prints the position of the detector that the photon has touched
    G4VPhysicalVolume *physVol = touchable->GetVolume();
    G4ThreeVector posDetector = physVol->GetTranslation();
    G4cout << "The detector position is: " << posDetector << G4endl;
}
