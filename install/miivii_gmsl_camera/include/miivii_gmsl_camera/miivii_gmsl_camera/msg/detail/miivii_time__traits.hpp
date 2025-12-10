// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from miivii_gmsl_camera:msg/MiiviiTime.idl
// generated code does not contain a copyright notice

#ifndef MIIVII_GMSL_CAMERA__MSG__DETAIL__MIIVII_TIME__TRAITS_HPP_
#define MIIVII_GMSL_CAMERA__MSG__DETAIL__MIIVII_TIME__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "miivii_gmsl_camera/msg/detail/miivii_time__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'jitter'
// Member 'latency'
#include "builtin_interfaces/msg/detail/duration__traits.hpp"

namespace miivii_gmsl_camera
{

namespace msg
{

inline void to_flow_style_yaml(
  const MiiviiTime & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: nodes
  {
    if (msg.nodes.size() == 0) {
      out << "nodes: []";
    } else {
      out << "nodes: [";
      size_t pending_items = msg.nodes.size();
      for (auto item : msg.nodes) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: jitter
  {
    if (msg.jitter.size() == 0) {
      out << "jitter: []";
    } else {
      out << "jitter: [";
      size_t pending_items = msg.jitter.size();
      for (auto item : msg.jitter) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: latency
  {
    if (msg.latency.size() == 0) {
      out << "latency: []";
    } else {
      out << "latency: [";
      size_t pending_items = msg.latency.size();
      for (auto item : msg.latency) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MiiviiTime & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: nodes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.nodes.size() == 0) {
      out << "nodes: []\n";
    } else {
      out << "nodes:\n";
      for (auto item : msg.nodes) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: jitter
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.jitter.size() == 0) {
      out << "jitter: []\n";
    } else {
      out << "jitter:\n";
      for (auto item : msg.jitter) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: latency
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.latency.size() == 0) {
      out << "latency: []\n";
    } else {
      out << "latency:\n";
      for (auto item : msg.latency) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MiiviiTime & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace miivii_gmsl_camera

namespace rosidl_generator_traits
{

[[deprecated("use miivii_gmsl_camera::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const miivii_gmsl_camera::msg::MiiviiTime & msg,
  std::ostream & out, size_t indentation = 0)
{
  miivii_gmsl_camera::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use miivii_gmsl_camera::msg::to_yaml() instead")]]
inline std::string to_yaml(const miivii_gmsl_camera::msg::MiiviiTime & msg)
{
  return miivii_gmsl_camera::msg::to_yaml(msg);
}

template<>
inline const char * data_type<miivii_gmsl_camera::msg::MiiviiTime>()
{
  return "miivii_gmsl_camera::msg::MiiviiTime";
}

template<>
inline const char * name<miivii_gmsl_camera::msg::MiiviiTime>()
{
  return "miivii_gmsl_camera/msg/MiiviiTime";
}

template<>
struct has_fixed_size<miivii_gmsl_camera::msg::MiiviiTime>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<miivii_gmsl_camera::msg::MiiviiTime>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<miivii_gmsl_camera::msg::MiiviiTime>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MIIVII_GMSL_CAMERA__MSG__DETAIL__MIIVII_TIME__TRAITS_HPP_
