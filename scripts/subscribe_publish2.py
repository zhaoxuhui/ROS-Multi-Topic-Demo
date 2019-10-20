# coding=utf-8
import rospy
from std_msgs.msg import String
from std_msgs.msg import Float32

# 注意在Python的类中，是通过self来表示某个变量是其成员的
# 如果不通过self方式获取，Python就会认为这个变量是全局变量
class Processer:
    def __init__(self):
        self.sub1 = rospy.Subscriber("topic_flt", Float32, self.callback1)
        self.sub2 = rospy.Subscriber("topic_str", String, self.callback2)

        self.pub1 = rospy.Publisher("processed_flt", Float32, queue_size=1)
        self.pub2 = rospy.Publisher("processed_str", String, queue_size=1)

    def callback1(self, flt):
        pub_flt = flt.data+0.4
        self.pub1.publish(pub_flt)

        print "receive flt:", flt.data
        print "publish flt:", pub_flt

    def callback2(self, str):
        str_msg = str.data+" hahaha"
        self.pub2.publish(str_msg)

        print "receive str:", str.data
        print "publish str:", str_msg


if __name__ == "__main__":
    rospy.init_node("subscribe_publish1")

    p = Processer()

    rospy.spin()
