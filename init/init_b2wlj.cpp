/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

void common_properties()
{
    property_set("rild.libargs", "-d /dev/smd0");
    property_set("ro.ril.hsdpa.category", "14");
    property_set("ro.ril.hsxpa", "4");
    property_set("ro.ril.disable.cpc", "1");
}

void cdma_properties(char const default_cdma_sub[], char const default_network[])
{
    property_set("ro.telephony.default_cdma_sub", default_cdma_sub);
    property_set("ro.telephony.default_network", default_network);
    property_set("telephony.lteOnCdmaDevice", "1");
    property_set("ro.ril.enable.sdr", "0");
    property_set("persist.radio.snapshot_enabled", "1");
    property_set("persist.radio.snapshot_timer", "22");
}

void gsm_properties(char const default_network[])
{
    property_set("ro.telephony.default_network", default_network);
    property_set("telephony.lteOnGsmDevice", "1");
    property_set("ro.ril.radio.svn", "1");
}

void vendor_load_properties()
{
    std::string platform;
    std::string bootmid;
    std::string device;

    platform = property_get("ro.board.platform");
    if (platform != ANDROID_TARGET)
        return;

    bootmid = property_get("ro.boot.mid");

    if (bootmid == "0P6B10000") {
        /* b2wlj */
        common_properties();
        cdma_properties("0", "10");
        property_set("ro.product.model", "b2wlj");
        property_set("ro.build.fingerprint", "htc/HTL23/htc_b2wlj:6.0/MRA58K/708002.3:user/release-keys");
        property_set("ro.build.description", "6.21.605.3 CL708002 release-keys");
        property_set("ro.product.device", "htc_b2wlj");
        property_set("ro.build.product", "htc_b2wlj");
        property_set("ro.ril.vzw.feature", "1");
        property_set("ro.ril.oem.ecclist", "911,*911,#911");
        property_set("ro.ril.enable.a52", "0");
        property_set("ro.ril.enable.a53", "1");
        property_set("ro.ril.enable.dtm", "0");
        property_set("ro.ril.enable.gea3", "1");
        property_set("ro.ril.enable.r8fd", "1");
        property_set("ro.ril.disable.fd.plmn.prefix", "23402,23410,23411,23420");
        property_set("ro.ril.fast.dormancy.cdma.rule", "0");
        property_set("ro.ril.gprsclass", "12");
        property_set("ro.ril.att.feature", "0");
        property_set("ro.ril.enable.managed.roaming", "1");
        property_set("ro.ril.oem.show.act", "0");
        property_set("ro.ril.pdpnumber.policy.roaming", "3");
        property_set("ro.ril.set.mtusize", "1428");
        property_set("ro.ril.air.enabled", "0");
        property_set("ro.ril.wp.feature", "1");
        property_set("ro.cdma.data_retry_config", "max_retries=infinite,0,0,60000,120000,480000,900000");
        property_set("ro.gsm.data_retry_config", "max_retries=infinite,0,0,60000,120000,480000,900000");
        property_set("ro.gsm.2nd_data_retry_config", "max_retries=infinite,0,0,60000,120000,480000,900000");
        property_set("ro.ril.gsm.to.lte.blind.redir", "0");
        property_set("ro.config.svlte1x", "true");
        property_set("ro.telephony.get_imsi_from_sim", "true");
    } else {
        /* b2ul */
        common_properties();
        gsm_properties("9");
        property_set("ro.product.model", "b2ul");
        property_set("ro.build.fingerprint", "htc/b2ul/htc_b2ul:6.0/MRA58K.H6/648564:user/release-keys");
        property_set("ro.build.description", "5.07.1700.6 CL648564 release-keys");
        property_set("ro.product.device", "htc_b2ul");
    }

    device = property_get("ro.product.device");
    ERROR("Found bootmid %s setting build properties for %s device\n", bootmid.c_str(), device.c_str());
}
