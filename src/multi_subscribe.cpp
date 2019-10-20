# include<ros/ros.h>
# include<std_msgs/String.h>
# include<std_msgs/Float32.h>
# include<std_msgs/Float32MultiArray.h>

void callback1(const std_msgs::StringConstPtr& str){
    std::cout<<"received str:"<<str->data<<std::endl;
}

void callback2(const std_msgs::Float32ConstPtr& flt){
    std::cout<<"received float:"<<flt->data<<std::endl;
}

void callback3(const std_msgs::Float32MultiArrayConstPtr& arr){
    std::cout<<"received array:";
    for (size_t i = 0; i < arr->data.size(); i++)
    {
        std::cout<<arr->data[i];
    }
    std::cout<<std::endl;
}

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "multi_subscribe");
    ros::NodeHandle nh;

    ros::Subscriber sub1 = nh.subscribe("topic_str",1,callback1);
    ros::Subscriber sub2 = nh.subscribe("topic_flt",1,callback2);
    ros::Subscriber sub3 = nh.subscribe("topic_arr",1,callback3);
    ros::spin();
    return 0;
}