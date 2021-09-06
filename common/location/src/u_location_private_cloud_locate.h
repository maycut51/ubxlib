/*
 * Copyright 2020 u-blox Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _U_LOCATION_PRIVATE_CLOUD_LOCATE_H_
#define _U_LOCATION_PRIVATE_CLOUD_LOCATE_H_

/* No #includes allowed here */

/** @file
 * @brief This header file defines functions that do not form part,
 * of the location API but are used internally to provide the Cloud
 * Locate API.
 */

#ifdef __cplusplus
extern "C" {
#endif

/* ----------------------------------------------------------------
 * COMPILE-TIME MACROS
 * -------------------------------------------------------------- */

/* ----------------------------------------------------------------
 * TYPES
 * -------------------------------------------------------------- */

/* ----------------------------------------------------------------
 * FUNCTIONS
 * -------------------------------------------------------------- */

/** Run Cloud Locate.
 *
 * @param networkHandle      the handle of the thing providing the
 *                           MQTT connection (e.g. the cellular module).
 * @param gnssHandle         the handle of the GNSS device that will
 *                           provide the RRLP data for Cloud Locate.
 * @param pMqttClientContext the context of an MQTT client that can
 *                           be used to communicate with the Cloud
 *                           Locate service; must already have been
 *                           logged-in to the Cloud Locate service.
 * @param svsThreshold       the minimum number of satellites that
 *                           must be visible for an RRLP data block
 *                           to be considered valid; use -1 for
 *                           "don't care".
 * @param pClientIdStr       the Thingstream device ID, obtained from
 *                           the Thingstream portal, for this device;
 *                           must be provided if pLocation is not NULL,
 *                           must be null-terminated.
 * @param pLocation          a place to put the location once established,
 *                           may be NULL if this device does not require
 *                           the location, i.e. it is sufficient for it
 *                           to be known in the cloud.
 * @param pKeepGoingCallback a callback function that governs how long
 *                           location establishment is allowed to take.
 *                           This function is called while waiting for
 *                           location establishment to complete; location
 *                           establishment will only continue while
 *                           it returns true.  This allows the caller
 *                           to terminate the locating process at
 *                           their convenience.  This function may
 *                           also be used to feed any watchdog
 *                           timer that might be running.  May be NULL,
 *                           in which case location establishment will
 *                           stop when U_LOCATION_TIMEOUT_SECONDS have
 *                           elapsed.  The single int32_t parameter is
 *                           the network handle.
 */
int32_t uLocationPrivateCloudLocate(int32_t networkHandle,
                                    int32_t gnssHandle,
                                    uMqttClientContext_t *pMqttClientContext,
                                    int32_t svsThreshold,
                                    const char *pClientIdStr,
                                    uLocation_t *pLocation,
                                    bool (*pKeepGoingCallback) (int32_t));

#ifdef __cplusplus
}
#endif

#endif // _U_LOCATION_PRIVATE_CLOUD_LOCATE_H_

// End of file
