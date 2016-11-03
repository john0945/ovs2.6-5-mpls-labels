#!/usr/bin/env bash
set -e
set -o nounset

echo "Creating and Installing Open vSwitch packages..."

OVS_SRC=/root/ovs2.6-5-mpls-labels

cd $OVS_SRC

# Remove any old packages

$remove openvswitch-common openvswitch-datapath-dkms openvswitch-pki openvswitch-switch \
		openvswitch-controller || true

# Get build deps
$install build-essential fakeroot debhelper autoconf automake libssl-dev \
		 pkg-config bzip2 openssl python-all procps python-qt4 \
		 python-zopeinterface python-twisted-conch dkms dh-python dh-autoreconf \
		 uuid-runtime

# Build OVS
parallel=`grep processor /proc/cpuinfo | wc -l`
cd /root/ovs2.6-5-mpls-labels
		DEB_BUILD_OPTIONS='parallel=$parallel nocheck' fakeroot debian/rules binary
cd ..
for pkg in common datapath-dkms pki switch; do
	pkg=openvswitch-${pkg}_$OVS_RELEASE*.deb
	echo "Installing $pkg"
	$pkginst $pkg
done
if $pkginst openvswitch-controller_$OVS_RELEASE*.deb 2>/dev/null; then
	echo "Ignoring error installing openvswitch-controller"
fi

/sbin/modinfo openvswitch
sudo ovs-vsctl show
# Switch can run on its own, but
# Mininet should control the controller
# This appears to only be an issue on Ubuntu/Debian
if sudo service openvswitch-controller stop 2>/dev/null; then
	echo "Stopped running controller"
fi
if [ -e /etc/init.d/openvswitch-controller ]; then
	sudo update-rc.d openvswitch-controller disable
fi