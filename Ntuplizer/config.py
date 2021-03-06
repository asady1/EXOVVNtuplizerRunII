####### Process initialization ##########

import FWCore.ParameterSet.Config as cms

process = cms.Process("Ntuple")

process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
process.load('Configuration.StandardSequences.Geometry_cff')
process.load('Configuration.StandardSequences.MagneticField_38T_cff')
process.GlobalTag.globaltag = 'PHYS14_25_V2'

process.TFileService = cms.Service("TFileService",
                                       fileName = cms.string('flatTuple.root')
                                   )
				   
####### Config parser ##########

import FWCore.ParameterSet.VarParsing as VarParsing

options = VarParsing.VarParsing ('analysis')

options.maxEvents = -1
options.inputFiles ='root://xrootd.unl.edu//store/mc/Phys14DR/RSGravitonToWW_kMpl01_M_1000_Tune4C_13TeV_pythia8/MINIAODSIM/PU20bx25_tsg_PHYS14_25_V1-v2/10000/CE92595C-9676-E411-A785-00266CF2E2C8.root'
#options.inputFiles = 'file:testWW.root'



options.parseArguments()

process.options  = cms.untracked.PSet( 
                     wantSummary = cms.untracked.bool(True),
                     SkipEvent = cms.untracked.vstring('ProductNotFound')
                     )

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(options.maxEvents) )

process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring(options.inputFiles)
                            )                     

######## Sequence settings ##########

doAK8reclustering = True
doAK8prunedReclustering = True
doAK8softdropReclustering = True
doMETReclustering = False

####### Logger ##########

process.load("FWCore.MessageLogger.MessageLogger_cfi")

process.MessageLogger.cerr.threshold = 'INFO'
process.MessageLogger.categories.append('Ntuple')
process.MessageLogger.cerr.INFO = cms.untracked.PSet(
    limit = cms.untracked.int32(5)
)
process.MessageLogger.cerr.FwkReport.reportEvery = 1000


####### Redo Jet clustering sequence ##########

from RecoJets.Configuration.RecoPFJets_cff import ak4PFJetsCHS, ak8PFJetsCHS, ak8PFJetsCHSPruned, ak8PFJetsCHSSoftDrop, ak8PFJetsCHSPrunedLinks, ak8PFJetsCHSSoftDropLinks# , ak8PFJetsCSTrimmed, ak8PFJetsCSFiltered, ak8PFJetsCHSFilteredLinks, ak8PFJetsCHSTrimmedLinks
                                                                                                          
process.chs = cms.EDFilter("CandPtrSelector",
  src = cms.InputTag('packedPFCandidates'),
  cut = cms.string('fromPV')
)

process.ak4PFJetsCHS = ak4PFJetsCHS.clone(src = 'chs')
process.ak8PFJetsCHS = ak8PFJetsCHS.clone( src = 'chs', jetPtMin = 100.0 )


process.NjettinessAK8 = cms.EDProducer("NjettinessAdder",
			       src = cms.InputTag("ak8PFJetsCHS"),
			       Njets = cms.vuint32(1, 2, 3, 4),
			       # variables for measure definition : 
			       measureDefinition = cms.uint32( 0 ), # CMS default is normalized measure
			       beta = cms.double(1.0),  	    # CMS default is 1
			       R0 = cms.double( 0.8 ),  	    # CMS default is jet cone size
			       Rcutoff = cms.double( -999.0),	    # not used by default
			       # variables for axes definition :
			       axesDefinition = cms.uint32( 6 ),    # CMS default is 1-pass KT axes
			       nPass = cms.int32(-999), 	    # not used by default
			       akAxesR0 = cms.double(-999.0)	    # not used by default
			       )
			       
 
process.ak8PFJetsCHSPruned = ak8PFJetsCHSPruned.clone( src = 'chs', jetPtMin = 100.0  )
process.ak8PFJetsCHSPrunedLinks = ak8PFJetsCHSPrunedLinks.clone()

process.ak8PFJetsCHSSoftDrop = ak8PFJetsCHSSoftDrop.clone( src = 'chs', jetPtMin = 100.0  )

process.ak8PFJetsCHSSoftDropLinks = ak8PFJetsCHSSoftDropLinks.clone()

# process.ak8PFJetsCSTrimmed = ak8PFJetsCSTrimmed.clone( src = 'chs' )
# process.ak8PFJetsCSFiltered = ak8PFJetsCSFiltered.clone( src = 'chs' )
# process.ak8PFJetsCHSFilteredLinks = ak8PFJetsCHSFilteredLinks.clone()
# process.ak8PFJetsCHSTrimmedLinks = ak8PFJetsCHSTrimmedLinks.clone()                              

process.substructureSequence = cms.Sequence()

if doAK8reclustering:
   process.substructureSequence+=process.chs
   process.substructureSequence+=process.ak8PFJetsCHS
   process.substructureSequence+=process.NjettinessAK8

if doAK8prunedReclustering:
   process.substructureSequence+=process.ak8PFJetsCHSPruned
   process.substructureSequence+=process.ak8PFJetsCHSPrunedLinks

if doAK8softdropReclustering:
   process.substructureSequence+=process.ak8PFJetsCHSSoftDrop
   process.substructureSequence+=process.ak8PFJetsCHSSoftDropLinks
  
####### Redo pat jets sequence ##########
process.redoPatJets = cms.Sequence()
process.redoPrunedPatJets = cms.Sequence()
process.redoSoftDropPatJets = cms.Sequence()

from ExoDiBosonResonances.EDBRJets.redoPatJets_cff import patJetCorrFactorsAK8, patJetsAK8, selectedPatJetsAK8

# Redo pat jets from ak8PFJetsCHS
process.patJetCorrFactorsAK8 = patJetCorrFactorsAK8.clone( src = 'ak8PFJetsCHS' )
process.patJetsAK8 = patJetsAK8.clone( jetSource = 'ak8PFJetsCHS' )
process.patJetsAK8.jetCorrFactorsSource = cms.VInputTag( cms.InputTag("patJetCorrFactorsAK8") )
process.selectedPatJetsAK8 = selectedPatJetsAK8.clone( cut = cms.string('pt > 20') )

if doAK8reclustering:
   process.redoPatJets+=process.patJetCorrFactorsAK8 
   process.redoPatJets+=process.patJetsAK8 
   process.redoPatJets+=process.selectedPatJetsAK8

# Redo pat jets ak8PFJetsCHSPruned
process.patPrunedJetCorrFactorsAK8 = patJetCorrFactorsAK8.clone( src = 'ak8PFJetsCHSPruned' )
process.patPrunedJetsAK8 = patJetsAK8.clone( jetSource = 'ak8PFJetsCHSPruned' )
process.patPrunedJetsAK8.jetCorrFactorsSource = cms.VInputTag( cms.InputTag("patPrunedJetCorrFactorsAK8") )
process.patPrunedJetsAK8.userData.userFloats =cms.PSet(src = cms.VInputTag(""))	
process.selectedPrunedPatJetsAK8 = selectedPatJetsAK8.clone(cut = 'pt > 20', src = "patPrunedJetsAK8")

if doAK8prunedReclustering:
   process.redoPrunedPatJets+=process.patPrunedJetCorrFactorsAK8
   process.redoPrunedPatJets+=process.patPrunedJetsAK8
   process.redoPrunedPatJets+=process.selectedPrunedPatJetsAK8

# Redo pat jets ak8PFJetsCHSSoftDrop
process.patSoftDropJetCorrFactorsAK8 = patJetCorrFactorsAK8.clone( src = 'ak8PFJetsCHSSoftDrop' )
process.patSoftDropJetsAK8 = patJetsAK8.clone( jetSource = 'ak8PFJetsCHSSoftDrop' )
process.patSoftDropJetsAK8.jetCorrFactorsSource = cms.VInputTag( cms.InputTag("patSoftDropJetCorrFactorsAK8") )
process.patSoftDropJetsAK8.userData.userFloats =cms.PSet(src = cms.VInputTag(""))	
process.selectedSoftDropPatJetsAK8 = selectedPatJetsAK8.clone(cut = 'pt > 20', src = "patSoftDropJetsAK8")

if doAK8softdropReclustering:
   process.redoSoftDropPatJets+=process.patSoftDropJetCorrFactorsAK8 
   process.redoSoftDropPatJets+=process.patSoftDropJetsAK8 
   process.redoSoftDropPatJets+=process.selectedSoftDropPatJetsAK8

####### ExoDiBosonResonances objects ##########

# import ExoDiBosonResonances.EDBRCommon.goodElectrons_cff
# import ExoDiBosonResonances.EDBRCommon.goodMuons_cff
# import ExoDiBosonResonances.EDBRCommon.goodJets_cff
#
# process.load("ExoDiBosonResonances.EDBRCommon.goodElectrons_cff")
# process.load("ExoDiBosonResonances.EDBRCommon.goodMuons_cff")
# process.load("ExoDiBosonResonances.EDBRCommon.goodJets_cff")
#
#
# process.goodJets.src = 'selectedPatJetsAK8'
# process.jetSequence = cms.Sequence(process.fatJetsSequence)
#
# process.goodPrunedJets  = process.goodJets.clone( src = 'selectedPrunedPatJetsAK8' )
# process.cleanPrunedJets = process.cleanJets.clone(src = 'goodPrunedJets' )
# process.PrunedJetSequence   = cms.Sequence(process.goodPrunedJets + process.cleanPrunedJets)
#
# process.leptonSequence  = cms.Sequence(process.muSequence + process.eleSequence)

####### Adding HEEP id ##########

from PhysicsTools.SelectorUtils.tools.vid_id_tools import *
process.load("RecoEgamma.ElectronIdentification.egmGsfElectronIDs_cfi")

# overwrite a default parameter: for miniAOD, the collection name is a slimmed one
process.egmGsfElectronIDs.physicsObjectSrc = cms.InputTag('slimmedElectrons')
from PhysicsTools.SelectorUtils.centralIDRegistry import central_id_registry
process.egmGsfElectronIDSequence = cms.Sequence(process.egmGsfElectronIDs)

#add in the heep ID to the producer. You can run with other IDs but heep ID must be loaded with setupVIDSelection, not setupAllVIDSelection as heep works differently because mini-aod and aod are defined in the same file to ensure consistancy (you cant change cuts of aod without changing miniaod
process.load('RecoEgamma.ElectronIdentification.Identification.heepElectronID_HEEPV50_CSA14_startup_cff')
setupVIDSelection(process.egmGsfElectronIDs,process.heepElectronID_HEEPV50_CSA14_startup)

###### Recluster MET ##########
process.redoPatMET = cms.Sequence()

process.load("PhysicsTools.PatAlgos.producersLayer1.patCandidates_cff")

from RecoMET.METProducers.PFMET_cfi import pfMet
from JetMETCorrections.Type1MET.correctionTermsPfMetType1Type2_cff import corrPfMetType1

from JetMETCorrections.Configuration.JetCorrectors_cff import ak4PFCHSL1FastL2L3Corrector,ak4PFCHSL1FastjetCorrector,ak4PFCHSL2RelativeCorrector,ak4PFCHSL3AbsoluteCorrector
process.ak4PFCHSL1FastL2L3Corrector = ak4PFCHSL1FastL2L3Corrector.clone()

from JetMETCorrections.Type1MET.correctedMet_cff import pfMetT1
from PhysicsTools.PatAlgos.producersLayer1.metProducer_cfi import patMETs

process.pfMet = pfMet.clone(src = "packedPFCandidates")
process.pfMet.calculateSignificance = False

corrPfMetType1.jetCorrLabel = cms.InputTag('ak4PFCHSL1FastL2L3Corrector')
corrPfMetType1.src = cms.InputTag('ak4PFJetsCHS')
corrPfMetType1.offsetCorrLabel = cms.InputTag("ak4PFCHSL1FastjetCorrector")

process.pfMetT1 = pfMetT1.clone()
process.patMETs = patMETs.clone()
process.patMETs.addGenMET = False # There's no point in recalculating this, and we can't remake it since we don't have genParticles beyond |eta|=5

if doMETReclustering:
    process.redoPatMET+=process.ak4PFJetsCHS
    process.redoPatMET+=process.pfMet
    process.redoPatMET+=process.ak4PFCHSL1FastjetCorrector
    process.redoPatMET+=process.ak4PFCHSL2RelativeCorrector
    process.redoPatMET+=process.ak4PFCHSL3AbsoluteCorrector
    process.redoPatMET+=process.ak4PFCHSL1FastL2L3Corrector
    process.redoPatMET+=process.corrPfMetType1
    process.redoPatMET+=process.pfMetT1
    process.redoPatMET+=process.patMETs



####### Ntuplizer initialization ##########

runOnMC = True

jetsAK8 = "slimmedJetsAK8"
jetsAK8pruned = ""
jetsAK8softdrop = ""

METS = "slimmedMETs"
reclusteredMETS = ""
pfMETS = ""


if doAK8reclustering:
   jetsAK8 = "patJetsAK8"
if doAK8prunedReclustering:
   jetsAK8pruned = "patPrunedJetsAK8" 
if doAK8softdropReclustering:
   jetsAK8softdrop = "patSoftDropJetsAK8"  
   
if doMETReclustering:
    METS = "" 
    reclusteredMETS = "patMETs"
    pfMETS = "pfMet" 
     

######## JEC ########
jecLevelsAK8chs = [
    'JEC/PHYS14_25_V2::All_L1FastJet_AK8PFchs.txt',
    'JEC/PHYS14_25_V2::All_L2Relative_AK8PFchs.txt',
    'JEC/PHYS14_25_V2::All_L3Absolute_AK8PFchs.txt'
  ]
jecLevelsAK4chs = [
    'JEC/PHYS14_25_V2::All_L1FastJet_AK4PFchs.txt',
    'JEC/PHYS14_25_V2::All_L2Relative_AK4PFchs.txt',
    'JEC/PHYS14_25_V2::All_L3Absolute_AK4PFchs.txt'
  ]
   

process.ntuplizer = cms.EDAnalyzer("Ntuplizer",
    runOnMC = cms.bool(runOnMC),
    vertices = cms.InputTag("offlineSlimmedPrimaryVertices"),
    muons = cms.InputTag("slimmedMuons"),
    electrons = cms.InputTag("slimmedElectrons"),
    #electronsId = cms.InputTag("egmGsfElectronIDs:heepElectronID-HEEPV50-CSA14-startup"),
    taus = cms.InputTag("slimmedTaus"),
    jets = cms.InputTag("slimmedJets"),
    fatjets = cms.InputTag(jetsAK8),
    prunedjets = cms.InputTag(jetsAK8pruned),
    softdropjets = cms.InputTag(jetsAK8softdrop),
    genJets = cms.InputTag("slimmedGenJets"),
    #subjetflavour = cms.InputTag("flavourByVal"),
    subjetflavour = cms.InputTag("AK8byValAlgo"),
    mets = cms.InputTag(METS),
    reclusteredmets = cms.InputTag(reclusteredMETS),
    pfmets = cms.InputTag(pfMETS),
    corrMetPx = cms.string("+0.1166 + 0.0200*Nvtx"),
    corrMetPy = cms.string("+0.2764 - 0.1280*Nvtx"),
    rho = cms.InputTag("fixedGridRhoFastjetAll"),
    genparticles = cms.InputTag("prunedGenParticles"),
    PUInfo = cms.InputTag("addPileupInfo"),
    genEventInfo = cms.InputTag("generator"),
    HLT = cms.InputTag("TriggerResults","","HLT"),
    triggerobjects = cms.InputTag("selectedPatTrigger"),
    triggerprescales = cms.InputTag("patTrigger"),
    jecAK8chsPayloadNames = cms.vstring( jecLevelsAK8chs ),
    jecAK4chsPayloadNames = cms.vstring( jecLevelsAK4chs ),
    jecpath = cms.string(''),
)

####### Final path ##########

process.p = cms.Path(process.substructureSequence*process.redoPatJets*process.redoPrunedPatJets*process.redoSoftDropPatJets*process.redoPatMET*process.ntuplizer)
# process.p = cms.Path(process.substructureSequence*process.redoPatJets*process.redoPrunedPatJets*process.redoSoftDropPatJets*process.ak4PFJetsCHS*process.ntuplizer)


