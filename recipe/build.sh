#!/bin/sh
set -xe

# cross compiling options for conda
RSYNC=rsync
if [[ "${CONDA_BUILD_CROSS_COMPILATION:-}" == "1" ]]; then
  RSYNC=${BUILD_PREFIX}/bin/rsync
fi

# remove -D_FORTIFY_SOURCE=2 because of stack smashing
echo Fixing CPPFLAGS
echo BEFORE: $CPPFLAGS
export CPPFLAGS="${CPPFLAGS//-D_FORTIFY_SOURCE=2 /}"
echo AFTER:$CPPFLAGS

export MSANDERHOME=`pwd`
./configure --conda --openmp

# check configuration
cat config.h
ls $PREFIX/include/*.mod
echo $CFLAGS
echo $FFLAGS

cd src
make -f Makefile.ap install
cd ..

${RSYNC} -av bin dat lib $PREFIX

# remove full path on macOS
if [[ ! -z "$MACOSX_DEPLOYMENT_TARGET" ]]; then
  echo Fixing rpath:
  for f in `find ${SP_DIR} -name "pysander*.so"`; do
    ${PYTHON} ${RECIPE_DIR}/fix_macos_rpath.py ${f}
  done
fi
