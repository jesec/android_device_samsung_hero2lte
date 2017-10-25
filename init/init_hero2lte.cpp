#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void init_target_properties()
{
    std::string bootloader = property_get("ro.bootloader");

    if (bootloader.find("G935S") == 0) {
        property_override("ro.product.model", "SM-G935S");
    } else if (bootloader.find("G935K") == 0) {
        property_override("ro.product.model", "SM-G935K");
    } else if (bootloader.find("G935L") == 0) {
        property_override("ro.product.model", "SM-G935L");
    } else if (bootloader.find("G935W8") == 0) {
        property_override("ro.product.model", "SM-G935W8");
    } else {
        property_override("ro.product.model", "SM-G935F");
    }

    std::string device = property_get("ro.product.device");
    INFO("Found bootloader id %s setting build properties for %s device\n", bootloader.c_str(), device.c_str());
}

void vendor_load_properties()
{
    init_target_properties();
}
