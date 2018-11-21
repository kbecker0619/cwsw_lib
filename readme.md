# CWSW Library

## Overview
This repo holds the full set of documents for the small CWSW Library. Being the building block upon which other CWSW components are built, it has no dependencies to other CWSW components.

This repo is the composed of a mixture of direct files and folders, and GIT submodules for reusable portions of the component; namely, sources, documentation, and unit testing (this component uses CUnit, hosted natively by NetBeans).

The source repo for this component is best inserted in the Services layer (if you have one). It contains core, stateless, utility functions that can be called by any application or driver layer module.

## Important folders
Folder   | Description
:---   	 | :---
cwsw_lib | GIT submodule: Container for the CWSW LIB submodule
app		 | demo app that illustrates how to use this component
cfg      | Project-specific configuration headers (demo app)
doc 	 | GIT submodule: Documentation folder for this component
ut  	 | GIT submodule: Unit Test sources for this component


## Important files
Almost all of the files in the root directory, are for various IDEs and build environments supported by this component.

### Eclipse, NXP S32DS, & other Eclipse-based tools
File 		 | Description
:--- 		 | :---
.cproject 	 | Eclipse project file for demo app
.project  	 | Eclipse project file for demo app
Debug		 | Eclipse build-output folder for demo app
cwsw_lib.prj | LW-CVI project file for this component, ready to import into workspace

### NetBeans 8.2
File 		 | Description
:--- 		 | :---
nbproject	 | NetBeans project definitions
.dep.inc	 | Component of NB makefile
Makefile	 | NetBeans-created makefile

### MSVC++ 2008
File 		 | Description
:--- 		 | :---
cwsw_lib.vcproj | MSVC Project file
