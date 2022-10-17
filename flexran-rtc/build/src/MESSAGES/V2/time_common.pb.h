// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: time_common.proto

#ifndef PROTOBUF_time_5fcommon_2eproto__INCLUDED
#define PROTOBUF_time_5fcommon_2eproto__INCLUDED

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
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
namespace protocol {
class flex_dl_info;
class flex_dl_infoDefaultTypeInternal;
extern flex_dl_infoDefaultTypeInternal _flex_dl_info_default_instance_;
class flex_ul_info;
class flex_ul_infoDefaultTypeInternal;
extern flex_ul_infoDefaultTypeInternal _flex_ul_info_default_instance_;
}  // namespace protocol

namespace protocol {

namespace protobuf_time_5fcommon_2eproto {
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
}  // namespace protobuf_time_5fcommon_2eproto

enum flex_harq_status {
  FLHS_ACK = 0,
  FLHS_NACK = 1,
  FLHS_DTX = 2
};
bool flex_harq_status_IsValid(int value);
const flex_harq_status flex_harq_status_MIN = FLHS_ACK;
const flex_harq_status flex_harq_status_MAX = FLHS_DTX;
const int flex_harq_status_ARRAYSIZE = flex_harq_status_MAX + 1;

const ::google::protobuf::EnumDescriptor* flex_harq_status_descriptor();
inline const ::std::string& flex_harq_status_Name(flex_harq_status value) {
  return ::google::protobuf::internal::NameOfEnum(
    flex_harq_status_descriptor(), value);
}
inline bool flex_harq_status_Parse(
    const ::std::string& name, flex_harq_status* value) {
  return ::google::protobuf::internal::ParseNamedEnum<flex_harq_status>(
    flex_harq_status_descriptor(), name, value);
}
enum flex_reception_status {
  FLRS_OK = 0,
  FLRS_NOT_OK = 1,
  FLRS_NOT_VALID = 2
};
bool flex_reception_status_IsValid(int value);
const flex_reception_status flex_reception_status_MIN = FLRS_OK;
const flex_reception_status flex_reception_status_MAX = FLRS_NOT_VALID;
const int flex_reception_status_ARRAYSIZE = flex_reception_status_MAX + 1;

const ::google::protobuf::EnumDescriptor* flex_reception_status_descriptor();
inline const ::std::string& flex_reception_status_Name(flex_reception_status value) {
  return ::google::protobuf::internal::NameOfEnum(
    flex_reception_status_descriptor(), value);
}
inline bool flex_reception_status_Parse(
    const ::std::string& name, flex_reception_status* value) {
  return ::google::protobuf::internal::ParseNamedEnum<flex_reception_status>(
    flex_reception_status_descriptor(), name, value);
}
// ===================================================================

class flex_dl_info : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:protocol.flex_dl_info) */ {
 public:
  flex_dl_info();
  virtual ~flex_dl_info();

  flex_dl_info(const flex_dl_info& from);

  inline flex_dl_info& operator=(const flex_dl_info& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const flex_dl_info& default_instance();

  static inline const flex_dl_info* internal_default_instance() {
    return reinterpret_cast<const flex_dl_info*>(
               &_flex_dl_info_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(flex_dl_info* other);

  // implements Message ----------------------------------------------

  inline flex_dl_info* New() const PROTOBUF_FINAL { return New(NULL); }

  flex_dl_info* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const flex_dl_info& from);
  void MergeFrom(const flex_dl_info& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(flex_dl_info* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated uint32 harq_status = 3;
  int harq_status_size() const;
  void clear_harq_status();
  static const int kHarqStatusFieldNumber = 3;
  ::google::protobuf::uint32 harq_status(int index) const;
  void set_harq_status(int index, ::google::protobuf::uint32 value);
  void add_harq_status(::google::protobuf::uint32 value);
  const ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >&
      harq_status() const;
  ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >*
      mutable_harq_status();

  // optional uint32 rnti = 1;
  bool has_rnti() const;
  void clear_rnti();
  static const int kRntiFieldNumber = 1;
  ::google::protobuf::uint32 rnti() const;
  void set_rnti(::google::protobuf::uint32 value);

  // optional uint32 harq_process_id = 2;
  bool has_harq_process_id() const;
  void clear_harq_process_id();
  static const int kHarqProcessIdFieldNumber = 2;
  ::google::protobuf::uint32 harq_process_id() const;
  void set_harq_process_id(::google::protobuf::uint32 value);

  // optional uint32 serv_cell_index = 4;
  bool has_serv_cell_index() const;
  void clear_serv_cell_index();
  static const int kServCellIndexFieldNumber = 4;
  ::google::protobuf::uint32 serv_cell_index() const;
  void set_serv_cell_index(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:protocol.flex_dl_info)
 private:
  void set_has_rnti();
  void clear_has_rnti();
  void set_has_harq_process_id();
  void clear_has_harq_process_id();
  void set_has_serv_cell_index();
  void clear_has_serv_cell_index();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedField< ::google::protobuf::uint32 > harq_status_;
  ::google::protobuf::uint32 rnti_;
  ::google::protobuf::uint32 harq_process_id_;
  ::google::protobuf::uint32 serv_cell_index_;
  friend struct protobuf_time_5fcommon_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class flex_ul_info : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:protocol.flex_ul_info) */ {
 public:
  flex_ul_info();
  virtual ~flex_ul_info();

  flex_ul_info(const flex_ul_info& from);

  inline flex_ul_info& operator=(const flex_ul_info& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const flex_ul_info& default_instance();

  static inline const flex_ul_info* internal_default_instance() {
    return reinterpret_cast<const flex_ul_info*>(
               &_flex_ul_info_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(flex_ul_info* other);

  // implements Message ----------------------------------------------

  inline flex_ul_info* New() const PROTOBUF_FINAL { return New(NULL); }

  flex_ul_info* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CopyFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void MergeFrom(const ::google::protobuf::Message& from) PROTOBUF_FINAL;
  void CopyFrom(const flex_ul_info& from);
  void MergeFrom(const flex_ul_info& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const PROTOBUF_FINAL;
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const PROTOBUF_FINAL;
  void InternalSwap(flex_ul_info* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated uint32 ul_reception = 2;
  int ul_reception_size() const;
  void clear_ul_reception();
  static const int kUlReceptionFieldNumber = 2;
  ::google::protobuf::uint32 ul_reception(int index) const;
  void set_ul_reception(int index, ::google::protobuf::uint32 value);
  void add_ul_reception(::google::protobuf::uint32 value);
  const ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >&
      ul_reception() const;
  ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >*
      mutable_ul_reception();

  // optional uint32 rnti = 1;
  bool has_rnti() const;
  void clear_rnti();
  static const int kRntiFieldNumber = 1;
  ::google::protobuf::uint32 rnti() const;
  void set_rnti(::google::protobuf::uint32 value);

  // optional uint32 reception_status = 3;
  bool has_reception_status() const;
  void clear_reception_status();
  static const int kReceptionStatusFieldNumber = 3;
  ::google::protobuf::uint32 reception_status() const;
  void set_reception_status(::google::protobuf::uint32 value);

  // optional uint32 tpc = 4;
  bool has_tpc() const;
  void clear_tpc();
  static const int kTpcFieldNumber = 4;
  ::google::protobuf::uint32 tpc() const;
  void set_tpc(::google::protobuf::uint32 value);

  // optional uint32 serv_cell_index = 5;
  bool has_serv_cell_index() const;
  void clear_serv_cell_index();
  static const int kServCellIndexFieldNumber = 5;
  ::google::protobuf::uint32 serv_cell_index() const;
  void set_serv_cell_index(::google::protobuf::uint32 value);

  // optional uint32 rssi = 6;
  bool has_rssi() const;
  void clear_rssi();
  static const int kRssiFieldNumber = 6;
  ::google::protobuf::uint32 rssi() const;
  void set_rssi(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:protocol.flex_ul_info)
 private:
  void set_has_rnti();
  void clear_has_rnti();
  void set_has_reception_status();
  void clear_has_reception_status();
  void set_has_tpc();
  void clear_has_tpc();
  void set_has_serv_cell_index();
  void clear_has_serv_cell_index();
  void set_has_rssi();
  void clear_has_rssi();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable int _cached_size_;
  ::google::protobuf::RepeatedField< ::google::protobuf::uint32 > ul_reception_;
  ::google::protobuf::uint32 rnti_;
  ::google::protobuf::uint32 reception_status_;
  ::google::protobuf::uint32 tpc_;
  ::google::protobuf::uint32 serv_cell_index_;
  ::google::protobuf::uint32 rssi_;
  friend struct protobuf_time_5fcommon_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// flex_dl_info

// optional uint32 rnti = 1;
inline bool flex_dl_info::has_rnti() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void flex_dl_info::set_has_rnti() {
  _has_bits_[0] |= 0x00000001u;
}
inline void flex_dl_info::clear_has_rnti() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void flex_dl_info::clear_rnti() {
  rnti_ = 0u;
  clear_has_rnti();
}
inline ::google::protobuf::uint32 flex_dl_info::rnti() const {
  // @@protoc_insertion_point(field_get:protocol.flex_dl_info.rnti)
  return rnti_;
}
inline void flex_dl_info::set_rnti(::google::protobuf::uint32 value) {
  set_has_rnti();
  rnti_ = value;
  // @@protoc_insertion_point(field_set:protocol.flex_dl_info.rnti)
}

// optional uint32 harq_process_id = 2;
inline bool flex_dl_info::has_harq_process_id() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void flex_dl_info::set_has_harq_process_id() {
  _has_bits_[0] |= 0x00000002u;
}
inline void flex_dl_info::clear_has_harq_process_id() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void flex_dl_info::clear_harq_process_id() {
  harq_process_id_ = 0u;
  clear_has_harq_process_id();
}
inline ::google::protobuf::uint32 flex_dl_info::harq_process_id() const {
  // @@protoc_insertion_point(field_get:protocol.flex_dl_info.harq_process_id)
  return harq_process_id_;
}
inline void flex_dl_info::set_harq_process_id(::google::protobuf::uint32 value) {
  set_has_harq_process_id();
  harq_process_id_ = value;
  // @@protoc_insertion_point(field_set:protocol.flex_dl_info.harq_process_id)
}

// repeated uint32 harq_status = 3;
inline int flex_dl_info::harq_status_size() const {
  return harq_status_.size();
}
inline void flex_dl_info::clear_harq_status() {
  harq_status_.Clear();
}
inline ::google::protobuf::uint32 flex_dl_info::harq_status(int index) const {
  // @@protoc_insertion_point(field_get:protocol.flex_dl_info.harq_status)
  return harq_status_.Get(index);
}
inline void flex_dl_info::set_harq_status(int index, ::google::protobuf::uint32 value) {
  harq_status_.Set(index, value);
  // @@protoc_insertion_point(field_set:protocol.flex_dl_info.harq_status)
}
inline void flex_dl_info::add_harq_status(::google::protobuf::uint32 value) {
  harq_status_.Add(value);
  // @@protoc_insertion_point(field_add:protocol.flex_dl_info.harq_status)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >&
flex_dl_info::harq_status() const {
  // @@protoc_insertion_point(field_list:protocol.flex_dl_info.harq_status)
  return harq_status_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >*
flex_dl_info::mutable_harq_status() {
  // @@protoc_insertion_point(field_mutable_list:protocol.flex_dl_info.harq_status)
  return &harq_status_;
}

// optional uint32 serv_cell_index = 4;
inline bool flex_dl_info::has_serv_cell_index() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void flex_dl_info::set_has_serv_cell_index() {
  _has_bits_[0] |= 0x00000004u;
}
inline void flex_dl_info::clear_has_serv_cell_index() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void flex_dl_info::clear_serv_cell_index() {
  serv_cell_index_ = 0u;
  clear_has_serv_cell_index();
}
inline ::google::protobuf::uint32 flex_dl_info::serv_cell_index() const {
  // @@protoc_insertion_point(field_get:protocol.flex_dl_info.serv_cell_index)
  return serv_cell_index_;
}
inline void flex_dl_info::set_serv_cell_index(::google::protobuf::uint32 value) {
  set_has_serv_cell_index();
  serv_cell_index_ = value;
  // @@protoc_insertion_point(field_set:protocol.flex_dl_info.serv_cell_index)
}

// -------------------------------------------------------------------

// flex_ul_info

// optional uint32 rnti = 1;
inline bool flex_ul_info::has_rnti() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void flex_ul_info::set_has_rnti() {
  _has_bits_[0] |= 0x00000001u;
}
inline void flex_ul_info::clear_has_rnti() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void flex_ul_info::clear_rnti() {
  rnti_ = 0u;
  clear_has_rnti();
}
inline ::google::protobuf::uint32 flex_ul_info::rnti() const {
  // @@protoc_insertion_point(field_get:protocol.flex_ul_info.rnti)
  return rnti_;
}
inline void flex_ul_info::set_rnti(::google::protobuf::uint32 value) {
  set_has_rnti();
  rnti_ = value;
  // @@protoc_insertion_point(field_set:protocol.flex_ul_info.rnti)
}

// repeated uint32 ul_reception = 2;
inline int flex_ul_info::ul_reception_size() const {
  return ul_reception_.size();
}
inline void flex_ul_info::clear_ul_reception() {
  ul_reception_.Clear();
}
inline ::google::protobuf::uint32 flex_ul_info::ul_reception(int index) const {
  // @@protoc_insertion_point(field_get:protocol.flex_ul_info.ul_reception)
  return ul_reception_.Get(index);
}
inline void flex_ul_info::set_ul_reception(int index, ::google::protobuf::uint32 value) {
  ul_reception_.Set(index, value);
  // @@protoc_insertion_point(field_set:protocol.flex_ul_info.ul_reception)
}
inline void flex_ul_info::add_ul_reception(::google::protobuf::uint32 value) {
  ul_reception_.Add(value);
  // @@protoc_insertion_point(field_add:protocol.flex_ul_info.ul_reception)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >&
flex_ul_info::ul_reception() const {
  // @@protoc_insertion_point(field_list:protocol.flex_ul_info.ul_reception)
  return ul_reception_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >*
flex_ul_info::mutable_ul_reception() {
  // @@protoc_insertion_point(field_mutable_list:protocol.flex_ul_info.ul_reception)
  return &ul_reception_;
}

// optional uint32 reception_status = 3;
inline bool flex_ul_info::has_reception_status() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void flex_ul_info::set_has_reception_status() {
  _has_bits_[0] |= 0x00000002u;
}
inline void flex_ul_info::clear_has_reception_status() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void flex_ul_info::clear_reception_status() {
  reception_status_ = 0u;
  clear_has_reception_status();
}
inline ::google::protobuf::uint32 flex_ul_info::reception_status() const {
  // @@protoc_insertion_point(field_get:protocol.flex_ul_info.reception_status)
  return reception_status_;
}
inline void flex_ul_info::set_reception_status(::google::protobuf::uint32 value) {
  set_has_reception_status();
  reception_status_ = value;
  // @@protoc_insertion_point(field_set:protocol.flex_ul_info.reception_status)
}

// optional uint32 tpc = 4;
inline bool flex_ul_info::has_tpc() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void flex_ul_info::set_has_tpc() {
  _has_bits_[0] |= 0x00000004u;
}
inline void flex_ul_info::clear_has_tpc() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void flex_ul_info::clear_tpc() {
  tpc_ = 0u;
  clear_has_tpc();
}
inline ::google::protobuf::uint32 flex_ul_info::tpc() const {
  // @@protoc_insertion_point(field_get:protocol.flex_ul_info.tpc)
  return tpc_;
}
inline void flex_ul_info::set_tpc(::google::protobuf::uint32 value) {
  set_has_tpc();
  tpc_ = value;
  // @@protoc_insertion_point(field_set:protocol.flex_ul_info.tpc)
}

// optional uint32 serv_cell_index = 5;
inline bool flex_ul_info::has_serv_cell_index() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void flex_ul_info::set_has_serv_cell_index() {
  _has_bits_[0] |= 0x00000008u;
}
inline void flex_ul_info::clear_has_serv_cell_index() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void flex_ul_info::clear_serv_cell_index() {
  serv_cell_index_ = 0u;
  clear_has_serv_cell_index();
}
inline ::google::protobuf::uint32 flex_ul_info::serv_cell_index() const {
  // @@protoc_insertion_point(field_get:protocol.flex_ul_info.serv_cell_index)
  return serv_cell_index_;
}
inline void flex_ul_info::set_serv_cell_index(::google::protobuf::uint32 value) {
  set_has_serv_cell_index();
  serv_cell_index_ = value;
  // @@protoc_insertion_point(field_set:protocol.flex_ul_info.serv_cell_index)
}

// optional uint32 rssi = 6;
inline bool flex_ul_info::has_rssi() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void flex_ul_info::set_has_rssi() {
  _has_bits_[0] |= 0x00000010u;
}
inline void flex_ul_info::clear_has_rssi() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void flex_ul_info::clear_rssi() {
  rssi_ = 0u;
  clear_has_rssi();
}
inline ::google::protobuf::uint32 flex_ul_info::rssi() const {
  // @@protoc_insertion_point(field_get:protocol.flex_ul_info.rssi)
  return rssi_;
}
inline void flex_ul_info::set_rssi(::google::protobuf::uint32 value) {
  set_has_rssi();
  rssi_ = value;
  // @@protoc_insertion_point(field_set:protocol.flex_ul_info.rssi)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


}  // namespace protocol

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::protocol::flex_harq_status> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::protocol::flex_harq_status>() {
  return ::protocol::flex_harq_status_descriptor();
}
template <> struct is_proto_enum< ::protocol::flex_reception_status> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::protocol::flex_reception_status>() {
  return ::protocol::flex_reception_status_descriptor();
}

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_time_5fcommon_2eproto__INCLUDED