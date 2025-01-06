// source file for DarcyPressure kernel

// the header file for this object is included. 
// then, the registerMooseObject() method is called for "YapperApp" and the DarcyPressure object.
// the validParams() method is used
// in the constructor method, the _permeability and _viscosity attributes are set according to the values
// that are given in the problem statement
// the precomputeQpResidual() method is programmed to return the LHS of the weak form, except that
// the gradphi (_grad_test) term is automatically handled by the base class.

#include "DarcyPressure.h"

registerMooseObject("YapperApp", DarcyPressure);

InputParameters
DarcyPressure::validParams()

{
    InputParameters params = ADKernelGrad::validParams();
    params.addClassDescription("Compute the diffusion term for Darcy pressure ($p$) equation: "
                                "$-\\nabla \\cdot \\frac{\\mathbf{K}}{\\mu} \\nabla p = 0$");
    return params;
}

DarcyPressure::DarcyPressure(const InputParameters & parameters)
    : ADKernelGrad(parameters),

    // set the coefficients for the pressure kernel

    _permeability(0.8451e-09),
    _viscosity(7.98e-04)

{

}

ADRealVectorValue
DarcyPressure::precomputeQpResidual()

{
    return (_permeability / _viscosity) * _grad_u[_qp];
}

