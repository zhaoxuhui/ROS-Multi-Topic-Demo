# coding=utf-8
import rospy
from std_msgs.msg import String
from std_msgs.msg import Float32
from std_msgs.msg import Float32MultiArray


def callback1(str):
    print "received str:", str.data


def callback2(flt):
    print "received flt:", flt.data


def callback3(arr):
    print "received arr:", arr.data


if __name__ == "__main__":
    rospy.init_node("multi_subscribe")

    sub1 = rospy.Subscriber("topic_str", String, callback1)
    sub2 = rospy.Subscriber("topic_flt", Float32, callback2)
    sub3 = rospy.Subscriber("topic_arr", Float32MultiArray, callback3)

    rospy.spin()
