#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int32.h>  //消息类型对应的头文件
//订阅者所需的头文件
void number_call(const std_msgs::Int32::ConstPtr& msg){
  ROS_INFO("RECEIVED[%d]",msg->data);
}
int main(int argc, char  *argv[])
{
   ros::init(argc,argv,"subscriber");//初始化chao_node节点
   ros::NodeHandle nh;//创建一个NodeHandle对象与ROS通信
   ros::Subscriber sub=nh.subscribe("/number",10,number_call); //回调函数
   ros::spin(); //添加一条注释1
   return 0;
}
