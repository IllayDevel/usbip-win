#include <usbdi.h>

#define K_V(a) {#a, a},

struct macro {
	const char *name;
	unsigned int code;
};

struct macro usb_io_ctrls[]={
K_V( IOCTL_INTERNAL_USB_CYCLE_PORT )
K_V( IOCTL_INTERNAL_USB_ENABLE_PORT )
K_V( IOCTL_INTERNAL_USB_GET_BUS_INFO )
K_V( IOCTL_INTERNAL_USB_GET_BUSGUID_INFO )
K_V( IOCTL_INTERNAL_USB_GET_CONTROLLER_NAME )
K_V( IOCTL_INTERNAL_USB_GET_DEVICE_HANDLE )
K_V( IOCTL_INTERNAL_USB_GET_HUB_COUNT )
K_V( IOCTL_INTERNAL_USB_GET_HUB_NAME )
K_V( IOCTL_INTERNAL_USB_GET_PARENT_HUB_INFO )
K_V( IOCTL_INTERNAL_USB_GET_PORT_STATUS )
K_V( IOCTL_INTERNAL_USB_RESET_PORT )
K_V( IOCTL_INTERNAL_USB_GET_ROOTHUB_PDO )
K_V( IOCTL_INTERNAL_USB_SUBMIT_IDLE_NOTIFICATION )
K_V( IOCTL_INTERNAL_USB_SUBMIT_URB  )
K_V( IOCTL_USB_DIAG_IGNORE_HUBS_ON )
K_V( IOCTL_USB_DIAG_IGNORE_HUBS_OFF )
K_V( IOCTL_USB_DIAGNOSTIC_MODE_OFF )
K_V( IOCTL_USB_DIAGNOSTIC_MODE_ON )
K_V( IOCTL_USB_GET_DESCRIPTOR_FROM_NODE_CONNECTION )
K_V( IOCTL_USB_GET_HUB_CAPABILITIES )
K_V( IOCTL_USB_GET_ROOT_HUB_NAME )
K_V( IOCTL_GET_HCD_DRIVERKEY_NAME )
K_V( IOCTL_USB_GET_NODE_INFORMATION )
K_V( IOCTL_USB_GET_NODE_CONNECTION_INFORMATION )
K_V( IOCTL_USB_GET_NODE_CONNECTION_ATTRIBUTES )
K_V( IOCTL_USB_GET_NODE_CONNECTION_NAME )
K_V( IOCTL_USB_GET_NODE_CONNECTION_DRIVERKEY_NAME )
K_V( IOCTL_USB_HCD_DISABLE_PORT )
K_V( IOCTL_USB_HCD_ENABLE_PORT )
K_V( IOCTL_USB_HCD_GET_STATS_1 )
K_V( IOCTL_USB_HCD_GET_STATS_2 )
{0,0}};

const char * code2name(unsigned int code)
{
	int i;
	for(i=0;usb_io_ctrls[i].name;i++){
		if(code==usb_io_ctrls[i].code)
			return usb_io_ctrls[i].name;
	}
	return "Unknown ioctl code";
}