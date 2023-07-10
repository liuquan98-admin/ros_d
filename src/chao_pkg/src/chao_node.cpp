#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int32.h>  //消息类型对应的头文件
int main(int argc, char  *argv[])
{
    ros::init(argc,argv,"demo_topic_publisher"); //初始化chao_node节点
    ros::NodeHandle node_ohj;//创建一个NodeHandle对象与ROS通信
    ros::Publisher number_publisher=node_ohj.advertise<std_msgs::Int32>("/number",10);//创建话题发布者，消息类型Int32,指定缓存大小
    ros::Rate loop_rate(10);//设置发送数据的频率
    int number_conut=0;
    while (ros::ok())
    {
     std_msgs::Int32 msg;  //创建整型ROS消息
     msg.data=number_conut;//ROS消息分配整型数据
     
     ROS_INFO("%d",msg.data);//输出ROS消息数据
     number_publisher.publish(msg);//将发布消息推送到"/number"话题上
     ros::spinOnce();//读取更话所有ROS话题
     loop_rate.sleep();
     ++number_conut;  
     }
    
             
    return 0;
}
