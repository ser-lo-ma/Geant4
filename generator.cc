#include"generator.hh"

MyPrimaryGenerator::MyPrimaryGenerator(){
//Creates only one particle per event run
    fParticleGun = new G4ParticleGun(1);
}

// Destructor
MyPrimaryGenerator::~MyPrimaryGenerator(){
    delete fParticleGun;
}

void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent){
// Create the definition of the particle from the particle table
    G4ParticleTable *particletable = G4ParticleTable::GetParticleTable();
    G4String particleName = "proton";
    G4ParticleDefinition *particle = particletable -> FindParticle(particleName);


// Create the vector for the position of the particle and the direction of its momentum
    G4ThreeVector pos(0.,0.,0.);
    G4ThreeVector mom(0.,0.,1.);

// Use the particle gun and set the parameters of the particles emitted
    fParticleGun->SetParticlePosition(pos);
    fParticleGun->SetParticleMomentumDirection(mom);
    fParticleGun->SetParticleMomentum(100.*GeV);
    fParticleGun->SetParticleDefinition(particle);

// Generate the primary vertex of the particle

    fParticleGun->GeneratePrimaryVertex(anEvent);

}
