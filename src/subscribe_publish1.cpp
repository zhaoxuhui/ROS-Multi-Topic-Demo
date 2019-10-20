# include<ros/ros.h>
# include<std_msgs/String.h>
# include<std_msgs/Float32.h>

// 定义为全局变量
static ros::Subscriber sub1;
static ros::Subscriber sub2;
static ros::Publisher pub1;
static ros::Publisher pub2;

// 回调函数1
void callback1(const std_msgs::Float32ConstPtr& flt){
    std_msgs::Float32 pub_flt;
    pub_flt.data = flt->data+0.4;
    pub1.publish(pub_flt);

    std::cout<<"receive flt:"<<flt->data<<std::endl;
    std::cout<<"publish flt:"<<pub_flt.data<<std::endl;
};

// 回调函数2
void callback2(const std_msgs::StringConstPtr& str){
    std_msgs::String str_msg;
    str_msg.data = str->data+" hahaha";
    pub2.publish(str_msg);

    std::cout<<"receive str:"<<str->data<<std::endl;
    std::cout<<"publish str:"<<str_msg.data<<std::endl;
}


int main(int argc, char *argv[])
{
    // 初始化ROS并指定节点名称
    ros::init(argc, argv, "subscribe_publish2");
    // 创建节点句柄
    ros::NodeHandle nh;
    
    // 利用节点句柄对sub和pub初始化
    sub1 = nh.subscribe("topic_flt",1,callback1);
    sub2 = nh.subscribe("topic_str",1,callback2);
    pub1 = nh.advertise<std_msgs::Float32>("processed_flt", 1);
    pub2 = nh.advertise<std_msgs::String>("processed_str",1);

    // 循环执行
    ros::spin();
    return 0;
}