/**
 * @file Example data types for a simple particle physics problem
 *
 * This sets up the output data types for a very simple analysis. For each event the incident beam
 * energy is recorded and every created particle is recorded along with its PDG ID and kinematics.
 *
 * The event table's index is called eventNumber and the particle table contains a matching column
 * so these can be linked in later analysis.
 */

#include "H5Composites/H5Struct.h"

namespace H5CompositesExamples {
    struct ParticleData {
        /// The particle number
        std::size_t particleID;
        /// The global event number
        std::size_t eventNumber;
        /// The PDG ID
        int pdgId;
        /// The transverse momentum [MeV]
        float pt;
        /// The eta
        float eta;
        /// The phi
        float phi;
        H5COMPOSITES_DECLARE_STRUCT_DTYPE()
    };

    struct EventData {
        /// The event number
        std::size_t eventNumber;
        /// The incident beam energy
        float beamEnergy;
        H5COMPOSITES_DECLARE_STRUCT_DTYPE()
    };
} // namespace H5CompositesExamples