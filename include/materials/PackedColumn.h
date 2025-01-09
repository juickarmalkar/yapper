// header file for material property K / mu to be used in the Darcy pressure equation

#pragma once

#include "Material.h"

// include a helper class from MOOSE that linearly interpolates abscissa-ordinate pairs

#include "LinearInterpolation.h"

// formulation to compute the permeability of a porous medium made up of packed steel spheres of a 
// specified diameter in accordance with Pamuk and Ozdemir (2012). this also provides a specified dynamic
// viscosity of the fluid in the medium.

class PackedColumn : public Material

{
    public:
        static InputParameters validParams();

        PackedColumn(const InputParameters & parameters);

    protected:
        // necessary override, this is where the property values are set.
        virtual void computeQpProperties() override;

        // the inputs for the diameter of the spheres in the column and the dynamic viscosity of the fluid
        const Real & _diameter;
        const Real & _input_viscosity;

        // this object interpolates permeability (m^2) based on the diameter (mm)
        LinearInterpolation _permeability_interpolation;

        // the material property objects that hold values for permeability (K) and dynamic viscosity (mu)
        ADMaterialProperty<Real> & _permeability;
        ADMaterialProperty<Real> & _viscosity;
};