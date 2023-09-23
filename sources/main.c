/*
 * main.c
 *
 *  Created on: 19 sep. 2023
 *      Author: Daniel
 */
#include "fsl_device_registers.h"
#include "clock_config.h"
#include "board.h"

#include <stdio.h>
#include <stdlib.h>

#include "pin_mux.h"


#include <stdio.h>
#include <stdlib.h>

#include "usb_device_config.h"
#include "usb.h"
#include "usb_device.h"

#include "usb_device_class.h"
#include "usb_device_cdc_acm.h"
#include "usb_device_ch9.h"

#include "usb_device_descriptor.h"
#include "virtual_com.h"

#define BUFFER_LENGTH  100

int main(void)
{

	uint8_t buffer_rx[BUFFER_LENGTH];
	uint32_t bytes_recibidos;

	BOARD_InitPins();
    BOARD_BootClockRUN();
    USB_AppInit();

    while (1)
    {
        //APPTask();

    	if(bytes_recibidos = virtual_com_recv(buffer_rx, sizeof(buffer_rx)))
    	{
    		virtual_com_send(buffer_rx, bytes_recibidos);
    	}

    }

}
