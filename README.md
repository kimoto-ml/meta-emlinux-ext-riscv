# meta-emlinux-ext-riscv

## How to build

### checkout meta-emlinux

checkout meta-emlinux repository from https://github.com/miraclelinux/meta-emlinux.

```
mkdir -p emlinux/repos/
git clone https://github.com/miraclelinux/meta-emlinux.git
```

### build docker image

```
cd repos/meta-emlinux/docker/
./run.sh build
./run.sh
apt install mmdebstrap
```
note: mmdepstrap is required by current isar.

### checkout mainline of isar

```
* inside container

cd ~/work/
source ./setup-emlinux build

* outside of container

cd ~/work/repos/
cd isar
git checkout main
cd ../isar-cip-core
git checkout main
```

### edit configurations.

```
echo 'BBLAYERS += "${TOPDIR}/../repos/meta-emlinux-ext-riscv"' >> build/conf/bblayers.conf

echo 'MACHINE = "qemu-riscv64"' >> build/conf/local.conf
echo 'DISTRO = "emlinux-sid"' >> build/conf/local.conf
```

### bitbake in container

```
* inside container
bitbake emlinux-image-base
````

this produces following files under build/tmp/deploy/image/qemu-riscv64/

* emlinux-image-base-emlinux-sid-qemu-riscv64.dpkg_status
* emlinux-image-base-emlinux-sid-qemu-riscv64.ext4
* emlinux-image-base-emlinux-sid-qemu-riscv64-initrd.img
* emlinux-image-base-emlinux-sid-qemu-riscv64.manifest
* emlinux-image-base-emlinux-sid-qemu-riscv64-vmlinux

### how to run the RISC-V images.

```
./repos/meta-emlinux-ext-riscv/scripts/runqemu.sh
```

