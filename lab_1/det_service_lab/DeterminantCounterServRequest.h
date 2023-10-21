// Generated by gencpp from file det_service_lab/DeterminantCounterServRequest.msg
// DO NOT EDIT!


#ifndef DET_SERVICE_LAB_MESSAGE_DETERMINANTCOUNTERSERVREQUEST_H
#define DET_SERVICE_LAB_MESSAGE_DETERMINANTCOUNTERSERVREQUEST_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace det_service_lab
{
template <class ContainerAllocator>
struct DeterminantCounterServRequest_
{
  typedef DeterminantCounterServRequest_<ContainerAllocator> Type;

  DeterminantCounterServRequest_()
    : a11(0.0)
    , a12(0.0)
    , a13(0.0)
    , a21(0.0)
    , a22(0.0)
    , a23(0.0)
    , a31(0.0)
    , a32(0.0)
    , a33(0.0)  {
    }
  DeterminantCounterServRequest_(const ContainerAllocator& _alloc)
    : a11(0.0)
    , a12(0.0)
    , a13(0.0)
    , a21(0.0)
    , a22(0.0)
    , a23(0.0)
    , a31(0.0)
    , a32(0.0)
    , a33(0.0)  {
  (void)_alloc;
    }



   typedef float _a11_type;
  _a11_type a11;

   typedef float _a12_type;
  _a12_type a12;

   typedef float _a13_type;
  _a13_type a13;

   typedef float _a21_type;
  _a21_type a21;

   typedef float _a22_type;
  _a22_type a22;

   typedef float _a23_type;
  _a23_type a23;

   typedef float _a31_type;
  _a31_type a31;

   typedef float _a32_type;
  _a32_type a32;

   typedef float _a33_type;
  _a33_type a33;





  typedef boost::shared_ptr< ::det_service_lab::DeterminantCounterServRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::det_service_lab::DeterminantCounterServRequest_<ContainerAllocator> const> ConstPtr;

}; // struct DeterminantCounterServRequest_

typedef ::det_service_lab::DeterminantCounterServRequest_<std::allocator<void> > DeterminantCounterServRequest;

typedef boost::shared_ptr< ::det_service_lab::DeterminantCounterServRequest > DeterminantCounterServRequestPtr;
typedef boost::shared_ptr< ::det_service_lab::DeterminantCounterServRequest const> DeterminantCounterServRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::det_service_lab::DeterminantCounterServRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::det_service_lab::DeterminantCounterServRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::det_service_lab::DeterminantCounterServRequest_<ContainerAllocator1> & lhs, const ::det_service_lab::DeterminantCounterServRequest_<ContainerAllocator2> & rhs)
{
  return lhs.a11 == rhs.a11 &&
    lhs.a12 == rhs.a12 &&
    lhs.a13 == rhs.a13 &&
    lhs.a21 == rhs.a21 &&
    lhs.a22 == rhs.a22 &&
    lhs.a23 == rhs.a23 &&
    lhs.a31 == rhs.a31 &&
    lhs.a32 == rhs.a32 &&
    lhs.a33 == rhs.a33;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::det_service_lab::DeterminantCounterServRequest_<ContainerAllocator1> & lhs, const ::det_service_lab::DeterminantCounterServRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace det_service_lab

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::det_service_lab::DeterminantCounterServRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::det_service_lab::DeterminantCounterServRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::det_service_lab::DeterminantCounterServRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::det_service_lab::DeterminantCounterServRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::det_service_lab::DeterminantCounterServRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::det_service_lab::DeterminantCounterServRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::det_service_lab::DeterminantCounterServRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "76bc77bacade00ac116d8d7c449a7fb9";
  }

  static const char* value(const ::det_service_lab::DeterminantCounterServRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x76bc77bacade00acULL;
  static const uint64_t static_value2 = 0x116d8d7c449a7fb9ULL;
};

template<class ContainerAllocator>
struct DataType< ::det_service_lab::DeterminantCounterServRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "det_service_lab/DeterminantCounterServRequest";
  }

  static const char* value(const ::det_service_lab::DeterminantCounterServRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::det_service_lab::DeterminantCounterServRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 a11\n"
"float32 a12\n"
"float32 a13\n"
"float32 a21\n"
"float32 a22\n"
"float32 a23\n"
"float32 a31\n"
"float32 a32\n"
"float32 a33\n"
;
  }

  static const char* value(const ::det_service_lab::DeterminantCounterServRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::det_service_lab::DeterminantCounterServRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.a11);
      stream.next(m.a12);
      stream.next(m.a13);
      stream.next(m.a21);
      stream.next(m.a22);
      stream.next(m.a23);
      stream.next(m.a31);
      stream.next(m.a32);
      stream.next(m.a33);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct DeterminantCounterServRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::det_service_lab::DeterminantCounterServRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::det_service_lab::DeterminantCounterServRequest_<ContainerAllocator>& v)
  {
    s << indent << "a11: ";
    Printer<float>::stream(s, indent + "  ", v.a11);
    s << indent << "a12: ";
    Printer<float>::stream(s, indent + "  ", v.a12);
    s << indent << "a13: ";
    Printer<float>::stream(s, indent + "  ", v.a13);
    s << indent << "a21: ";
    Printer<float>::stream(s, indent + "  ", v.a21);
    s << indent << "a22: ";
    Printer<float>::stream(s, indent + "  ", v.a22);
    s << indent << "a23: ";
    Printer<float>::stream(s, indent + "  ", v.a23);
    s << indent << "a31: ";
    Printer<float>::stream(s, indent + "  ", v.a31);
    s << indent << "a32: ";
    Printer<float>::stream(s, indent + "  ", v.a32);
    s << indent << "a33: ";
    Printer<float>::stream(s, indent + "  ", v.a33);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DET_SERVICE_LAB_MESSAGE_DETERMINANTCOUNTERSERVREQUEST_H