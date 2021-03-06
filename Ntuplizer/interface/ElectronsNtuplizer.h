#ifndef ElectronsNtuplizer_H
#define ElectronsNtuplizer_H

#include "../interface/CandidateNtuplizer.h"

class ElectronsNtuplizer : public CandidateNtuplizer {

public:
  ElectronsNtuplizer( edm::EDGetTokenT<pat::ElectronCollection> electronToken, edm::EDGetTokenT<reco::VertexCollection> verticeToken, edm::EDGetTokenT<double> rhoToken, NtupleBranches* nBranches );
  ~ElectronsNtuplizer( void );
  
  void fillBranches( edm::Event const & event, const edm::EventSetup& iSetup );
  
  float dEtaInSeed( const pat::Electron &ele );
  
private:
   edm::EDGetTokenT<pat::ElectronCollection> electronToken_;
   edm::EDGetTokenT<reco::VertexCollection>  verticeToken_ ;
   edm::EDGetTokenT<double> 		     rhoToken_     ;
   
   edm::Handle<pat::ElectronCollection>      electrons_    ;
   edm::Handle<reco::VertexCollection> 	     vertices_     ;
   edm::Handle<double> 			     rho_	   ;
      
};

#endif // ElectronsNtuplizer_H
