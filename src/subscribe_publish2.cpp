# include<ros/ros.h>
# include<std_msgs/String.h>
# include<std_msgs/Float32.h>

class Processer
{
// 为了保持C++类数据封装的特性，将成员变量写成私有
// 当然如果是public也是完全没问题的，只是有点破坏数据的封装性
private:
    ros::NodeHandle nh;
    ros::Subscriber sub1;
    ros::Subscriber sub2;
    ros::Publisher pub1;
    ros::Publisher pub2;

public:
    // 构造函数中对sub和pub进行初始化
    Processer(){
        // 注意订阅函数的写法，第三个参数要写成&+类名+callback形式，以及最后增加this
        sub1 = nh.subscribe("topic_flt",1,&Processer::callback1,this);
        sub2 = nh.subscribe("topic_str",1,&Processer::callback2,this);
        
        pub1 = nh.advertise<std_msgs::Float32>("processed_flt", 1);
        pub2 = nh.advertise<std_msgs::String>("processed_str",1);
    };

    // 回调函数1,作为类的成员函数
    void callback1(const std_msgs::Float32ConstPtr& flt){
        std_msgs::Float32 pub_flt;
        pub_flt.data = flt->data+0.4;
        pub1.publish(pub_flt);

        std::cout<<"receive flt:"<<flt->data<<std::endl;
        std::cout<<"publish flt:"<<pub_flt.data<<std::endl;
    };

    // 回调函数2,作为类的成员函数
    void callback2(const std_msgs::StringConstPtr& str){
        std_msgs::String str_msg;
        str_msg.data = str->data+" hahaha";
        pub2.publish(str_msg);

        std::cout<<"receive str:"<<str->data<<std::endl;
        std::cout<<"publish str:"<<str_msg.data<<std::endl;
    }
};


int main(int argc, char *argv[])
{
    // 初始化ROS并指定节点名称
    ros::init(argc, argv, "subscribe_publish1");

    // // 新建一个处理类对象，程序会自动调用构造函数初始化sub、pub
    Processer p;

    // 循环执行
    ros::spin();
    return 0;
}