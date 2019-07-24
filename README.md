# MAMMOTH
Electronic structure method package aimed to work with both cartesian and spherical harmonic basis functions, example: cartesian type d(L = 2) orbital has 6d functions, whilst spherical harmonic type has the normal 5d functions.\n
The current stage supports only the Molpro regular basis set files.\n
The library path is "./basislib/".\n
The very fixed format of the input file, recommended extension for input file: *.com\n


[Title]
Basis, start\n
[Basis set name for each element, one line] (Example: H=STO-3G, O=STO-3G)\n
Basis, end\n
[charge],[spin multiplicity]\n
Geometry, start\n
[cartesian xyz](Example: Al, 0.000, 0.001, 0.002)\n
Geometry, end\n
Hamiltonian = Regular\n


No extra empty lines.\n
(This'll perhaps be modified in the later stage.)\n

Produces nuclear energy, electronic energy, total energy, and molecular orbitals(MOs).\n

The program does not support symmetry at the stage.\n

#WARNING: THIS PROJECT HAS NOT BEEN FINISHED.\n
#PROGRESS ESTIMATE TO FIRST RELEASE: ~30%.\n

Thanks for reading through.\n
