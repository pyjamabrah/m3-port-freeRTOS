# FreeRTOS Port tutorial

## Use needs to implement:
1. `pxPortInitialiseStack'
1. `vPortEnterCritical'
1. `vPortExitCritical'
1. `xPortStartScheduler'
1. `vPortEndScheduler'
1. `pvPortMalloc'
1. `vPortFree'
1. `memset'
1. `memcpy'

## Setup

```
.
├── FreeRTOS-Kernel
└── port
```

1. FreeRTOS-Kernel - `https://github.com/FreeRTOS/FreeRTOS-Kernel.git`
1. port - this repo

## Commands

from port/

### Build
```
make
```

### QEMU

```
make qemu
```

### GDB connect

```
make gdb
```

# Utilities

```
sudo apt isntall gdb-multiarch make gcc-arm-none-eabi qemu-system
```
