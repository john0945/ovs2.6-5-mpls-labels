#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0xc6c01fa, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x7af5a224, __VMLINUX_SYMBOL_STR(ovs_gre_fill_metadata_dst) },
	{ 0x70cf766, __VMLINUX_SYMBOL_STR(rpl_gre_fb_xmit) },
	{ 0x33578cef, __VMLINUX_SYMBOL_STR(ovs_netdev_tunnel_destroy) },
	{ 0xa48a55c9, __VMLINUX_SYMBOL_STR(ovs_vport_ops_unregister) },
	{ 0x4358af77, __VMLINUX_SYMBOL_STR(__ovs_vport_ops_register) },
	{ 0x78cc4cb7, __VMLINUX_SYMBOL_STR(ovs_vport_free) },
	{ 0x532a09ba, __VMLINUX_SYMBOL_STR(rpl_rtnl_delete_link) },
	{ 0xc5927d9, __VMLINUX_SYMBOL_STR(ovs_netdev_link) },
	{ 0x6e720ff2, __VMLINUX_SYMBOL_STR(rtnl_unlock) },
	{ 0x2a2938d1, __VMLINUX_SYMBOL_STR(dev_change_flags) },
	{ 0x30f7e04e, __VMLINUX_SYMBOL_STR(rpl_gretap_fb_dev_create) },
	{ 0xc7a4fbed, __VMLINUX_SYMBOL_STR(rtnl_lock) },
	{ 0xd43bb19b, __VMLINUX_SYMBOL_STR(ovs_vport_alloc) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=openvswitch";


MODULE_INFO(srcversion, "E9CA8E2F1531EB3F7001587");
