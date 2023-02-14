#include "H5CompositesExamples/ParticleData.h"

namespace H5CompositesExamples {
    H5COMPOSITES_DEFINE_STRUCT_DTYPE(ParticleData, particleID, eventNumber, pdgId, pt, eta, phi)
    H5COMPOSITES_DEFINE_STRUCT_DTYPE(EventData, eventNumber, beamEnergy)
}