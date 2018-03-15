#!/bin/bash

JUMANPATH="/usr/local/src/jumanpp-2.0.0-rc2"

echo "Copy Jumanpp include files."
rsync -arm \
    --include="*/" \
    --include="*.h" \
    --include="*.hpp" \
    --exclude="*" \
    ${JUMANPATH}/src/ ./

cp ${JUMANPATH}/build/src/core/cfg/*.h ./
cp ${JUMANPATH}/build/src/jumandic/gen/*.h ./
