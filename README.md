# kokkos-sandbox
trying stuff with kokkos

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
../build-ray-gnu-host.sh
make
```

### Device build

```
cd build-device
../build-ray-gnu-device.sh
make
```

## scalarToArray

write the value of a host scalar into a device array

### Run

`./scalarToArray.[host|device]`
