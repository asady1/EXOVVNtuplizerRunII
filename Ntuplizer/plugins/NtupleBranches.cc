#include "../interface/NtupleBranches.h"

//===================================================================================================================        
NtupleBranches::NtupleBranches( TTree* tree )
   : tree_( tree )
{
   branch();

}

//===================================================================================================================
NtupleBranches::~NtupleBranches( void )
{
}

//===================================================================================================================      
void NtupleBranches::branch( void ){

  /*----------------------gen particles-------------------------*/
  tree_->Branch( "genParticle_pt"	     , &genParticle_pt	       ); 
  tree_->Branch( "genParticle_px"	     , &genParticle_px	       ); 
  tree_->Branch( "genParticle_py"	     , &genParticle_py	       ); 
  tree_->Branch( "genParticle_pz"	     , &genParticle_pz	       ); 
  tree_->Branch( "genParticle_e" 	     , &genParticle_e	       ); 
  tree_->Branch( "genParticle_eta"	     , &genParticle_eta        ); 
  tree_->Branch( "genParticle_phi"	     , &genParticle_phi        ); 
  tree_->Branch( "genParticle_mass"	     , &genParticle_mass       ); 
  tree_->Branch( "genParticle_pdgId"	     , &genParticle_pdgId      );
  tree_->Branch( "genParticle_status"	     , &genParticle_status     );
  tree_->Branch( "genParticle_mother"	     , &genParticle_mother     );
  tree_->Branch( "genParticle_nMoth"	     , &genParticle_nMoth      );
  tree_->Branch( "genParticle_nDau"	     , &genParticle_nDau       ); 
  tree_->Branch( "genParticle_dau"	     , &genParticle_dau        ); 
  tree_->Branch( "lheV_pt"	             , &lheV_pt                ); 
  tree_->Branch( "lheHT"	             , &lheHT                  ); 
  tree_->Branch( "lheNj"	             , &lheNj                  ); 
  tree_->Branch( "genWeight"	             , &genWeight              ); 
  tree_->Branch( "qScale"	             , &qScale                 ); 
  
  /*-------------------------leptons----------------------------*/
  tree_->Branch( "nlep"  		     , &nlep		       );
  tree_->Branch( "lep_type"		     , &lep_type	       );
  tree_->Branch( "lep_charge"		     , &lep_charge	       );
  tree_->Branch( "lep_e" 		     , &lep_e		       );
  tree_->Branch( "lep_eta"		     , &lep_eta 	       );
  tree_->Branch( "lep_mass"		  			   , &lep_mass	       );
  tree_->Branch( "lep_pt"		     				, &lep_pt  	       );
  tree_->Branch( "lep_phi"		     				, &lep_phi 	       );
  tree_->Branch( "lep_isHEEP"	            	, &lep_isHEEP             );
  tree_->Branch( "lep_isHEEPv50"	            , &lep_isHEEPv50             );
  tree_->Branch( "lep_isHighPtMuon"	   	  	, &lep_isHighPtMuon       );
  tree_->Branch( "lep_isTightMuon"	     		, &lep_isTightMuon       );
  tree_->Branch( "lep_isLooseMuon"	     		, &lep_isLooseMuon       );
  tree_->Branch( "lep_pfRhoCorrRelIso03"     , &lep_pfRhoCorrRelIso03  );
  tree_->Branch( "lep_pfRhoCorrRelIso04"     , &lep_pfRhoCorrRelIso04  );
  tree_->Branch( "lep_pfDeltaCorrRelIso"     , &lep_pfDeltaCorrRelIso  );
  tree_->Branch( "lep_pfRelIso"  	     , &lep_pfRelIso	       );
  tree_->Branch( "lep_photonIso" 	     , &lep_photonIso	       );
  tree_->Branch( "lep_neutralHadIso"	     , &lep_neutralHadIso      );
  tree_->Branch( "lep_chargedHadIso"	     , &lep_chargedHadIso      );
  tree_->Branch( "lep_trackIso"	             , &lep_trackIso	       );
      
  /*-------------------------energy density---------------------------*/	 
  tree_->Branch("rho"	    		        , &rho	  	     	 );

  /*-------------------------AK4 jets---------------------------*/	 
  tree_->Branch( "njetsAK4"		    , &njetsAK4 	);
  tree_->Branch( "jetAK4_pt"		    , &jetAK4_pt	);
  tree_->Branch( "jetAK4_eta"		    , &jetAK4_eta	);
  tree_->Branch( "jetAK4_mass"		    , &jetAK4_mass	);
  tree_->Branch( "jetAK4_phi"		    , &jetAK4_phi	);
  tree_->Branch( "jetAK4_e"		    , &jetAK4_e 	);
  tree_->Branch( "jetAK4_jec"		    , &jetAK4_jec 	);
  tree_->Branch( "jetAK4_IDLoose"	    , &jetAK4_IDLoose	);
  tree_->Branch( "jetAK4_muf" 		    , &jetAK4_muf	);
  tree_->Branch( "jetAK4_phf" 		    , &jetAK4_phf	);
  tree_->Branch( "jetAK4_emf" 		    , &jetAK4_emf	);
  tree_->Branch( "jetAK4_nhf" 		    , &jetAK4_nhf	);
  tree_->Branch( "jetAK4_chf" 		    , &jetAK4_chf	);
  tree_->Branch( "jetAK4_area" 		    , &jetAK4_area	);
  tree_->Branch( "jetAK4_cm"     	    , &jetAK4_cm	);
  tree_->Branch( "jetAK4_nm"     	    , &jetAK4_nm	);
  tree_->Branch( "jetAK4_che"     	    , &jetAK4_che	);
  tree_->Branch( "jetAK4_ne"     	    , &jetAK4_ne	);
  tree_->Branch( "jetAK4_charge" 	    , &jetAK4_charge    );
  tree_->Branch( "jetAK4_flavour"	    , &jetAK4_flavour   );
  tree_->Branch( "jetAK4_ssv"		    , &jetAK4_ssv	);
  tree_->Branch( "jetAK4_cisv"		    , &jetAK4_cisv	);
  tree_->Branch( "jetAK4_tchp"		    , &jetAK4_tchp	);
  tree_->Branch( "jetAK4_tche"		    , &jetAK4_tche	);
  tree_->Branch( "jetAK4_jp"		    , &jetAK4_jp	);
  tree_->Branch( "jetAK4_jbp"		    , &jetAK4_jbp	);
  tree_->Branch( "jetAK4_vtxMass"	    , &jetAK4_vtxMass   );
  tree_->Branch( "jetAK4_vtxNtracks"        , &jetAK4_vtxNtracks);
  tree_->Branch( "jetAK4_vtx3DVal"	    , &jetAK4_vtx3DVal  );
  tree_->Branch( "jetAK4_vtx3DSig"	    , &jetAK4_vtx3DSig  );
  //tree_->Branch( "jetAK4_nSVs"	    , &jetAK4_nSVs	);
        
  /*-------------------------AK8 jets---------------------------*/    
  tree_->Branch( "njetsAK8"		    , &njetsAK8 		 );
  tree_->Branch( "jetAK8_pt"		    , &jetAK8_pt		 );
  tree_->Branch( "jetAK8_eta"		    , &jetAK8_eta		 );
  tree_->Branch( "jetAK8_mass"		    , &jetAK8_mass		 );
  tree_->Branch( "jetAK8_phi"		    , &jetAK8_phi		 );
  tree_->Branch( "jetAK8_e"		    , &jetAK8_e 		 );
  tree_->Branch( "jetAK8_jec"		    , &jetAK8_jec 		 );
  tree_->Branch( "jetAK8_IDLoose"	    , &jetAK8_IDLoose		 );
  tree_->Branch( "jetAK8_muf" 		    , &jetAK8_muf		 );
  tree_->Branch( "jetAK8_phf" 		    , &jetAK8_phf		 );
  tree_->Branch( "jetAK8_emf" 		    , &jetAK8_emf		 );
  tree_->Branch( "jetAK8_nhf" 		    , &jetAK8_nhf		 );
  tree_->Branch( "jetAK8_chf" 		    , &jetAK8_chf		 );
  tree_->Branch( "jetAK8_area" 		    , &jetAK8_area		 );
  tree_->Branch( "jetAK8_cm"     	    , &jetAK8_cm		 );
  tree_->Branch( "jetAK8_nm"     	    , &jetAK8_nm		 );
  tree_->Branch( "jetAK8_che"     	    , &jetAK8_che		 );
  tree_->Branch( "jetAK8_ne"     	    , &jetAK8_ne		 );
  tree_->Branch( "jetAK8_charge" 	    , &jetAK8_charge    	 );
  tree_->Branch( "jetAK8_flavour"	    , &jetAK8_flavour   	 );
  tree_->Branch( "jetAK8_ssv"		    , &jetAK8_ssv		 );
  tree_->Branch( "jetAK8_csv"		    , &jetAK8_csv		 );
  tree_->Branch( "jetAK8_tchp"		    , &jetAK8_tchp		 );
  tree_->Branch( "jetAK8_tche"		    , &jetAK8_tche		 );
  tree_->Branch( "jetAK8_jp"		    , &jetAK8_jp		 );
  tree_->Branch( "jetAK8_jbp"		    , &jetAK8_jbp		 );
  tree_->Branch( "jetAK8_tau1"		    , &jetAK8_tau1		 );
  tree_->Branch( "jetAK8_tau2"		    , &jetAK8_tau2      	 );
  tree_->Branch( "jetAK8_tau3"		    , &jetAK8_tau3	    	 );
  tree_->Branch( "jetAK8_prunedmassUnCorr"  , &jetAK8_prunedmassUnCorr   );
  tree_->Branch( "jetAK8_prunedmassCorr"    , &jetAK8_prunedmassCorr	 );
  tree_->Branch( "jetAK8pruned_jec"	    , &jetAK8pruned_jec          );
  tree_->Branch( "jetAK8_softdropmassUnCorr", &jetAK8_softdropmassUnCorr ); 
  tree_->Branch( "jetAK8_softdropmassCorr"  , &jetAK8_softdropmassCorr   );
  tree_->Branch( "jetAK8softdrop_jec"	    , &jetAK8softdrop_jec        );
  
  // /*----------------------AK8 jets pruned-----------------------*/
  //tree_->Branch( "njetsAK8pruned"	 , &njetsAK8pruned	 );
  //tree_->Branch( "jetAK8pruned_pt"	 , &jetAK8pruned_pt	 );
  //tree_->Branch( "jetAK8pruned_eta"	 , &jetAK8pruned_eta	 );
  //tree_->Branch( "jetAK8pruned_mass"	 , &jetAK8pruned_mass    );
  //tree_->Branch( "jetAK8pruned_phi"	 , &jetAK8pruned_phi	 );
  //tree_->Branch( "jetAK8pruned_e"	 , &jetAK8pruned_e	 );
  //tree_->Branch( "jetAK8pruned_flavour", &jetAK8pruned_flavour );
  //tree_->Branch( "jetAK8pruned_charge" , &jetAK8pruned_charge  );
  //tree_->Branch( "jetAK8pruned_ssv"	 , &jetAK8pruned_ssv	 );
  //tree_->Branch( "jetAK8pruned_csv"	 , &jetAK8pruned_csv	 );
  //tree_->Branch( "jetAK8pruned_tchp"	 , &jetAK8pruned_tchp    );
  //tree_->Branch( "jetAK8pruned_tche"	 , &jetAK8pruned_tche    );
  //tree_->Branch( "jetAK8pruned_jp"	 , &jetAK8pruned_jp	 );
  //tree_->Branch( "jetAK8pruned_jbp"	 , &jetAK8pruned_jbp	 );
  //tree_->Branch( "jetAK8pruned_nSVs"	 , &jetAK8pruned_nSVs    );
  
  // /*----------------------AK8 jets softdrop-----------------------*/
  //tree_->Branch( "njetsAK8softdrop"	   , &njetsAK8softdrop	      );
  //tree_->Branch( "jetAK8softdrop_pt"     , &jetAK8softdrop_pt       );
  //tree_->Branch( "jetAK8softdrop_eta"    , &jetAK8softdrop_eta      );
  //tree_->Branch( "jetAK8softdrop_mass"   , &jetAK8softdrop_mass     );
  //tree_->Branch( "jetAK8softdrop_phi"    , &jetAK8softdrop_phi      );
  //tree_->Branch( "jetAK8softdrop_e"	   , &jetAK8softdrop_e        );
  //tree_->Branch( "jetAK8softdrop_flavour", &jetAK8softdrop_flavour  );
  //tree_->Branch( "jetAK8softdrop_charge" , &jetAK8softdrop_charge   );
  //tree_->Branch( "jetAK8softdrop_ssv"    , &jetAK8softdrop_ssv      );
  //tree_->Branch( "jetAK8softdrop_csv"    , &jetAK8softdrop_csv      );
  //tree_->Branch( "jetAK8softdrop_tchp"   , &jetAK8softdrop_tchp     );
  //tree_->Branch( "jetAK8softdrop_tche"   , &jetAK8softdrop_tche     );
  //tree_->Branch( "jetAK8softdrop_jp"     , &jetAK8softdrop_jp       );
  //tree_->Branch( "jetAK8softdrop_jbp"    , &jetAK8softdrop_jbp      );
  //tree_->Branch( "jetAK8softdrop_nSVs"   , &jetAK8softdrop_nSVs     );
	  
  /*----------------------Pruned AK8 subjets---------------------------*/    
  tree_->Branch( "nsubjets"		    , &nsubjets	 	       );
  tree_->Branch( "subjetAK8pruned_pt"	    , &subjetAK8pruned_pt      );
  tree_->Branch( "subjetAK8pruned_eta"	    , &subjetAK8pruned_eta     );
  tree_->Branch( "subjetAK8pruned_mass"     , &subjetAK8pruned_mass    );
  tree_->Branch( "subjetAK8pruned_phi"	    , &subjetAK8pruned_phi     );
  tree_->Branch( "subjetAK8pruned_e"	    , &subjetAK8pruned_e       );
  tree_->Branch( "subjetAK8pruned_charge"   , &subjetAK8pruned_charge  );
  tree_->Branch( "subjetAK8pruned_flavour"  , &subjetAK8pruned_flavour );
  tree_->Branch( "subjetAK8pruned_ssv"	    , &subjetAK8pruned_ssv     );
  tree_->Branch( "subjetAK8pruned_csv"	    , &subjetAK8pruned_csv     );
  tree_->Branch( "subjetAK8pruned_tchp"     , &subjetAK8pruned_tchp    );
  tree_->Branch( "subjetAK8pruned_tche"     , &subjetAK8pruned_tche    );
  tree_->Branch( "subjetAK8pruned_jp"	    , &subjetAK8pruned_jp      );
  tree_->Branch( "subjetAK8pruned_jbp"	    , &subjetAK8pruned_jbp     );
  
  // /*----------------------Softdrop AK8 subjets---------------------------*/
  //tree_->Branch( "nsoftdropsubjets"	      , &nsoftdropsubjets	   );
  //tree_->Branch( "subjetAK8softdrop_pt"     , &subjetAK8softdrop_pt      );
  //tree_->Branch( "subjetAK8softdrop_eta"    , &subjetAK8softdrop_eta     );
  //tree_->Branch( "subjetAK8softdrop_mass"   , &subjetAK8softdrop_mass    );
  //tree_->Branch( "subjetAK8softdrop_phi"    , &subjetAK8softdrop_phi     );
  //tree_->Branch( "subjetAK8softdrop_e"      , &subjetAK8softdrop_e	   );
  //tree_->Branch( "subjetAK8softdrop_charge" , &subjetAK8softdrop_charge  );
  //tree_->Branch( "subjetAK8softdrop_flavour", &subjetAK8softdrop_flavour );
  //tree_->Branch( "subjetAK8softdrop_ssv"    , &subjetAK8softdrop_ssv     );
  //tree_->Branch( "subjetAK8softdrop_csv"    , &subjetAK8softdrop_csv     );
  //tree_->Branch( "subjetAK8softdrop_tchp"   , &subjetAK8softdrop_tchp    );
  //tree_->Branch( "subjetAK8softdrop_tche"   , &subjetAK8softdrop_tche    );
  //tree_->Branch( "subjetAK8softdrop_jp"     , &subjetAK8softdrop_jp	   );
  //tree_->Branch( "subjetAK8softdrop_jbp"    , &subjetAK8softdrop_jbp     );
    
  /*-------------------------AK4 GenJets---------------------------*/	 
  tree_->Branch( "ngenJetsAK4"		    , &ngenJetsAK4 	  );
  tree_->Branch( "genJetAK4_pt"		    , &genJetAK4_pt	  );
  tree_->Branch( "genJetAK4_eta"	    , &genJetAK4_eta	  );
  tree_->Branch( "genJetAK4_mass"	    , &genJetAK4_mass	  );
  tree_->Branch( "genJetAK4_phi"	    , &genJetAK4_phi	  );
  tree_->Branch( "genJetAK4_e"		    , &genJetAK4_e 	  );
  tree_->Branch( "genJetNoNuAK4_pt"	    , &genJetNoNuAK4_pt	  );
  tree_->Branch( "genJetNoNuAK4_mass"	    , &genJetNoNuAK4_mass );
  tree_->Branch( "genJetNoNuAK4_e"	    , &genJetNoNuAK4_e    );
        
  /*----------------------HLT trigger---------------------------*/	  
  tree_->Branch("isFired_HLT_AK8PFJet360TrimMod_Mass30_v1"							, &isFired_HLT_AK8PFJet360TrimMod_Mass30_v1							);
  tree_->Branch("isFired_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v1"					, &isFired_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v1					);
  tree_->Branch("isFired_HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p3_v1"		, &isFired_HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p3_v1		);
  tree_->Branch("isFired_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v1"					, &isFired_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v1					);
  tree_->Branch("isFired_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v1"					, &isFired_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v1					);
  tree_->Branch("isFired_HLT_PFHT900_v1"													, &isFired_HLT_PFHT900_v1													);
  tree_->Branch("isFired_HLT_Ele95_CaloIdVT_GsfTrkIdT_v1"							, &isFired_HLT_Ele95_CaloIdVT_GsfTrkIdT_v1							);
  tree_->Branch("isFired_HLT_Mu40_v1"														, &isFired_HLT_Mu40_v1														);
  tree_->Branch("isFired_HLT_IsoMu20_eta2p1_IterTrk02_v1"							, &isFired_HLT_IsoMu20_eta2p1_IterTrk02_v1							);
  tree_->Branch("isFired_HLT_Ele27_eta2p1_WP85_Gsf_v1"								, &isFired_HLT_Ele27_eta2p1_WP85_Gsf_v1								);
  tree_->Branch("isFired_HLT_IsoMu20_eta2p1_IterTrk02_TriCentralPFJet40_v1"	, &isFired_HLT_IsoMu20_eta2p1_IterTrk02_TriCentralPFJet40_v1	);
  tree_->Branch("isFired_HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet40_v1"		, &isFired_HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet40_v1		);
  
  tree_->Branch("triggerObject_pt"				, &triggerObject_pt				);
  tree_->Branch("triggerObject_eta"				, &triggerObject_eta				);
  tree_->Branch("triggerObject_phi"				, &triggerObject_phi				);
  tree_->Branch("triggerObject_mass"			, &triggerObject_mass			);
  tree_->Branch("triggerObject_filterIDs"		, &triggerObject_filterIDs		);
  tree_->Branch("triggerObject_firedTrigger"	, &triggerObject_firedTrigger	);

  /*-------------------------MET--------------------------------*/
  tree_->Branch("METraw_et"		        , &METraw_et	     );
  tree_->Branch("METraw_phi"		        , &METraw_phi	     ); 
  tree_->Branch("METraw_sumEt"		        , &METraw_sumEt	     );   
  tree_->Branch("MET_corrPx"		        , &MET_corrPx	     ); 
  tree_->Branch("MET_corrPy"		        , &MET_corrPy	     );   
  tree_->Branch("MET_et"	                , &MET_et  	     ); 
  tree_->Branch("MET_phi"	                , &MET_phi           );
  // tree_->Branch("MET_T1Uncertainty"	        , &MET_T1Uncertainty );
  tree_->Branch("MET_sumEt"	                , &MET_sumEt 	     ); 
  //tree_->Branch("METdefault_et"	        , &METdefault_et     ); 
  //tree_->Branch("METdefault_sumEt"	        , &METdefault_sumEt  ); 
 // tree_->Branch("METdefault_phi"	        , &METdefault_phi    );

  /*------------- ------EVENT infos-----------------------------*/
  tree_->Branch("EVENT_event"	 , &EVENT_event     );
  tree_->Branch("EVENT_run"	 , &EVENT_run	    );
  tree_->Branch("EVENT_lumiBlock", &EVENT_lumiBlock );
  
  /*--------------------------PU infos--------------------------*/  			         
  tree_->Branch("nPuVtxTrue", &nPuVtxTrue );	
  tree_->Branch("nPuVtx"    , &nPuVtx	  );
  tree_->Branch("bX"	    , &bX	  );
  
  /*--------------------------PV infos--------------------------*/
  tree_->Branch("nPVs", &nPVs);
  
}

//=================================================================================================================== 
void NtupleBranches::reset( void ){

  lheV_pt     = 0;
  lheHT       = 0;
  lheNj       = 0;
  genWeight   = 0;
  qScale      = 0;
  nlep        = 0;
  njetsAK4    = 0;
  njetsAK8    = 0;  
  ngenJetsAK4 = 0;

  //njetsAK8pruned = 0;
  //njetsAK8softdrop = 0;
  isFired_HLT_AK8PFJet360TrimMod_Mass30_v1						= false;
  isFired_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_v1				= false;
  isFired_HLT_AK8DiPFJet280_200_TrimMass30_BTagCSV0p3_v1		= false;
  isFired_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_v1					= false;
  isFired_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_v1					= false;
  isFired_HLT_PFHT900_v1												= false;
  isFired_HLT_Ele95_CaloIdVT_GsfTrkIdT_v1							= false;
  isFired_HLT_Mu40_v1													= false;
  isFired_HLT_IsoMu20_eta2p1_IterTrk02_v1							= false;
  isFired_HLT_Ele27_eta2p1_WP85_Gsf_v1								= false;
  isFired_HLT_IsoMu20_eta2p1_IterTrk02_TriCentralPFJet40_v1	= false;
  isFired_HLT_Ele27_eta2p1_WP85_Gsf_TriCentralPFJet40_v1		= false;
  
    
  /************************************/    
  genParticle_pt	    .clear();
  genParticle_px	    .clear();
  genParticle_py	    .clear();
  genParticle_pz	    .clear();
  genParticle_e 	    .clear();
  genParticle_eta	    .clear();
  genParticle_phi	    .clear();
  genParticle_mass	    .clear();
  genParticle_pdgId	    .clear();
  genParticle_status	    .clear();
  genParticle_mother        .clear();
  genParticle_nMoth	    .clear();
  genParticle_nDau	    .clear();
  genParticle_dau	    .clear();
  /************************************/
  genJetAK4_pt              .clear();
  genJetAK4_eta             .clear();
  genJetAK4_mass            .clear();
  genJetAK4_phi             .clear();
  genJetAK4_e	            .clear();
  genJetNoNuAK4_pt          .clear();
  genJetNoNuAK4_mass        .clear();
  genJetNoNuAK4_e           .clear();
  /************************************/
  lep_type		    .clear();
  lep_charge		    .clear();
  lep_e 		    .clear();
  lep_eta		    .clear();
  lep_mass		    .clear();
  lep_pt		    .clear();
  lep_phi		    .clear();
  lep_isHEEP	            .clear();
  lep_isHEEPv50	            .clear();
  lep_isHighPtMuon	    .clear();
  lep_isTightMuon	    		.clear();
  lep_isLooseMuon	    		.clear();
  lep_pfRhoCorrRelIso03		.clear();
  lep_pfRhoCorrRelIso04    .clear();
  lep_pfDeltaCorrRelIso    .clear();
  lep_pfRelIso  	    .clear();
  lep_photonIso 	    .clear();
  lep_neutralHadIso	    .clear();
  lep_chargedHadIso	    .clear();
  lep_trackIso	            .clear();  	  
  /************************************/
  jetAK4_pt		    .clear();
  jetAK4_eta		    .clear();
  jetAK4_mass		    .clear();
  jetAK4_phi		    .clear();
  jetAK4_e		    .clear();
  jetAK4_jec                .clear();
  //jetAK4_jecUp              .clear();
  //jetAK4_jecDown            .clear();
  jetAK4_IDLoose            .clear();
  jetAK4_muf     	    .clear();
  jetAK4_phf     	    .clear();
  jetAK4_emf     	    .clear();
  jetAK4_nhf     	    .clear();
  jetAK4_chf     	    .clear();
  jetAK4_area        	    .clear();
  jetAK4_cm                 .clear();
  jetAK4_nm                 .clear();
  jetAK4_che                .clear();
  jetAK4_ne                 .clear();
  jetAK4_charge 	    .clear();
  jetAK4_flavour	    .clear();
  jetAK4_ssv		    .clear();
  jetAK4_cisv		    .clear();
  jetAK4_tchp		    .clear();
  jetAK4_tche		    .clear();
  jetAK4_jp		    .clear();
  jetAK4_jbp		    .clear();
  jetAK4_vtxMass	    .clear(); 
  jetAK4_vtxNtracks	    .clear(); 
  jetAK4_vtx3DVal	    .clear(); 
  jetAK4_vtx3DSig	    .clear(); 
  //jetAK4_nSVs		    .clear();
  /************************************/
  jetAK8_pt		    .clear();
  jetAK8_eta		    .clear();
  jetAK8_mass		    .clear();
  jetAK8_phi		    .clear();
  jetAK8_e		    .clear();
  jetAK8_jec                .clear();
  //jetAK8_jecUp 	     .clear();
  //jetAK8_jecDown	     .clear();
  jetAK8_IDLoose            .clear();
  jetAK8_muf     	    .clear();
  jetAK8_phf     	    .clear();
  jetAK8_emf     	    .clear();
  jetAK8_nhf     	    .clear();
  jetAK8_chf     	    .clear();
  jetAK8_area        	    .clear();
  jetAK8_cm                 .clear();
  jetAK8_nm                 .clear();
  jetAK8_che                .clear();
  jetAK8_ne                 .clear();
  jetAK8_charge 	    .clear();
  jetAK8_flavour	    .clear();
  jetAK8_ssv		    .clear();
  jetAK8_csv		    .clear();
  jetAK8_tchp		    .clear();
  jetAK8_tche		    .clear();
  jetAK8_jp		    .clear();
  jetAK8_jbp		    .clear();
  jetAK8_tau1		    .clear();
  jetAK8_tau2		    .clear();
  jetAK8_tau3		    .clear();
  jetAK8_prunedmassUnCorr   .clear();
  jetAK8_softdropmassUnCorr .clear();
  jetAK8_prunedmassCorr	    .clear();
  jetAK8_softdropmassCorr   .clear();
  jetAK8softdrop_jec	    .clear();
  jetAK8pruned_jec	    .clear();

  /************************************/
  //jetAK8pruned_pt	   .clear();
  //jetAK8pruned_eta	   .clear();
  //jetAK8pruned_mass	   .clear();
  //jetAK8pruned_phi	   .clear();
  //jetAK8pruned_e	   .clear();
  //jetAK8pruned_flavour   .clear();
  //jetAK8pruned_charge    .clear();
  //jetAK8pruned_ssv	   .clear();
  //jetAK8pruned_csv	   .clear();
  //jetAK8pruned_tchp	   .clear();
  //jetAK8pruned_tche	   .clear();
  //jetAK8pruned_jp	   .clear();
  //jetAK8pruned_jbp	   .clear();
  /************************************/
  //jetAK8softdrop_pt	    .clear();
  //jetAK8softdrop_eta      .clear();
  //jetAK8softdrop_mass     .clear();
  //jetAK8softdrop_phi      .clear();
  //jetAK8softdrop_e	    .clear();
  //jetAK8softdrop_flavour  .clear();
  //jetAK8softdrop_charge   .clear();
  //jetAK8softdrop_ssv      .clear();
  //jetAK8softdrop_csv      .clear();
  //jetAK8softdrop_tchp     .clear();
  //jetAK8softdrop_tche     .clear();
  //jetAK8softdrop_jp	    .clear();
  //jetAK8softdrop_jbp      .clear();
  //jetAK8softdrop_nSVs	    .clear();
  /************************************/
  nsubjets		    .clear();
  subjetAK8pruned_pt	    .clear();
  subjetAK8pruned_eta	    .clear();
  subjetAK8pruned_mass      .clear();
  subjetAK8pruned_phi	    .clear();
  subjetAK8pruned_e	    .clear();
  subjetAK8pruned_charge    .clear();
  subjetAK8pruned_flavour   .clear();
  subjetAK8pruned_ssv	    .clear();
  subjetAK8pruned_csv	    .clear();
  subjetAK8pruned_tchp      .clear();
  subjetAK8pruned_tche      .clear();
  subjetAK8pruned_jp	    .clear();
  subjetAK8pruned_jbp	    .clear();
  /************************************/
  //nsoftdropsubjets	     .clear();
  //subjetAK8softdrop_pt     .clear();
  //subjetAK8softdrop_eta    .clear();
  //subjetAK8softdrop_mass   .clear();
  //subjetAK8softdrop_phi    .clear();
  //subjetAK8softdrop_e      .clear();
  //subjetAK8softdrop_charge .clear();
  //subjetAK8softdrop_flavour.clear();
  //subjetAK8softdrop_ssv    .clear();
  //subjetAK8softdrop_csv    .clear();
  //subjetAK8softdrop_tchp   .clear();
  //subjetAK8softdrop_tche   .clear();
  //subjetAK8softdrop_jp     .clear();
  //subjetAK8softdrop_jbp    .clear();
  /************************************/

  METraw_et		 .clear();
  METraw_phi		 .clear();
  METraw_sumEt		 .clear();
  MET_et	         .clear();
  MET_sumEt              .clear();
  MET_phi	         .clear();
  MET_corrPx	         .clear();
  MET_corrPy	         .clear();
  MET_T1Uncertainty	 .clear();

  /************************************/  
  nPuVtxTrue             .clear();
  nPuVtx       		 .clear();
  bX	     		 .clear();
  
  triggerObject_pt.clear();
  triggerObject_eta.clear();
  triggerObject_phi.clear();
  triggerObject_mass.clear();
  triggerObject_filterIDs.clear();
  triggerObject_firedTrigger.clear();

} 
