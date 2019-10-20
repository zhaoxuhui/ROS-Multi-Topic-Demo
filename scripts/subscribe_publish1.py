# coding=utf-8
import rospy
from std_msgs.msg import String
from std_msgs.msg import Float32


def callback1(flt):
    pub_flt = flt.data+0.4
    pub1.publish(pub_flt)

    print "receive flt:", flt.data
    print "publish flt:", pub_flt


def callback2(str):
    str_msg = str.data+" hahaha"
    pub2.publish(str_msg)

    print "receive str:", str.data
    print "publish str:", str_msg


if __name__ == "__main__":
    # 注意这里其实并没有在函数外面声明变量，但在回调函数中也直接调用了main函数中初始化的pub
    # 这时Python与C++不同点之一，需要注意
    rospy.init_node("subscribe_publish1")

    sub1 = rospy.Subscriber("topic_flt", Float32, callback1)
    sub2 = rospy.Subscriber("topic_str", String, callback2)

    pub1 = rospy.Publisher("processed_flt", Float32, queue_size=1)
    pub2 = rospy.Publisher("processed_str", String, queue_size=1)

    rospy.spin()
