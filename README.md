# MAMMOTH
Electronic structure method package aimed to work with both cartesian and spherical harmonic basis functions, example: cartesian type d(L = 2) orbital has 6d functions, whilst spherical harmonic type has the normal 5d functions.  
The current stage supports only the Molpro regular basis set files.  
The library path is "./basislib/".  
The very fixed format of the input file, recommended extension for input file: *.com  


[Title]
Basis, start  
[Basis set name for each element, one line] (Example: H=STO-3G, O=STO-3G)  
Basis, end  
[charge],[spin multiplicity]  
Geometry, start  
[cartesian xyz](Example: Al, 0.000, 0.001, 0.002)  
Geometry, end  
Hamiltonian = Regular  


No extra empty lines.  
(This'll perhaps be modified in the later stage.)  

Produces nuclear energy, electronic energy, total energy, and molecular orbitals(MOs).  

The program does not support symmetry at the stage.  

#WARNING: THIS PROJECT HAS NOT BEEN FINISHED.  
#PROGRESS ESTIMATE TO FIRST RELEASE: ~30%.  

Thanks for reading through.  
