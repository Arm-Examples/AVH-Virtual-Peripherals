#!/bin/bash
#
# run.sh - Run test on Linux
#
# Copyright 2022 ARM Limited.
# All rights reserved.
#

if [ -z "${PLATFORM_NAME}" ]; then
  PLATFORM_NAME=VHT_MPS3_Corstone_SSE-300_Ethos-U55
fi

VHT_EXE=${PLATFORM_NAME}
VHT_EXE=${VHT_EXE//MPS3_Corstone_SSE-300_Ethos/Corstone_SSE-300_Ethos}

if [[ "${PLATFORM_NAME}" = *"MPS2"* ]]; then
  if [[ "${PLATFORM_NAME}" = *"M23"* ]] || [[ "${PLATFORM_NAME}" = *"M33"* ]] || [[ "${PLATFORM_NAME}" = *"M35P"* ]]; then
    BOARD_NAME=MPS2_IOTKit
  else
    if [[ "${PLATFORM_NAME}" = *"M55"* ]] || [[ "${PLATFORM_NAME}" = *"Olympus"* ]] || [[ "${PLATFORM_NAME}" = *"Mizar"* ]]; then
      BOARD_NAME=MPS2_IOTKit_TCM
    else
      BOARD_NAME=MPS2
    fi
  fi
fi

if [[ "${PLATFORM_NAME}" = *"MPS3"* ]]; then
   BOARD_NAME=MPS3
fi


${VHT_EXE} -V ./python -f ./config/${BOARD_NAME}.config -a ./example-leds.axf $*
