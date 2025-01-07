# tutorial 1 : custom app development in MOOSE

[Mesh]	
	type		= GeneratedMesh
	dim			= 2
	nx			= 100
	ny 			= 10
	xmax		= 0.304
	ymax		= 0.0257
[]

[Problem]
	type					= FEProblem
	coord_type		= RZ
	rz_coord_axis	= X
[]

[Variables]
	[pressure]
	[]
[]

# [Kernels]
# 	[diffusion]
# 		type			= ADDiffusion
# 		variable	= pressure
# 	[]
# []

[Kernels]
	[diffusion]
		type					= DarcyPressure
		variable			= pressure
		permeability	= 0.8451e-09
	[]
[]

[BCs]
	[inlet]
		type			= ADDirichletBC
		variable	= pressure
		boundary	= left
		value			= 4000
	[]

	[outlet]
		type			= ADDirichletBC
		variable	= pressure
		boundary	= right
		value			= 0
	[]
[]

[Executioner]
	type				= Steady
	solve_type	= NEWTON

	petsc_options_iname		= '-pc_type		-pc_hypre_type'
	petsc_options_value		= 'hypre			boomeramg'
[]

[Outputs]
	exodus	= true
[]
	
