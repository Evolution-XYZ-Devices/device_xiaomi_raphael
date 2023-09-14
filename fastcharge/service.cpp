/*
 * Copyright (C) 2023 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "fastcharge@1.0-service.xiaomi_raphael"

#include <android-base/logging.h>
#include <hidl/HidlTransportSupport.h>

#include "FastCharge.h"
#include "RestrictedCurrent.h"

using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;

using vendor::lineage::fastcharge::V1_0::IFastCharge;
using vendor::lineage::fastcharge::V1_0::implementation::FastCharge;
using vendor::lineage::fastcharge::V1_0::implementation::RestrictedCurrent;

using android::OK;
using android::status_t;

int main() {
  android::sp<FastCharge> scharge = new FastCharge();
  android::sp<RestrictedCurrent> scurrent = new RestrictedCurrent();

  configureRpcThreadpool(1, true);

  status_t status = scharge->registerAsService();
  if (status != OK) {
    LOG(ERROR) << "Could not register service for FastCharge HAL FastCharge Iface.";
    return 1;
  }

  status = scurrent->registerAsService();
  if (status != OK) {
      LOG(ERROR) << "Could not register service for FastCharge HAL RestrictedCurrent Iface.";
      return 1;
  }

  LOG(INFO) << "FastCharge HAL service ready.";

  joinRpcThreadpool();

  // In normal operation, we don't expect the thread pool to shutdown
  LOG(ERROR) << "FastCharge HAL service is shutting down.";
  return 1;
}
