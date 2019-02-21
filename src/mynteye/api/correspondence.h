// Copyright 2018 Slightech Co., Ltd. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#ifndef MYNTEYE_API_CONFIG_H_
#define MYNTEYE_API_CONFIG_H_
#pragma once

#include <memory>
#include <mutex>
#include <vector>

#include "mynteye/api.h"
#include "mynteye/device/callbacks.h"

MYNTEYE_BEGIN_NAMESPACE

class Correspondence {
 public:
  Correspondence(const std::shared_ptr<Device> &device, const Stream &stream);
  ~Correspondence();

  void OnStreamDataCallback(const Stream &stream, const api::StreamData &data);
  void OnMotionDataCallback(const device::MotionData &data);

  void SetMotionCallback(API::motion_callback_t callback);

  std::vector<api::MotionData> GetMotionDatas();

 private:
  std::shared_ptr<Device> device_;
  Stream stream_;
  API::motion_callback_t motion_callback_;
  std::vector<device::MotionData> motion_datas_;
  std::mutex mtx_motion_datas_;
};

MYNTEYE_END_NAMESPACE

#endif  // MYNTEYE_API_CONFIG_H_