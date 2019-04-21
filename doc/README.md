# Project-specific documentation folder for the Library component

## Overview

This folder replicates the general structure envisioned for all aspects
of the CWSW Library suite of components.

Stuff that pertains to this project only, are kept in this folder; the
component's reusable submodule is in the `doc_lib` folder. The
project-specific files can be duplicated in the doc folder of the
projects that use this component; the submodule is intended to be
inserted in this location as a GIT submodule.

## Important folders

Folder              | Description
:---                | :---
doc_lib             | GIT submodule, home to the standardized, reusable portion of the documentation for this component

## Important files

File                | Description
:---                | :---
cwsw_lib.doxyfile   | Project-specific Doxygen project. For most developers, this will be the project to use to generate output.

## Tool-Related Tidbits

File `cwsw_lib.klb.doxyfile` is an example of how to override behvior or
settings of the project, in case they don't work for the specific
deployment environment.
