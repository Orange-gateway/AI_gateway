#include "include.h"
void file_init_common()
{
/*	初始化情景列表文件*/
	memset(scene_list,0,BUFFSIZE);
	int scene_list_fd = open("/system/bin/scene_list.txt",O_RDWR|O_CREAT,0777);
	
	int scene_list_read_len = read(scene_list_fd,scene_list,BUFFSIZE);

	close(scene_list_fd);
	if(json_checker(scene_list)==0 && scene_list_read_len>0)
		;
	else
	{
		printf("scene_list not json!!!\n");
		memset(scene_list,0,BUFFSIZE);
		scene_list_fd = open("/system/bin/scene_list.txt",O_RDWR|O_CREAT|O_TRUNC,0777);
		memcpy(scene_list,"{}",2);
		write(scene_list_fd,scene_list,2);
		fsync(scene_list_fd);
		close(scene_list_fd);
	}


/*	初始化情景明细文件  */
	
	memset(scene_detail,0,BUFFSIZE_MAX);
	int scene_detail_fd = open("/system/bin/scene_detail.txt",O_RDWR|O_CREAT,0777);

	int scene_detail_read_len = read(scene_detail_fd,scene_detail,BUFFSIZE_MAX);

	close(scene_detail_fd);
	if(json_checker(scene_detail)==0 && scene_detail_read_len>0)
		;
	else
	{
		printf("scene_detail not json!!!\n");
		memset(scene_detail,0,BUFFSIZE_MAX);
		scene_detail_fd = open("/system/bin/scene_detail.txt",O_RDWR|O_CREAT|O_TRUNC,0777);
		memcpy(scene_detail,"{}",2);
		write(scene_detail_fd,scene_detail,2);
		fsync(scene_detail_fd);
		close(scene_detail_fd);
	}


/* 	初始化设备列表文件  */
	
	memset(device_list,0,BUFFSIZE_MAX);
	int device_list_fd = open("/system/bin/device_list.txt",O_RDWR|O_CREAT,0777);

	int device_list_read_len = read(device_list_fd,device_list,BUFFSIZE_MAX);
	close(device_list_fd);
	if(json_checker(device_list)==0  && device_list_read_len>0)
		;
	else
	{
		printf("device_list not json!!!\n");
		memset(device_list,0,BUFFSIZE_MAX);
		device_list_fd = open("/system/bin/device_list.txt",O_RDWR|O_CREAT|O_TRUNC,0777);
		memcpy(device_list,"{}",2);
		write(device_list_fd,device_list,2);
		fsync(device_list_fd);
		close(device_list_fd);
	}
	
	
/*	初始化设备状态列表文件  */
	pthread_mutex_lock(&mutex_zl);
	memset(device_state_list,0,BUFFSIZE);
	int device_state_list_fd = open("/system/bin/device_state_list.txt",O_RDWR|O_CREAT,0777);

	int device_state_list_len = read(device_state_list_fd,device_state_list,BUFFSIZE);
	close(device_state_list_fd);
	if(json_checker(device_state_list)==0 && device_state_list_len>0)
	{
		;
	}
	
	else
	{
		printf("device_state_list not json!!!\n");
		close(device_state_list_fd);
		device_state_list_fd = open("/system/bin/device_state_list.txt",O_RDWR|O_CREAT|O_TRUNC,0777);//重新打开创建
		memset(device_state_list,0,BUFFSIZE);
		cJSON *device_stae_root = cJSON_CreateObject();
		cJSON_AddStringToObject(device_stae_root,"co","orange");
		cJSON_AddStringToObject(device_stae_root,"api","gw_upDevState");
		cJSON *dev_status_data = cJSON_CreateObject();
		cJSON_AddItemToObject(device_stae_root,"data",dev_status_data);
		char *send_char = cJSON_PrintUnformatted(device_stae_root);
		int my_len = strlen(send_char);
		write(device_state_list_fd,send_char,my_len);
		fsync(device_state_list_fd);
		close(device_state_list_fd);
		memcpy(device_state_list,send_char,my_len);
		free(send_char);
		send_char = NULL;
		cJSON_Delete(device_stae_root);
		device_stae_root=NULL;
		device_flag = 1;
	}	
	pthread_mutex_unlock(&mutex_zl);

/*	初始化定时器列表文件  */
	
	memset(timer_list,0,BUFFSIZE);
	int timer_list_fd = open("/system/bin/timer_list.txt",O_RDWR|O_CREAT,0777);

	int timer_list_read_len = read(timer_list_fd,timer_list,BUFFSIZE);

	close(timer_list_fd);
	if(json_checker(timer_list)==0 && timer_list_read_len>0)
		;
	else
	{
		printf("timer_list not json!!!\n");
		memset(timer_list,0,BUFFSIZE);
		timer_list_fd = open("/system/bin/timer_list.txt",O_RDWR|O_CREAT|O_TRUNC,0777);
		memcpy(timer_list,"{}",2);
		write(timer_list_fd,timer_list,2);
		fsync(timer_list_fd);
		close(timer_list_fd);
	}
	

/*	安放模式设置列表  */
	
	memset(secure_set_list,0,BUFFSIZE);
	int secure_set_list_fd = open("/system/bin/secure_set_list.txt",O_RDWR|O_CREAT,0777);

	int secure_set_list_read_len = read(secure_set_list_fd,secure_set_list,BUFFSIZE);

	close(secure_set_list_fd);
	if(json_checker(secure_set_list)==0 && secure_set_list_read_len>0)
		;
	else
	{
		printf("secure_set_list not json!!!\n");
		secure_set_list_fd = open("/system/bin/secure_set_list.txt",O_RDWR|O_CREAT|O_TRUNC,0777);
		memset(secure_set_list,0,BUFFSIZE);
		memcpy(secure_set_list,"{}",2);
		write(secure_set_list_fd,secure_set_list,2);
		fsync(secure_set_list_fd);
		close(secure_set_list_fd);
	}


/*	初始化多联绑定文件  */
	
	memset(multi_bind,0,BUFFSIZE);
	int multi_bind_fd = open("/system/bin/multi_bind.txt",O_RDWR|O_CREAT,0777);

	int multi_bind_read_len = read(multi_bind_fd,multi_bind,BUFFSIZE);

	close(multi_bind_fd);
	if(json_checker(multi_bind)==0 && multi_bind_read_len>0)
		;
	else
	{
		printf("multi_bind not json!!!\n");
		multi_bind_fd = open("/system/bin/multi_bind.txt",O_RDWR|O_CREAT|O_TRUNC,0777);
		memset(multi_bind,0,BUFFSIZE);
		memcpy(multi_bind,"{}",2);
		write(multi_bind_fd,multi_bind,2);
		fsync(multi_bind_fd);
		close(multi_bind_fd);
	}


/* 初始化离线语音文件 */
	memset(voice_list,0,BUFFSIZE);
	int voice_fd = open("/system/bin/voice.txt",O_RDWR|O_CREAT,0777);

	int voice_list_len = read(voice_fd,voice_list,BUFFSIZE);

	close(voice_fd);
	if(json_checker(voice_list)==0 && voice_list_len > 0)
		;
	else
	{
		printf("voice_list not json!!!\n");
		voice_fd = open("/system/bin/voice.txt",O_RDWR|O_CREAT|O_TRUNC,0777);
		memset(voice_list,0,BUFFSIZE);
		memcpy(voice_list,"{}",2);
		write(voice_fd,voice_list,2);
		fsync(voice_fd);
		close(voice_fd);

	}

	/* 初始化码库文件  */
	pthread_mutex_lock(&mutex_code);
	memset(code_id,0,BUFFSIZE);
	int code_fd = open("/system/bin/code.txt",O_RDWR|O_CREAT,0777);

	int code_id_len = read(code_fd,code_id,BUFFSIZE);

	close(code_fd);
	if(json_checker(code_id)==0 && code_id_len > 0)
	{
		;
	}
	else
	{
		printf("code_id not json!!!\n");
		code_fd = open("/system/bin/code.txt",O_RDWR|O_CREAT|O_TRUNC,0777);
		memset(code_id,0,BUFFSIZE);
		cJSON *code_root = cJSON_CreateObject();
		cJSON *code_kt = cJSON_CreateObject();
		cJSON *code_fkt = cJSON_CreateObject();
		cJSON_AddItemToObject(code_root,"kt",code_kt);
		cJSON_AddItemToObject(code_root,"fkt",code_fkt);
		char *code_char = cJSON_PrintUnformatted(code_root);
		memcpy(code_id,code_char,strlen(code_char));
		write(code_fd,code_id,strlen(code_char));
		fsync(code_fd);
		close(code_fd);
		free(code_char);
		code_char=NULL;
		cJSON_Delete(code_root);
		code_root=NULL;
	}
	pthread_mutex_unlock(&mutex_code);
	
	/*初始化房间列表文件*/
	pthread_mutex_lock(&mutex_room);
	memset(room_list,0,BUFFSIZE_ROOM);
	int room_fd = open("/system/bin/room_list.txt",O_RDWR|O_CREAT,0777);
	int room_fd_len = read(room_fd,room_list,BUFFSIZE_ROOM);
	close(room_fd);
	if(json_checker(room_list)==0 && room_fd_len > 0)
	{
		;
	}
	else
	{
		printf("room_list not json\n");
		room_fd = open("/system/bin/room_list.txt",O_RDWR|O_CREAT|O_TRUNC,0777);
		memset(room_list,0,BUFFSIZE_ROOM);
		memcpy(room_list,"{}",2);
		write(room_fd,room_list,2);
		fsync(room_fd);
		close(room_fd);
	}
	pthread_mutex_unlock(&mutex_room);
	
	/*初始化人体列表*/
	char control_human[10240];
	memset(control_human,0,10240);
	int human_fd = open("/system/bin/human_list.txt",O_RDWR|O_CREAT,0777);
	int human_fd_len = read(human_fd,control_human,10240);
	close(human_fd);
	if(json_checker(control_human)==0 && human_fd_len > 0)
	{
		cJSON *human_root = cJSON_Parse(control_human);
		if(human_root != NULL)
		{
			if(human_root->child != NULL)
			{
				cJSON *human_arr = cJSON_GetObjectItem(human_root,"human_list");
				int num = cJSON_GetArraySize(human_arr);
				int i = 0;
				cJSON *get_arr = NULL;
				cJSON *tem_mac = NULL;
				cJSON *tem_port = NULL;
				cJSON *tem_id = NULL;
				cJSON *tem_type = NULL;
				cJSON *tem_time = NULL;
				for(i=0;i<num;i++)
				{
					get_arr = cJSON_GetArrayItem(human_arr,i);
					tem_mac = cJSON_GetObjectItem(get_arr,"dev_mac");
					tem_port = cJSON_GetObjectItem(get_arr,"dev_port");
					tem_id = cJSON_GetObjectItem(get_arr,"dev_id");
					tem_type = cJSON_GetObjectItem(get_arr,"dev_type");
					tem_time = cJSON_GetObjectItem(get_arr,"dev_time");
					human_zt(tem_mac->valuestring,tem_port->valuestring,tem_id->valuestring,tem_type->valuestring,tem_time->valueint);
				}
			}
		}
		cJSON_Delete(human_root);
		human_root = NULL;
	}
	/*初始化延时控制列表*/
	char control_delay[10240];
	memset(control_delay,0,10240);
	int delay_fd = open("/system/bin/delay_list.txt",O_RDWR|O_CREAT,0777);
	int delay_fd_len = read(delay_fd,control_delay,10240);
	close(delay_fd);
	if(json_checker(control_delay)==0 && delay_fd_len > 0)
	{
		cJSON *delay_root = cJSON_Parse(control_delay);
		if(delay_root != NULL)
		{
			if(delay_root->child != NULL)
			{
				cJSON *delay_arr = cJSON_GetObjectItem(delay_root,"delay_list");
				int num = cJSON_GetArraySize(delay_arr);
				int i = 0;
				cJSON *get_arr = NULL;
				cJSON *tem_id = NULL;
				cJSON *tem_mac = NULL;
				cJSON *tem_type = NULL;
				cJSON *tem_port = NULL;
				cJSON *tem_hour = NULL;
				cJSON *tem_min = NULL;
				cJSON *tem_sec = NULL;
				cJSON *tem_cmd = NULL;
				for(i=0;i<num;i++)
				{
					get_arr = cJSON_GetArrayItem(delay_arr,i);
					tem_id = cJSON_GetObjectItem(get_arr,"dev_id");
					tem_mac = cJSON_GetObjectItem(get_arr,"dev_mac");
					tem_type = cJSON_GetObjectItem(get_arr,"dev_type");
					tem_port = cJSON_GetObjectItem(get_arr,"dev_port");
					tem_hour = cJSON_GetObjectItem(get_arr,"dev_hour");
					tem_min = cJSON_GetObjectItem(get_arr,"dev_min");
					tem_sec = cJSON_GetObjectItem(get_arr,"dev_sec");
					tem_cmd = cJSON_GetObjectItem(get_arr,"dev_cmd");
					delay_zt(tem_cmd->valuestring,tem_mac->valuestring,tem_port->valuestring,tem_id->valuestring,tem_type->valuestring,tem_hour->valueint,tem_min->valueint,tem_sec->valueint,0);
				}
			}
		}
		cJSON_Delete(delay_root);
		delay_root = NULL;
	}
}

void file_init_net(void)
{
	/* 初始化码库文件  */
	pthread_mutex_lock(&mutex_code);
	memset(code_id,0,BUFFSIZE);
	int code_fd = open("/system/bin/code.txt",O_RDWR|O_CREAT,0777);

	int code_id_len = read(code_fd,code_id,BUFFSIZE);

	close(code_fd);
	if(json_checker(code_id)==0 && code_id_len > 0)
	{
		cJSON *up_to_ser_code = cJSON_CreateObject();
		cJSON_AddStringToObject(up_to_ser_code,"co","orange");
		cJSON_AddStringToObject(up_to_ser_code,"api","get_lid_ver");
		cJSON *up_to_ser_data = cJSON_CreateArray();
		cJSON_AddItemToObject(up_to_ser_code,"data",up_to_ser_data);
		cJSON *code_id_root = cJSON_Parse(code_id);
		if(code_id_root != NULL)
		{
			if(code_id_root->child != NULL)
			{
				cJSON *kt_root = cJSON_GetObjectItem(code_id_root,"kt");
				if(kt_root != NULL)
				{
					cJSON *kt_while = kt_root->child;
					while(kt_while != NULL)
					{
						cJSON_AddStringToArray(up_to_ser_data,kt_while->string);
						kt_while = kt_while->next;
					}
				}
				cJSON *fkt_root = cJSON_GetObjectItem(code_id_root,"fkt");
				if(fkt_root != NULL)
				{
					cJSON *fkt_while = fkt_root->child;
					while(fkt_while != NULL)
					{
						cJSON_AddStringToArray(up_to_ser_data,fkt_while->string);
						fkt_while = fkt_while->next;
					}
				}
			}
		}
		cJSON_Delete(code_id_root);
		code_id_root=NULL;
		char *send_char = cJSON_PrintUnformatted(up_to_ser_code);
		int my_len = strlen(send_char);
		char *my_send_char = (char *)malloc(my_len+2);
		memset(my_send_char,0,my_len+2);
		memcpy(my_send_char,send_char,my_len);
		strcat(my_send_char,"\n\0");
		send(cd,my_send_char,my_len+1,0);
		free(send_char);
		send_char=NULL;
		free(my_send_char);
		my_send_char = NULL;
		cJSON_Delete(up_to_ser_code);
		up_to_ser_code=NULL;
	}
	else
	{
		printf("code_id not json!!!\n");
		code_fd = open("/system/bin/code.txt",O_RDWR|O_CREAT|O_TRUNC,0777);
		memset(code_id,0,BUFFSIZE);
		cJSON *code_root = cJSON_CreateObject();
		cJSON *code_kt = cJSON_CreateObject();
		cJSON *code_fkt = cJSON_CreateObject();
		cJSON_AddItemToObject(code_root,"kt",code_kt);
		cJSON_AddItemToObject(code_root,"fkt",code_fkt);
		char *code_char = cJSON_PrintUnformatted(code_root);
		memcpy(code_id,code_char,strlen(code_char));
		write(code_fd,code_id,strlen(code_char));
		fsync(code_fd);
		close(code_fd);
		free(code_char);
		code_char=NULL;
		cJSON_Delete(code_root);
		code_root=NULL;
	}
	pthread_mutex_unlock(&mutex_code);
	usleep(10000);
	
/*	初始化设备状态列表文件  */

	update_state();
	int device_state_list_len = strlen(device_state_list);
	char *my_send_char_dev = (char *)malloc(device_state_list_len+2);
	memset(my_send_char_dev,0,device_state_list_len+2);
	memcpy(my_send_char_dev,device_state_list,device_state_list_len);
	strcat(my_send_char_dev,"\n\0");
	if(device_flag == 0)
		send(cd,my_send_char_dev,device_state_list_len+2,0);
	else if(device_flag == 1)
	{
		cJSON *device_stae_root = cJSON_CreateObject();
		cJSON_AddStringToObject(device_stae_root,"co","orange");
		cJSON_AddStringToObject(device_stae_root,"api","gw_upDevState");
		cJSON *dev_status_data = cJSON_CreateObject();
		cJSON_AddItemToObject(device_stae_root,"data",dev_status_data);
		char *send_char = cJSON_PrintUnformatted(device_stae_root);
		int my_len = strlen(send_char);
		char *my_send_char = (char *)malloc(my_len+2);
		memset(my_send_char,0,my_len+2);
		memcpy(my_send_char,send_char,my_len);
		strcat(my_send_char,"\n\0");
		send(cd,my_send_char,my_len+1,0);
		free(send_char);
		send_char = NULL;
		free(my_send_char);
		my_send_char = NULL;
		cJSON_Delete(device_stae_root);
		device_stae_root=NULL;
	}
	free(my_send_char_dev);
	my_send_char_dev=NULL;
	
	
/*  初始化安防模式文件	*/
	pthread_mutex_lock(&mutex_qj);	
	memset(qj_model,0,5);
	int qj_model_fd = open("/system/bin/qj_model.txt",O_RDWR|O_CREAT,0777);
	int qj_model_len = read(qj_model_fd,qj_model,5);
	if(qj_model_len==-1 || qj_model_len <4)
	{
		memset(qj_model,0,5);
		memcpy(qj_model,"0101",4);
		write(qj_model_fd,"0101",4);
		fsync(qj_model_fd);
	}
	cJSON *secure_model_now = cJSON_CreateObject();
	cJSON *secure_model_now_data = cJSON_CreateObject();
	cJSON_AddNumberToObject(secure_model_now,"retcode",0);
	cJSON_AddStringToObject(secure_model_now,"message","success");
	cJSON_AddStringToObject(secure_model_now,"api","secuModelRes");
	cJSON_AddItemToObject(secure_model_now,"data",secure_model_now_data);
	cJSON_AddStringToObject(secure_model_now_data,"model",qj_model);
	char *secure_model_now_char = cJSON_PrintUnformatted(secure_model_now);
	int my_len = strlen(secure_model_now_char);
	char *my_send_char = (char *)malloc(my_len+2);
	memset(my_send_char,0,my_len+2);
	memcpy(my_send_char,secure_model_now_char,my_len);
	strcat(my_send_char,"\n\0");
	send(cd,my_send_char,my_len+1,0);
	free(secure_model_now_char);
	secure_model_now_char=NULL;
	free(my_send_char);
	my_send_char=NULL;
	cJSON_Delete(secure_model_now);
	secure_model_now=NULL;
	close(qj_model_fd);
	pthread_mutex_unlock(&mutex_qj);
}


