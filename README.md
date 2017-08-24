# kokkos-sandbox
trying stuff with kokkos

The build scripts below have a path to kokkos source hardcoded.

## Build on Ray

### Setup
```
module swap xl/beta-2017.07.28 gcc/4.9.3
module load cuda/8.0 cmake/3.7.2
mkdir build-host build-device
```

### Host build
```
cd build-host
../config-ray-gnu-host.sh [Debug|Release]
make
```

### Device build

```
cd build-device
../config-ray-gnu-device.sh [Debug|Release]
make
```

## scalarToArray

write the value of a host scalar into a device array

### Run

`./scalarToArray.[host|device]`
