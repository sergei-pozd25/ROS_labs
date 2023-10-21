#include "ros/ros.h"
#include "std_msgs/Float32.h"

void chatterCallback(const std_msgs::Float32::ConstPtr& message)
{
    ROS_INFO("I heard: [%0.2f]", message->data);
    if (fmod(message->data, 2)==0.00)
    {
        ROS_INFO_STREAM("even");
    }
    else
    {
        ROS_INFO_STREAM("odd");
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "det_subscriber_node");
    ros::NodeHandle nh;

    ros::Subscriber det_sub = nh.subscribe("det_topic", 16, chatterCallback);

    ros::spin();

    return 0;
}
