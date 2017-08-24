kokkos_path=/usr/workspace/wsb/smith516/kokkos
opt=$1
cmake ../ \
  -DCMAKE_BUILD_TYPE=$opt \
  -DKOKKOS_HOST_ARCH=Power8 \
  -DCMAKE_CXX_COMPILER=g++ \
  -DKOKKOS_PATH=/usr/workspace/wsb/smith516/kokkos ../
