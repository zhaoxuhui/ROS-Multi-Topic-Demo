# include<ros/ros.h>
# include<std_msgs/String.h>
# include<std_msgs/Float32.h>
# include<std_msgs/Float32MultiArray.h>


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "multi_publish");
    ros::NodeHandle nh;
    ros::Publisher pub1 = nh.advertise<std_msgs::String>("topic_str",1);
    ros::Publisher pub2 = nh.advertise<std_msgs::Float32>("topic_flt",1);
    ros::Publisher pub3 = nh.advertise<std_msgs::Float32MultiArray>("topic_arr",1);

    // 一定要注意，这里发布的String、Float等类型的消息本质是Message，而不是C++里的类型
    // 所以新建了一个Message的类型后，不能直接对Message赋值，而是应该对它里面的成员变量data赋值！
    std_msgs::String str_msg;
    str_msg.data = "this is a string from node";

    std_msgs::Float32 flt_msg;
    flt_msg.data = 2.3;

    std_msgs::Float32MultiArray arr_msg;
    std::vector<float> data{1.2,6.8,7.4};
    arr_msg.data = data;

    ros::Rate rate(1);
    while (nh.ok())
    {
        pub1.publish(str_msg);
        pub2.publish(flt_msg);
        pub3.publish(arr_msg);
        
        std::cout<<"published str:"<<str_msg.data<<std::endl;
        std::cout<<"published flt:"<<flt_msg.data<<std::endl;
        std::cout<<"published arr:";
        for (size_t i = 0; i < arr_msg.data.size(); i++)
        {
            std::cout<<arr_msg.data[i];
        }
        std::cout<<std::endl;
        
        rate.sleep();
    }

    // 注意spin和spinOnce的区别
    // spin让ros一直调用回调函数，ros::spin以下的代码无效
    // spinOnce让ros调用回调函数的同时还可以继续执行以下的代码
    // 由于这里后面没有代码了，所以两个没有区别
    ros::spinOnce();
    return 0;
}