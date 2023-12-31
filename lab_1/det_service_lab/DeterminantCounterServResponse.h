// Generated by gencpp from file det_service_lab/DeterminantCounterServResponse.msg
// DO NOT EDIT!


#ifndef DET_SERVICE_LAB_MESSAGE_DETERMINANTCOUNTERSERVRESPONSE_H
#define DET_SERVICE_LAB_MESSAGE_DETERMINANTCOUNTERSERVRESPONSE_H


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
struct DeterminantCounterServResponse_
{
  typedef DeterminantCounterServResponse_<ContainerAllocator> Type;

  DeterminantCounterServResponse_()
    : det(0.0)  {
    }
  DeterminantCounterServResponse_(const ContainerAllocator& _alloc)
    : det(0.0)  {
  (void)_alloc;
    }



   typedef float _det_type;
  _det_type det;





  typedef boost::shared_ptr< ::det_service_lab::DeterminantCounterServResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::det_service_lab::DeterminantCounterServResponse_<ContainerAllocator> const> ConstPtr;

}; // struct DeterminantCounterServResponse_

typedef ::det_service_lab::DeterminantCounterServResponse_<std::allocator<void> > DeterminantCounterServResponse;

typedef boost::shared_ptr< ::det_service_lab::DeterminantCounterServResponse > DeterminantCounterServResponsePtr;
typedef boost::shared_ptr< ::det_service_lab::DeterminantCounterServResponse const> DeterminantCounterServResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::det_service_lab::DeterminantCounterServResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::det_service_lab::DeterminantCounterServResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::det_service_lab::DeterminantCounterServResponse_<ContainerAllocator1> & lhs, const ::det_service_lab::DeterminantCounterServResponse_<ContainerAllocator2> & rhs)
{
  return lhs.det == rhs.det;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::det_service_lab::DeterminantCounterServResponse_<ContainerAllocator1> & lhs, const ::det_service_lab::DeterminantCounterServResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace det_service_lab

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::det_service_lab::DeterminantCounterServResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::det_service_lab::DeterminantCounterServResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::det_service_lab::DeterminantCounterServResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::det_service_lab::DeterminantCounterServResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::det_service_lab::DeterminantCounterServResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::det_service_lab::DeterminantCounterServResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::det_service_lab::DeterminantCounterServResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6bb9c80a49044a815006ce46b540ce50";
  }

  static const char* value(const ::det_service_lab::DeterminantCounterServResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6bb9c80a49044a81ULL;
  static const uint64_t static_value2 = 0x5006ce46b540ce50ULL;
};

template<class ContainerAllocator>
struct DataType< ::det_service_lab::DeterminantCounterServResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "det_service_lab/DeterminantCounterServResponse";
  }

  static const char* value(const ::det_service_lab::DeterminantCounterServResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::det_service_lab::DeterminantCounterServResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 det\n"
"\n"
;
  }

  static const char* value(const ::det_service_lab::DeterminantCounterServResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::det_service_lab::DeterminantCounterServResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.det);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct DeterminantCounterServResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::det_service_lab::DeterminantCounterServResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::det_service_lab::DeterminantCounterServResponse_<ContainerAllocator>& v)
  {
    s << indent << "det: ";
    Printer<float>::stream(s, indent + "  ", v.det);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DET_SERVICE_LAB_MESSAGE_DETERMINANTCOUNTERSERVRESPONSE_H
