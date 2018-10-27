# CWSW Library

This repo holds the full set of documents for the small CWSW Library. Being the building block upon which other CWSW components are built, it has no dependencies to other CWSW components. Note: The source code itself is attached as a GIT "submodule."

This component is best placed in the Services layer (if you have one). It contains core, stateless, utility functions that can be called by any application or driver layer module.

Folder | Description
:---   | :---
cfg | Project-specific configuration headers
doc | Documentation folder for this component
src | Container for the CWSW LIB submodule
ut  | Unit Test sources for this component

File | Description
:--- | :---
.cproject | Eclipse project file
.project  | Eclipse project file for this component
cwsw_lib.prj  | LW-CVI project file for this component, ready to import into workspace
