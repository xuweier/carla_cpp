// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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

/*!
 * @file CameraInfo.cpp
 * 该源文件包含接口定义文件(Interface definition file,IDL)中所描述类型的定义。
 *
 * 这个文件是由工具生成的。
 */

#ifdef _WIN32
// 移除Visual Studio上的链接器警告LNK4221
namespace {
char dummy;
}  // namespace
#endif  // _WIN32

#include "CameraInfo.h"
#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>
#include <cmath>

#define builtin_interfaces_msg_Time_max_cdr_typesize 8ULL;
#define sensor_msgs_msg_CameraInfo_max_cdr_typesize 3793ULL;
#define sensor_msgs_msg_RegionOfInterest_max_cdr_typesize 17ULL;
#define std_msgs_msg_Header_max_cdr_typesize 268ULL;
#define builtin_interfaces_msg_Time_max_key_cdr_typesize 0ULL;
#define sensor_msgs_msg_CameraInfo_max_key_cdr_typesize 0ULL;
#define sensor_msgs_msg_RegionOfInterest_max_key_cdr_typesize 0ULL;
#define std_msgs_msg_Header_max_key_cdr_typesize 0ULL;

sensor_msgs::msg::CameraInfo::CameraInfo(uint32_t height, uint32_t width, double fov) :
m_height(height),
m_width(width)
{
    // 字符串 m_distortion_model
    m_distortion_model = "plumb_bob";

    const double cx = static_cast<double>(m_width) / 2.0;
    const double cy = static_cast<double>(m_height) / 2.0;
    const double fx = static_cast<double>(m_width) / (2.0 * std::tan(fov) * M_PI / 360.0);
    const double fy = fx;

    m_d = { 0.0, 0.0, 0.0, 0.0, 0.0 };
    m_k = {fx, 0.0, cx, 0.0, fy, cy, 0.0, 0.0, 1.0};
    m_r = { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 };
    m_p = {fx, 0.0, cx, 0.0, 0.0, fy, cy, 0.0, 0.0, 0.0, 1.0, 0.0};

    m_binning_x = 0;
    m_binning_y = 0;
}

sensor_msgs::msg::CameraInfo::~CameraInfo()
{
}

sensor_msgs::msg::CameraInfo::CameraInfo(
        const CameraInfo& x)
{
    m_header = x.m_header;
    m_height = x.m_height;
    m_width = x.m_width;
    m_distortion_model = x.m_distortion_model;
    m_d = x.m_d;
    m_k = x.m_k;
    m_r = x.m_r;
    m_p = x.m_p;
    m_binning_x = x.m_binning_x;
    m_binning_y = x.m_binning_y;
    m_roi = x.m_roi;
}

sensor_msgs::msg::CameraInfo::CameraInfo(
        CameraInfo&& x) noexcept
{
    m_header = std::move(x.m_header);
    m_height = x.m_height;
    m_width = x.m_width;
    m_distortion_model = std::move(x.m_distortion_model);
    m_d = std::move(x.m_d);
    m_k = std::move(x.m_k);
    m_r = std::move(x.m_r);
    m_p = std::move(x.m_p);
    m_binning_x = x.m_binning_x;
    m_binning_y = x.m_binning_y;
    m_roi = std::move(x.m_roi);
}

sensor_msgs::msg::CameraInfo& sensor_msgs::msg::CameraInfo::operator =(
        const CameraInfo& x)
{
    m_header = x.m_header;
    m_height = x.m_height;
    m_width = x.m_width;
    m_distortion_model = x.m_distortion_model;
    m_d = x.m_d;
    m_k = x.m_k;
    m_r = x.m_r;
    m_p = x.m_p;
    m_binning_x = x.m_binning_x;
    m_binning_y = x.m_binning_y;
    m_roi = x.m_roi;

    return *this;
}

sensor_msgs::msg::CameraInfo& sensor_msgs::msg::CameraInfo::operator =(
        CameraInfo&& x) noexcept
{
    m_header = std::move(x.m_header);
    m_height = x.m_height;
    m_width = x.m_width;
    m_distortion_model = std::move(x.m_distortion_model);
    m_d = std::move(x.m_d);
    m_k = std::move(x.m_k);
    m_r = std::move(x.m_r);
    m_p = std::move(x.m_p);
    m_binning_x = x.m_binning_x;
    m_binning_y = x.m_binning_y;
    m_roi = std::move(x.m_roi);

    return *this;
}

bool sensor_msgs::msg::CameraInfo::operator ==(
        const CameraInfo& x) const
{
    return (m_header == x.m_header && m_height == x.m_height && m_width == x.m_width && m_distortion_model == x.m_distortion_model && m_d == x.m_d && m_k == x.m_k && m_r == x.m_r && m_p == x.m_p && m_binning_x == x.m_binning_x && m_binning_y == x.m_binning_y && m_roi == x.m_roi);
}

bool sensor_msgs::msg::CameraInfo::operator !=(
        const CameraInfo& x) const
{
    return !(*this == x);
}

size_t sensor_msgs::msg::CameraInfo::getMaxCdrSerializedSize(
        size_t current_alignment)
{
    static_cast<void>(current_alignment);
    return sensor_msgs_msg_CameraInfo_max_cdr_typesize;
}

size_t sensor_msgs::msg::CameraInfo::getCdrSerializedSize(
        const sensor_msgs::msg::CameraInfo& data,
        size_t current_alignment)
{
    (void)data;
    size_t initial_alignment = current_alignment;
    current_alignment += std_msgs::msg::Header::getCdrSerializedSize(data.header(), current_alignment);
    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);
    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);
    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4) + data.distortion_model().size() + 1;
    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);

    if (data.D().size() > 0)
    {
        current_alignment += (data.D().size() * 8) + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);
    }

    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);

    if (data.k().size() > 0)
    {
        current_alignment += (data.k().size() * 8) + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);
    }

    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);

    if (data.r().size() > 0)
    {
        current_alignment += (data.r().size() * 8) + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);
    }

    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);

    if (data.p().size() > 0)
    {
        current_alignment += (data.p().size() * 8) + eprosima::fastcdr::Cdr::alignment(current_alignment, 8);
    }

    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);
    current_alignment += 4 + eprosima::fastcdr::Cdr::alignment(current_alignment, 4);
    current_alignment += sensor_msgs::msg::RegionOfInterest::getCdrSerializedSize(data.roi(), current_alignment);

    return current_alignment - initial_alignment;
}

void sensor_msgs::msg::CameraInfo::serialize(
        eprosima::fastcdr::Cdr& scdr) const
{
    scdr << m_header;
    scdr << m_height;
    scdr << m_width;
    scdr << m_distortion_model.c_str();
    scdr << m_d;
    scdr << m_k;
    scdr << m_r;
    scdr << m_p;
    scdr << m_binning_x;
    scdr << m_binning_y;
    scdr << m_roi;
}

void sensor_msgs::msg::CameraInfo::deserialize(
        eprosima::fastcdr::Cdr& dcdr)
{
    dcdr >> m_header;
    dcdr >> m_height;
    dcdr >> m_width;
    dcdr >> m_distortion_model;
    dcdr >> m_d;
    dcdr >> m_k;
    dcdr >> m_r;
    dcdr >> m_p;
    dcdr >> m_binning_x;
    dcdr >> m_binning_y;
    dcdr >> m_roi;
}

/*!
 * @brief 这个函数复制成员头中的值
 * @param _header New value to be copied in member header
 */
void sensor_msgs::msg::CameraInfo::header(
        const std_msgs::msg::Header& _header)
{
    m_header = _header;
}

/*!
 * @brief 这个函数移动成员头中的值
 * @param _header New value to be moved in member header
 */
void sensor_msgs::msg::CameraInfo::header(
        std_msgs::msg::Header&& _header)
{
    m_header = std::move(_header);
}

/*!
 * @brief 此函数返回对成员头的常量引用
 * @return Constant reference to member header
 */
const std_msgs::msg::Header& sensor_msgs::msg::CameraInfo::header() const
{
    return m_header;
}

/*!
 * @brief 这个函数返回对成员头的引用
 * @return 对成员头的引用
 */
std_msgs::msg::Header& sensor_msgs::msg::CameraInfo::header()
{
    return m_header;
}
/*!
 * @brief 这个函数设置成员高度的值
 * @param _height New value for member height
 */
void sensor_msgs::msg::CameraInfo::height(
        uint32_t _height)
{
    m_height = _height;
}

/*!
 * @brief 这个函数返回成员高度的值
 * @return Value of member height
 */
uint32_t sensor_msgs::msg::CameraInfo::height() const
{
    return m_height;
}

/*!
 * @brief 这个函数返回对成员高度的引用
 * @return Reference to member height
 */
uint32_t& sensor_msgs::msg::CameraInfo::height()
{
    return m_height;
}

/*!
 * @brief 这个函数设置成员宽度的值
 * @param _width New value for member width
 */
void sensor_msgs::msg::CameraInfo::width(
        uint32_t _width)
{
    m_width = _width;
}

/*!
 * @brief 这个函数返回成员宽度的值
 * @return 成员宽度的值
 */
uint32_t sensor_msgs::msg::CameraInfo::width() const
{
    return m_width;
}

/*!
 * @brief 这个函数返回成员宽度的引用
 * @return 成员宽度的引用
 */
uint32_t& sensor_msgs::msg::CameraInfo::width()
{
    return m_width;
}

/*!
 * @brief 这个函数复制成员twisttion_model中的值
 * @param _distortion_model New value to be copied in member distortion_model
 */
void sensor_msgs::msg::CameraInfo::distortion_model(
        const std::string& _distortion_model)
{
    m_distortion_model = _distortion_model;
}

/*!
 * @brief 这个函数移动成员twisttion_model中的值
 * @param _distortion_model New value to be moved in member distortion_model
 */
void sensor_msgs::msg::CameraInfo::distortion_model(
        std::string&& _distortion_model)
{
    m_distortion_model = std::move(_distortion_model);
}

/*!
 * @brief 这个函数返回一个对成员畸变模型 distortion_model 的常量引用
 * @return Constant reference to member distortion_model
 */
const std::string& sensor_msgs::msg::CameraInfo::distortion_model() const
{
    return m_distortion_model;
}

/*!
 * @brief 这个函数返回对成员twisttion_model的引用
 * @return Reference to member distortion_model
 */
std::string& sensor_msgs::msg::CameraInfo::distortion_model()
{
    return m_distortion_model;
}

/*!
 * @brief 这个函数复制成员D中的值
 * @param _D New value to be copied in member D
 */
void sensor_msgs::msg::CameraInfo::D(
        const std::vector<double>& _D)
{
    m_d = _D;
}

/*!
 * @brief 这个函数移动成员D中的值
 * @param _D New value to be moved in member D
 */
void sensor_msgs::msg::CameraInfo::D(
        std::vector<double>&& _D)
{
    m_d = std::move(_D);
}

/*!
 * @brief 这个函数返回一个对成员D的常量引用
 * @return Constant reference to member D
 */
const std::vector<double>& sensor_msgs::msg::CameraInfo::D() const
{
    return m_d;
}

/*!
 * @brief 这个函数返回对成员D的引用
 * @return Reference to member D
 */
std::vector<double>& sensor_msgs::msg::CameraInfo::D()
{
    return m_d;
}

/*!
 * @brief 这个函数复制成员k中的值
 * @param _k New value to be copied in member k
 */
void sensor_msgs::msg::CameraInfo::k(
        const std::array<double, 9>& _k)
{
    m_k = _k;
}

/*!
 * @brief 这个函数移动成员k中的值
 * @param _k New value to be moved in member k
 */
void sensor_msgs::msg::CameraInfo::k(
        std::array<double, 9>&& _k)
{
    m_k = std::move(_k);
}

/*!
 * @brief 这个函数返回对成员k的常量引用
 * @return Constant reference to member k
 */
const std::array<double, 9>& sensor_msgs::msg::CameraInfo::k() const
{
    return m_k;
}

/*!
 * @brief 这个函数返回对成员k的引用
 * @return Reference to member k
 */
std::array<double, 9>& sensor_msgs::msg::CameraInfo::k()
{
    return m_k;
}
/*!
 * @brief 这个函数复制成员r中的值
 * @param _r New value to be copied in member r
 */
void sensor_msgs::msg::CameraInfo::r(
        const std::array<double, 9>& _r)
{
    m_r = _r;
}

/*!
 * @brief 这个函数移动成员r中的值
 * @param _r New value to be moved in member r
 */
void sensor_msgs::msg::CameraInfo::r(
        std::array<double, 9>&& _r)
{
    m_r = std::move(_r);
}

/*!
 * @brief 这个函数返回一个对成员r的常量引用
 * @return Constant reference to member r
 */
const std::array<double, 9>& sensor_msgs::msg::CameraInfo::r() const
{
    return m_r;
}

/*!
 * @brief 这个函数返回对成员r的引用
 * @return Reference to member r
 */
std::array<double, 9>& sensor_msgs::msg::CameraInfo::r()
{
    return m_r;
}

/*!
 * @brief 这个函数复制成员p中的值
 * @param _p New value to be copied in member p
 */
void sensor_msgs::msg::CameraInfo::p(
        const std::array<double, 12>& _p)
{
    m_p = _p;
}

/*!
 * @brief 这个函数移动成员p中的值
 * @param _p New value to be moved in member p
 */
void sensor_msgs::msg::CameraInfo::p(
        std::array<double, 12>&& _p)
{
    m_p = std::move(_p);
}

/*!
 * @brief 这个函数返回一个对成员p的常量引用
 * @return Constant reference to member p
 */
const std::array<double, 12>& sensor_msgs::msg::CameraInfo::p() const
{
    return m_p;
}

/*!
 * @brief 这个函数返回对成员p的引用
 * @return Reference to member p
 */
std::array<double, 12>& sensor_msgs::msg::CameraInfo::p()
{
    return m_p;
}

/*!
 * @brief 这个函数在成员binning_x中设置一个值
 * @param _binning_x New value for member binning_x
 */
void sensor_msgs::msg::CameraInfo::binning_x(
        uint32_t _binning_x)
{
    m_binning_x = _binning_x;
}

/*!
 * @brief 这个函数返回成员binning_x的值
 * @return Value of member binning_x
 */
uint32_t sensor_msgs::msg::CameraInfo::binning_x() const
{
    return m_binning_x;
}

/*!
 * @brief 这个函数返回对成员binning_x的引用
 * @return Reference to member binning_x
 */
uint32_t& sensor_msgs::msg::CameraInfo::binning_x()
{
    return m_binning_x;
}

/*!
 * @brief 该函数设置成员binning_y中的值
 * @param _binning_y New value for member binning_y
 */
void sensor_msgs::msg::CameraInfo::binning_y(
        uint32_t _binning_y)
{
    m_binning_y = _binning_y;
}

/*!
 * @brief 这个函数返回成员binning_y的值
 * @return Value of member binning_y
 */
uint32_t sensor_msgs::msg::CameraInfo::binning_y() const
{
    return m_binning_y;
}

/*!
 * @brief 这个函数返回对成员binning_y的引用
 * @return Reference to member binning_y
 */
uint32_t& sensor_msgs::msg::CameraInfo::binning_y()
{
    return m_binning_y;
}

/*!
 * @brief 这个函数复制成员roi中的值
 * @param _roi New value to be copied in member roi
 */
void sensor_msgs::msg::CameraInfo::roi(
        const sensor_msgs::msg::RegionOfInterest& _roi)
{
    m_roi = _roi;
}

/*!
 * @brief 这个函数移动成员roi中的值
 * @param _roi New value to be moved in member roi
 */
void sensor_msgs::msg::CameraInfo::roi(
        sensor_msgs::msg::RegionOfInterest&& _roi)
{
    m_roi = std::move(_roi);
}

/*!
 * @brief 这个函数返回一个对成员roi的常量引用
 * @return Constant reference to member roi
 */
const sensor_msgs::msg::RegionOfInterest& sensor_msgs::msg::CameraInfo::roi() const
{
    return m_roi;
}

/*!
 * @brief 这个函数返回对成员roi的引用
 * @return Reference to member roi
 */
sensor_msgs::msg::RegionOfInterest& sensor_msgs::msg::CameraInfo::roi()
{
    return m_roi;
}

size_t sensor_msgs::msg::CameraInfo::getKeyMaxCdrSerializedSize(
        size_t current_alignment)
{
    static_cast<void>(current_alignment);
    return sensor_msgs_msg_CameraInfo_max_key_cdr_typesize;
}

bool sensor_msgs::msg::CameraInfo::isKeyDefined()
{
    return false;
}

void sensor_msgs::msg::CameraInfo::serializeKey(
        eprosima::fastcdr::Cdr& scdr) const
{
    (void) scdr;
}
