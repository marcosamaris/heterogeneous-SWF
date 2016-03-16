#!/bin/bash

if [[ ! -d spack ]]; then
    git clone https://github.com/fpruvost/spack.git
    . ./spack/share/spack/setup-env.sh

    cd spack
    git checkout morse
    
    spack install -v chameleon@trunk+cuda+fxt~quark+examples~shared~simu ^starpu@svn-trunk~shared+cuda+fxt 

fi

