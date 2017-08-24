kokkos_path=/usr/workspace/wsb/smith516/kokkos
opt=$1
cmake ../ \
  -DCMAKE_BUILD_TYPE=$opt \
  -DKOKKOS_ENABLE_CUDA=ON \
  -DKOKKOS_HOST_ARCH=Power8 -DKOKKOS_GPU_ARCH=Pascal60 \
  -DCMAKE_CXX_COMPILER=$kokkos_path/bin/nvcc_wrapper \
  -DKOKKOS_PATH=/usr/workspace/wsb/smith516/kokkos
