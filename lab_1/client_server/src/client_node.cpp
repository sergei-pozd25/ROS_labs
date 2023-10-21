#include "ros/ros.h"
#include "det_service_lab/DeterminantCounterServ.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "client_node");
  if (argc != 3)
  {
    ROS_INFO("usage: add_two_ints_client X Y");
    return 1;
  }

  ros::NodeHandle nh;
  ros::ServiceClient client = nh.serviceClient<det_service_lab::DeterminantCounterServ>("determinant_counter_s");
  det_service_lab::DeterminantCounterServ srv;
  srv.request.a11 = atoll(argv[1]);
  srv.request.a12 = atoll(argv[2]);
  srv.request.a13 = atoll(argv[3]);
  srv.request.a21 = atoll(argv[4]);
  srv.request.a22 = atoll(argv[5]);
  srv.request.a23 = atoll(argv[6]);
  srv.request.a31 = atoll(argv[7]);
  srv.request.a32 = atoll(argv[8]);
  srv.request.a33 = atoll(argv[9]);
  if (client.call(srv))
  {
    ROS_INFO("Sum: %f", srv.response.det);
  }
  else
  {
    ROS_ERROR("Failed to call service determinant_counter_s");
    return 1;
  }

  return 0;
}
