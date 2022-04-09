#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>


class CustomRobotController
{
    public:
        CustomRobotController();

    private:
        void processLaserScan(const sensor_msgs::LaserScan &lidar_scan_msg);
        ros::NodeHandle nh;
        std::string scan_topic, twist_topic;
        ros::Subscriber scan_sub;
        ros::Publisher twist_pub;

};

CustomRobotController::CustomRobotController():
    scan_topic("static_laser"), //"static_laser" uses the complete lidar scan, "simple_lidar" uses a simplified version
    twist_topic("cmd_vel")
{
    scan_sub = nh.subscribe(scan_topic, 1, &CustomRobotController::processLaserScan, this);
    twist_pub = nh.advertise<geometry_msgs::Twist>(twist_topic, 1);
}

void CustomRobotController::processLaserScan(const sensor_msgs::LaserScan &lidar_scan_msg)
{

    geometry_msgs::Twist twist_msg;

    /**
        Write your code here

        The values from the LiDAR are in lidar_scan_msg.ranges
        For more information on the data contained in a LaserScan message, consult http://docs.ros.org/en/api/sensor_msgs/html/msg/LaserScan.html

        The following are used to set the linear and angular velocities of the robot
        twist.linear.x = 0;
        twist.angular.z = 0;
     */

    twist_pub.publish(twist_msg);

}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "custom_robot_controller");
  CustomRobotController robot_controller;

  ros::spin();
  
  return(0);
}
