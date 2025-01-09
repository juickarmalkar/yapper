#include "DarcyVelocity.h"

#include "metaphysicl/raw_type.h"

registerMooseObject("YapperApp", DarcyVelocity);

InputParameters
DarcyVelocity::validParams()
{
    InputParameters params = VectorAuxKernel::validParams();
    params.addClassDescription("Compute volumetric flux (which has units of velocity) for a given pressure "
    "gradient, permeability, and viscosity using Darcy's Law: $\\vec{u} = -\\frac{\\mathbf{K}}{\\mu} "
    "\\nabla p$");

    params.addRequiredCoupledVar("pressure","The pressure field.");

    return params;
}

DarcyVelocity::DarcyVelocity(const InputParameters & parameters)
    : VectorAuxKernel(parameters),
    _grad_p(coupledGradient("pressure")),

    _permeability(getADMaterialProperty<Real>("permeability")),
    _viscosity(getADMaterialProperty<Real>("viscosity"))
    {

    }

RealVectorValue
DarcyVelocity::computeValue()
{
    return -MetaPhysicL::raw_value(_permeability[_qp] / _viscosity[_qp]) * _grad_p[_qp];
}