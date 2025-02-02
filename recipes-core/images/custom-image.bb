#
# custom Linux image
#   based on EMLinux base image
#
# SPDX-License-Identifier: MIT
#

require recipes-core/images/emlinux-image-base.bb
# require recipes-core/images/emlinux-image-private.inc

DESCRIPTION = "custom target root filesystem"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${LAYERDIR_core}/licenses/COPYING.MIT;md5=838c366f69b72c5df05c96dff79b35f2"

#
# Install recipes or self-build packages
#
IMAGE_INSTALL:append = " \
"

#
# Install Debian packages
#
IMAGE_PREINSTALL:append = " \
"
