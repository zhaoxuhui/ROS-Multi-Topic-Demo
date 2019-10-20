# coding=utf-8
import rospy
from std_msgs.msg import String
from std_msgs.msg import Float32
from std_msgs.msg import Float32MultiArray


if __name__ == "__main__":
    rospy.init_node("multi_publish")
    pub1 = rospy.Publisher("topic_str", String, queue_size=1)
    pub2 = rospy.Publisher("topic_flt", Float32, queue_size=1)
    pub3 = rospy.Publisher("topic_arr", Float32MultiArray, queue_size=1)

    str_msg = "this is a string from node"
    flt_msg = 2.3
    arr_msg = Float32MultiArray(data=[1.2, 6.8, 7.4])   # 注意初始化的方法

    rate = rospy.Rate(1)
    while not rospy.is_shutdown():
        pub1.publish(str_msg)
        pub2.publish(flt_msg)
        pub3.publish(arr_msg)
        print "published str:", str_msg
        print "published flt:", flt_msg
        print "published arr:", arr_msg.data
        rate.sleep()
