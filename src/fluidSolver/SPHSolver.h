#ifndef SPHSOLVER_H
#define SPHSOLVER_H

#include <fluidSolver/fluidSolver.h>
#include <fluidSolver/SPHGrid.h>
#include <fluidSolver/SPHKernels.h>

typedef enum {
    SPHStiffness,
    SPHViscosity,
    SPHRestDensity,
    SPHMass
} SPHConstantType;

// ---------------------------------------------------- //
// SPHSolver
// ---------------------------------------------------- //
class SPHSolver : public FluidSolver
{
public:
    SPHSolver(
        const glm::vec3& containerDim,
        const glm::vec3& particleDim,
        const float separation,
        const float cellSize,
        const float stiffness,
        const float viscosity,
        const float mass,
        const float restDensity
        );

    virtual ~SPHSolver();

    void SetConstant(
        SPHConstantType type,
        float value
        );
    virtual void Update(const float deltaT);

protected:

    SPHGrid* m_grid;

    // -- Particle info
    float m_cellSize;
    float m_stiffness;
    float m_viscosity;
    float m_restDensity;
    float m_kernelRadius;

    void CalculateDensity(
        FluidParticle* particle
        );
    void CalculatePressure(
        FluidParticle* particle
        );
    void CalculatePressureForceField(
        FluidParticle* particle
        );
    void CalculateViscosityForceField(
        FluidParticle* particle
        );
    void UpdateDynamics(
        FluidParticle* particle,
        const float deltaT
        );
};

#endif /* SPHSOLVER_H */
