#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>
 
static struct usb_device *device;

//Controller Vendor ID: 0079
//Controller Product ID: 0011
 
static int snes_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
    struct usb_host_interface *iface_desc;
    struct usb_endpoint_descriptor *endpoint;
    int i;
 
    iface_desc = interface->cur_altsetting;
    printk(KERN_INFO "SNES_3000 is now probed: (%04X:%04X)\n",id->idVendor, id->idProduct);
    printk(KERN_INFO "ID->bNumEndpoints: %02X\n", iface_desc->desc.bNumEndpoints);
    printk(KERN_INFO "ID->bInterfaceClass: %02X\n",iface_desc->desc.bInterfaceClass);
 
    for (i = 0; i < iface_desc->desc.bNumEndpoints; i++)
    {
        endpoint = &iface_desc->endpoint[i].desc;
 
        printk(KERN_INFO "ED[%d]->bEndpointAddress: 0x%02X\n",
                i, endpoint->bEndpointAddress);
        printk(KERN_INFO "ED[%d]->bmAttributes: 0x%02X\n",
                i, endpoint->bmAttributes);
        printk(KERN_INFO "ED[%d]->wMaxPacketSize: 0x%04X (%d)\n",
                i, endpoint->wMaxPacketSize, endpoint->wMaxPacketSize);
    }
 
    device = interface_to_usbdev(interface);
    return 0;
}
 
static void snes_disconnect(struct usb_interface *interface)
{
    printk(KERN_INFO "SNES_3000 is now disconnected\n");
}
 
static struct usb_device_id snes_table[] =
{
    { USB_DEVICE(0x0079, 0x0011) },
    {} /* Terminating entry */
};
MODULE_DEVICE_TABLE (usb, snes_table);
 
static struct usb_driver snes_driver =
{
    .name = "snes_driver",
    .probe = snes_probe,
    .disconnect = snes_disconnect,
    .id_table = snes_table,
};
 
static int __init snes_init(void)
{
    return usb_register(&snes_driver);
}
 
static void __exit snes_exit(void)
{
    usb_deregister(&snes_driver);
}
 
module_init(snes_init);
module_exit(snes_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Brandon Turner and Jaime Herzog");
MODULE_DESCRIPTION("SNES Controller Driver");