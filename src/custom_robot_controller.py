import rospy
from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist

class csvExporterNode():


    def process_LaserScan(self,data):

        twist_msg = Twist()

        #########################################
        #
        # Write your code here
        #
        # The values from the LiDAR are in data.ranges
        # For more information on the data contained in a LaserScan message, consult http://docs.ros.org/en/api/sensor_msgs/html/msg/LaserScan.html
        #
        # The following are used to set the linear and angular velocities of the robot
        # twist_msg.linear.x = 0;
        # twist_msg.angular.z = 0;
        ########################################

        self.twist_pub.publish(twist_msg)
        


    def __init__(self):

        rospy.init_node('custom_robot_controller', anonymous=True)

        self.scan_topic = "/simple_lidar"   # uncomment only one of these lines at a time, depending on which LiDAR you wish to use
        #self.scan_topic = "/static_laser"   # "/static_laser" uses the complete LiDAR scan, "/simple_lidar" uses a simplified version

        self.twist_topic = "/cmd_vel"

        rospy.Subscriber(
                self.scan_topic,
                LaserScan,
                self.process_LaserScan,
                buff_size=10000000,
                queue_size=1)

        self.twist_pub = rospy.Publisher(self.twist_topic, Twist, queue_size=1)




if __name__ == '__main__':
    try:
        csvExpNode = csvExporterNode()
        
        rospy.spin()        

    except rospy.ROSInterruptException:
        pass