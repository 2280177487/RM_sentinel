双云台哨兵注意事项：
以底盘电机安装位置为左 以主控模块安装位置为前

1.左云台为主云台 负责控制底盘和裁判模块的通信， 右云台读取传感器数据，通过can1传输给左云台

2.其中由于两个云台关于法线对称，所以pitch轴电机的旋转方向刚好相反，故两份代码的pitch限位和控制方向相反

左云台电机id:
3508底盘电机1 2
2006拨盘电机3
6020云台电机pitch 1 yaw 2 

右云台电机id:
2006拨盘电机4
6020云台电机pitch3 yaw4

