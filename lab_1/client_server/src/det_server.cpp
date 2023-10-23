#include "ros/ros.h"
#include "det_service_lab/DeterminantCounterServ.h"
#include "std_msgs/Float32.h"

ros::Publisher det_pub;

bool determinant(det_service_lab::DeterminantCounterServ::Request &req,
    det_service_lab::DeterminantCounterServ::Response &res)
{
    res.det = req.a11*(req.a22*req.a33-req.a23*req.a32)-req.a12*(req.a21*req.a33-req.a23*req.a31)+
            req.a13*(req.a21*req.a32-req.a22*req.a31);

    ROS_INFO_STREAM("request: " << req.a11 << req.a12 << req.a13 << req.a21 << req.a22 <<
             req.a23 << req.a31 << req.a32 << req.a33);
    ROS_INFO_STREAM("sending back response: " << res.det);

    std_msgs::Float32 message;
    message.data = res.det;
    ROS_INFO_STREAM("Published: " << message.data);

    det_pub.publish(message);

    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc,argv,"determinant_counter_server");
    ros::NodeHandle nh;
    ros::ServiceServer service=nh.advertiseService("determinant_counter_s",determinant);
    det_pub = nh.advertise<std_msgs::Float32>("det_topic", 16);

    ROS_INFO_STREAM("READY TO COUNT");
    ros::spin();
    return 0;
}
