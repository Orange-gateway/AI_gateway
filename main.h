#ifndef _MAIN_H_
#define _MAIN_H_
#include "pthread.h"
#include <stdint.h>
#define BUFFSIZE 81920
#define BUFFSIZE_MAX 819200
#define BUFFSIZE_ROOM 10240
 int cd;//socket 描述符
 int down_cd;
 int fd;//串口描述符
 int NET_FLAG; 
 int device_flag;
 int down_gw_flag;
 int alive;
 pid_t main_pid;
 //time_t first;//接收更新时间
 //time_t second;//心跳更新时间
 time_t net_record_time;//入网记录时间
 pthread_mutex_t mutex_v;//全开全关下发锁
 pthread_mutex_t mutex_sl;//遍历设备列表锁
 pthread_mutex_t mutex_zl;//遍历设备状态列表锁
 pthread_mutex_t mutex_bl;//遍历多联绑定列表锁
 pthread_mutex_t mutex_qj;//安防模式文件锁
 pthread_mutex_t mutex_af;//安防列表文件锁
 pthread_mutex_t mutex_scene;//情景文件
 pthread_mutex_t mutex_time;//定时器列表
 pthread_mutex_t mutex_voice;//离线语音锁
 pthread_mutex_t mutex_code;//码库锁
 pthread_mutex_t mutex_down_file;//下载文件锁
 pthread_mutex_t mutex_room;//房间锁
 pthread_mutex_t mutex_human;//人体文件互斥锁
 pthread_mutex_t mutex_delay;//智能插座文件互斥锁
 pthread_mutex_t mutex_resend;//重发互斥锁
 pthread_cond_t cond;
 pthread_mutex_t mutex_waite;
 typedef struct resend //重发结构体
 {
 	time_t now_time;//登记现在的时间
 	int now_times;//登记现在的次数
 	char dev_id[20];
 	char dev_type[10];
 	uint8_t cmd[64];//命令
 	struct resend *next;
 }RSD;
 RSD *resend_head,*resend_z,*resend_d;
 typedef struct human //human_body结构体
 {
	time_t now_time;//登记现在的时间
 	char mac[17];
 	char port[3];
 	char id[20];
 	char type[10];
 	int flag;
 	struct human *next;
 }HB;
 HB *human_head,*human_z,*human_d;
 typedef struct delay //延时控制结构体（智能插座）
 {
 	char dev_mac[17];
 	char dev_port[3];
 	char dev_id[20];
 	char dev_type[10];
 	char cmd[3];
 	int delay_time[3];
 	int flag;
 	struct delay *next;
 }DELAY;
 DELAY *delay_head,*delay_z,*delay_d;
 char str_from_server[BUFFSIZE_MAX];//中间转换缓冲区
 char scene_list[BUFFSIZE];//情景列表缓存区
 char scene_detail[BUFFSIZE_MAX];//情景明细缓存区
 char device_list[BUFFSIZE_MAX];//设备列表缓存区
 char timer_list[BUFFSIZE];//定时器列表缓存区
 char secure_set_list[BUFFSIZE];//安放设置列表缓存区
 char multi_bind[BUFFSIZE];//多联绑定缓存区
 char voice_list[BUFFSIZE];//离线语音列表缓存区
 char device_state_list[BUFFSIZE];//设备状态缓存区
 char code_id[BUFFSIZE];//码库id缓存区
 char room_list[BUFFSIZE_ROOM];//房间列表缓冲区
 char gw_sn[100];//sn缓存区
 int identify_flag;//身份验证成功标志
 int go_net_flag;//允许入网标志
 int onekey_or_study_flag;
 char qj_model[5];
 char gw_version[9];
 char zigbee_channel[3];
 char zigbee_id[5];
#endif
