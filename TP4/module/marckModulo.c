#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/utsname.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Marcos Agustín Reyeros");
MODULE_DESCRIPTION("Módulo de ejemplo que imprime el hostname al cargar");
MODULE_VERSION("0.1");

static int __init mimodulo_init(void) {
    struct new_utsname *uts = utsname();
    printk(KERN_INFO "mimodulo: Hola! Nombre del equipo: %s\n", uts->nodename);
    return 0;
}

static void __exit mimodulo_exit(void) {
    printk(KERN_INFO "mimodulo: Chau chau!\n");
}

module_init(mimodulo_init);
module_exit(mimodulo_exit);
