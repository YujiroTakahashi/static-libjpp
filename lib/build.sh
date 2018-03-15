#!/bin/bash

JUMANPATH="/usr/local/src/jumanpp-2.0.0-rc2"
ALIB="libjpp.a"
ALIBS=(
    "libjpp_core.a"
    "libjpp_core_codegen.a"
    "libjpp_core_train.a"
    "libjpp_jumandic.a"
    "libjpp_jumandic_spec.a"
    "libjpp_rnn.a"
    "libjpp_util.a"
    "libjumanpp_rnn_legacy.a"
)

echo "Copy Jumanpp static libraries."
cp ${JUMANPATH}/build/src/*/*.a ./
cp ${JUMANPATH}/build/src/*/*/*.a ./

echo "Create libjpp.a."
rm libjpp.a
ar cqT ${ALIB} ${ALIBS[*]}
MRI="CREATE ${ALIB}\n"
for alib in "${ALIBS[@]}" ; do
    MRI+="ADDLIB ${alib}\n"
done
MRI+="SAVE\nEND"
echo -n -e ${MRI} > libjpp.mri
ar -M < libjpp.mri

rm ${ALIBS[@]}
rm libjpp_test*.a
rm libjpp.mri
