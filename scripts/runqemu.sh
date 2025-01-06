#!/bin/sh

qemu-system-riscv64 -device virtio-blk-device,drive=disk0 -drive file=./tmp/deploy/images/qemu-riscv64/emlinux-image-base-emlinux-sid-qemu-riscv64.ext4,id=disk0,format=raw -kernel ./tmp/deploy/images/qemu-riscv64/emlinux-image-base-emlinux-sid-qemu-riscv64-vmlinux -initrd ./tmp/deploy/images/qemu-riscv64/emlinux-image-base-emlinux-sid-qemu-riscv64-initrd.img -m 2G -smp 2 -serial mon:stdio  -append "root=/dev/vda rw console=ttyS0" -machine virt -nographic
