# LEDs Example

## Description

This example comes with software and Python interface to simulate the behavior of color LEDs.

## Requirements

This example requires Python tiker to be installed. On Ubuntu, this can be installed with:

```
sudo apt install python3-tk
pip install tk
```

## Build

To build for Corstone-300, run:

```
make
```

For other targets, specify PLATFORM\_NAME. E.g.:

```
PLATFORM_NAME=VHT_MPS2_Cortex-M0 make
```

## Run

To run for Corstone-300, run:

```
run.sh
```

For other targets, specify PLATFORM\_NAME. E.g.:

```
PLATFORM_NAME=VHT_MPS2_Cortex-M0 make
```

