/**
 * @file Simple example test to generate some fake particles and demonstrate the output writing
 *
 * Note that there is *no* physics involved here - the produced 'events' will be completely
 * meaningless
 */

#include "H5Composites/GroupWrapper.h"
#include "H5Composites/TypedWriter.h"
#include "H5CompositesExamples/ParticleData.h"

#include <random>

using namespace H5CompositesExamples;
namespace {
    EventData generateEvent(std::mt19937 &random, std::size_t &eventNumber) {
        std::exponential_distribution<float> dist(1e-3);
        return EventData{.eventNumber = eventNumber++, .beamEnergy = dist(random)};
    }
    ParticleData generateParticle(
            std::mt19937 &random, std::size_t eventNumber, std::size_t &particleID,
            float beamEnergy) {
        std::exponential_distribution<float> ptDist(1. / beamEnergy);
        std::uniform_real_distribution<float> etaDist(-5, 5);
        std::uniform_real_distribution<float> phiDist(0, 2 * M_PI);
        return ParticleData{
                .particleID = particleID++,
                .eventNumber = eventNumber,
                .pdgId = 1,
                .pt = ptDist(random),
                .eta = etaDist(random),
                .phi = phiDist(random)};
    }
} // namespace

int main(int argc, char *argv[]) {
    using namespace H5Composites;

    // Create the output file. Allow overwriting as this is a test
    GroupWrapper fOut = GroupWrapper::createFile("particles.h5", true);
    // Create writes for the two tables of interest
    auto eventsWriter = fOut.makeDataSetWriter<EventData>("Events");
    auto particlesWriter = fOut.makeDataSetWriter<ParticleData>("Particles");
    // Record attributes onto the H5 objects to describe which column is an index.
    // This can be read in python later (though this has to be done manually)
    eventsWriter.setIndex("eventNumber");
    particlesWriter.setIndex("particleID");

    // Now generate some events
    std::mt19937 random;
    std::uniform_int_distribution<std::size_t> nParticleDist(3, 10);
    std::size_t eventNumber = 0;
    std::size_t particleID = 0;
    for (std::size_t idx = 0; idx < 100; ++idx) {
        EventData event = generateEvent(random, eventNumber);
        eventsWriter.write(event);
        for (std::size_t jdx = 0; jdx < nParticleDist(random); ++jdx)
            particlesWriter.write(
                    generateParticle(random, event.eventNumber, particleID, event.beamEnergy));
    }

    return 0;
}