#
# EMLinux distro common file
#
# Copyright (c) Cybertrust Japan Co., Ltd. 
#
# Authors:
#  Masahiko Kimoto <masahiko.kimoto@miraclelinux.com>
#
# SPDX-License-Identifier: MIT
#

# require include/security_flags.inc

INHERIT += "sdk-installer"

DISTRO_KERNELS ?= "linux-cip"
KERNEL_NAME ?= "cip"

DISTRO_APT_SOURCES = "conf/distro/emlinux-sid.list"

IMAGER_INSTALL:wic = "parted \
  gdisk \
  util-linux \
  dosfstools \
  mtools \
  e2fsprogs \
  python3-distutils \
  bmap-tools \
  tar \
  fdisk"

IMAGE_PREINSTALL:append = " netbase"

WKS_FILE ?= "${MACHINE}.wks"

SDK_PREINSTALL += "bc"

SDK_INSTALL += "linux-headers-${KERNEL_NAME}"
