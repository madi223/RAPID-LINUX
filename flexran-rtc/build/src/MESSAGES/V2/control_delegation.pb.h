// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: control_delegation.proto

#ifndef PROTOBUF_control_5fdelegation_2eproto__INCLUDED
#define PROTOBUF_control_5fdelegation_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3003000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3003000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)
namespace protocol {
}  // namespace protocol

namespace protocol {

namespace protobuf_control_5fdelegation_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_control_5fdelegation_2eproto

enum flex_control_delegation_type {
  FLCDT_MAC_DL_UE_SCHEDULER = 1
};
bool flex_control_delegation_type_IsValid(int value);
const flex_control_delegation_type flex_control_delegation_type_MIN = FLCDT_MAC_DL_UE_SCHEDULER;
const flex_control_delegation_type flex_control_delegation_type_MAX = FLCDT_MAC_DL_UE_SCHEDULER;
const int flex_control_delegation_type_ARRAYSIZE = flex_control_delegation_type_MAX + 1;

const ::google::protobuf::EnumDescriptor* flex_control_delegation_type_descriptor();
inline const ::std::string& flex_control_delegation_type_Name(flex_control_delegation_type value) {
  return ::google::protobuf::internal::NameOfEnum(
    flex_control_delegation_type_descriptor(), value);
}
inline bool flex_control_delegation_type_Parse(
    const ::std::string& name, flex_control_delegation_type* value) {
  return ::google::protobuf::internal::ParseNamedEnum<flex_control_delegation_type>(
    flex_control_delegation_type_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)


}  // namespace protocol

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::protocol::flex_control_delegation_type> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::protocol::flex_control_delegation_type>() {
  return ::protocol::flex_control_delegation_type_descriptor();
}

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_control_5fdelegation_2eproto__INCLUDED
