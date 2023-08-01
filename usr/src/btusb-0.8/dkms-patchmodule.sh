#!/bin/bash

vers=(${kernelver//./ })   # split kernel version into individual elements
major="${vers[0]}"
minor="${vers[1]}"
version="$major.$minor"    # recombine as needed
subver=$(grep "SUBLEVEL =" /usr/src/linux-headers-${kernelver}/Makefile | tr -d " " | cut -d "=" -f 2)
plain_vers=(${kernelver/-generic/})

PACKAGE_NAME=btusb
PACKAGE_VERSION=0.8

build_dir="/var/lib/dkms/${PACKAGE_NAME}/${PACKAGE_VERSION}/build/"

echo build-dir: ${build_dir}

cd /usr/src/linux
git pull origin master
git archive --format=tar tags/v$version drivers/bluetooth/ | (cd ${build_dir} && tar xf -  --strip-components=2)
cd ${build_dir}
patch < /usr/src/btusb-0.8/0001-Added-support-for-MT7922-Bluetooth-adapter.patch