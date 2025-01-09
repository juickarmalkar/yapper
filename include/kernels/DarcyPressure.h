// the DarcyPressure class was defined as a type of ADKernelGrad object, so the header file ADKernelGrad.h
// is included. a MooseObject must have a validParams() method and a constructor, so these are included as 
// part of public members. the precomputeQpResidual() method is overridden so that the weak form equation 
// may set its returned value in accordance with the methods prescribed in Table 1

// two variables, _permeability and _viscosity are created to store the values for K and mu
// K is a tensor, but using the assumption of isotropy, its scalar value is considered.

// K and mu are assigned constant types, so that their values are not accidentally modified 
// after they are set by the constructor method.

#pragma once

// including the "ADKernel" base class here so it can be extended later on

#include "ADKernelGrad.h"

// compute the residual contribution: K / mu * grad_test * grad_u

class DarcyPressure : public ADKernelGrad
{
    public:

        static InputParameters validParams();

        DarcyPressure(const InputParameters & parameters);

    protected:

        // ADKernel objects must override precomputeQpResidual

        virtual ADRealVectorValue precomputeQpResidual() override;

        // variables which hold the value for K and mu

        const ADMaterialProperty<Real> & _permeability;
        const ADMaterialProperty<Real> & _viscosity;
};