1 //串口打印相关的: driver_l1_cfg.h
	//#define UART0_TX_IOB5__RX_IOB4						0x00000001
	//#define UART0_TX_IOC12__RX_IOC13					0x00000002
	//#define UART0_TX_IOD5__RX_IOD4						0x00000003
	//#define UART1_TX_IOB7__RX_IOB6						0x00000004
	//#define UART1_TX_IOC15__RX_IOC14					0x00000005
	//#define UART1_TX_IOD9__RX_IOD8						0x00000006
	//#define UART1_TX_IOD15__RX_IOD14					0x00000007
	//#define UART_TX_NONE__RX_NONE						0x00000000
	
	//#if DBG_MESSAGE == CUSTOM_ON
	//#if 1//(GPDV_BOARD_VERSION == DVP_V1_0)  // EVB
	//#if PCB_TYPE                  ==         TYPE_1248

	//#define UART_TX_RX_POS			   UART1_TX_IOB7__RX_IOB6// UART1_TX_IOD9__RX_IOD8
	//#else

	//#define UART_TX_RX_POS			   UART1_TX_IOC15__RX_IOC14//UART1_TX_IOC15__RX_IOC14//UART1_TX_IOB7__RX_IOB6 
	//#endif
	//#else
	//#define UART_TX_RX_POS              UART_TX_NONE__RX_NONE
	//#endif
2 //打开串口调试: customer.h
	//#define CUSTOM_ON       1
	//#define CUSTOM_OFF      0

	//#define DBG_MESSAGE						CUSTOM_ON//CUSTOM_OFF 	// UART debug message
3 //烧录工具: writer（D:\TOOL）
4 //工程中Tool的运用：
	//运行ComBin.exe， F:\work\study\v001\programe\Tools\GPCV1248_SPIFC_Pack_\GPCV1248_SDRAM_Header_144M.bin，其中144的确定,
	//{(CUSTOMER.H)
		// CPU and system clock
	//	#define INIT_MHZ                    	144//115//144     // MHz
	//}
5 //调试程序的:
	//#if 0
	//#undef __here__
	//#undef __msg
	//#define __here__            eLIBs_printf("@L%d(%s)\n", __LINE__, __FILE__);
	//#define __msg(...)    		(eLIBs_printf("MSG:L%d(%s):", __LINE__, __FILE__),                 \
							     eLIBs_printf(__VA_ARGS__)									        )
	//#define DebugPrintf(...)    		(eLIBs_printf("MSG:L%d(%s):", __LINE__, __FILE__),                 \
	//						     eLIBs_printf(__VA_ARGS__)									        )
	//#else
		//#define DebugPrintf(...)
	//#endif
	
6 //LED灯的控制，根据原理图看是哪个io口控制，然后把io设置成相应的电平值: (ap_peripheral_handling.c)
	//case LED_INIT:

    //    led_green_on();
		/* add begin by Zhibo, 2017-04-27 */
		//led_red_on();
		/* add end by Zhibo, 2017-04-27 */
//        DBG_PRINT("led_type = LED_INIT\r\n");
      //  __msg("led_type = LED_INIT\r\n");
    //    break;
	//(customer.h)
	//#define LED1							IO_E3
	//#define LED2							IO_E2
	
7 //    OSTaskCreate(state_handling_entry, (void *) 0, &StateHandlingStack[STATE_HANDLING_STACK_SIZE - 1], STATE_HANDLING_PRIORITY);
	//系统的初始化

8 //sd卡或者usb： void state_video_record_entry(void *para, INT32U state)中，首先判断有没有sd或者usb，没有的时候，
	//向MSG_PERIPHERAL_TASK_LED_SET队列中发送消息。如果有则进行判别是连接电脑还是连接usb或者sd。
	//ap_state_handling_connect_to_pc(STATE_VIDEO_RECORD);摄像状态
	
9. //有电池没有usb连接时，五秒自动关机，msgQSend(ApQ, MSG_APQ_POWER_KEY_ACTIVE, NULL, NULL, MSG_PRI_NORMAL);
	//
	//if(shutoff_cnt){
      //          shutoff_cnt--;
     //           if(usb_state_get() != 0)
      //          {
                    //led_green_off();
     //               shutoff_cnt = 0;
     //               DBG_PRINT("fankun5:%d\r\n", usb_state_get());
      //          }
     //           if(!shutoff_cnt)
      //          {
       //             if(usb_state_get() == 0)
      //              {
      //                  DBG_PRINT("fankun1:%d\r\n", usb_state_get());
      //                  msgQSend(ApQ, MSG_APQ_POWER_KEY_ACTIVE, NULL, NULL, MSG_PRI_NORMAL);
      //              }
      //          }
     //           else
      //          {
      //              if(shutoff_cnt % 20 == 0)
     //               {
      //                  if(t_flash_flag == 0)
      //                  {
     //                       t_flash_flag = 1;
		//					moto_vibration_on(20);
       //                     led_green_on();
       //                     led_red_on();
      //                  }
      //                  else
                        //{
                            //led_red_off();
                           // led_green_off();
                            //t_flash_flag = 0;
                       // }
                   // }
              //  }

           // }
			//--->case MSG_APQ_POWER_KEY_ACTIVE:
          //  if ((ap_video_record_sts_get() & VIDEO_RECORD_BUSY))
          //  {

             //   if(ap_video_record_func_key_active(msg_id))
             //   {
             //       break;
              //  }
            //}
            //	DBG_PRINT("dfdfffdf\r\n");
            //msgQSend(PeripheralTaskQ, MSG_PERIPHERAL_TASK_ZD, &type, sizeof(INT8U), MSG_PRI_NORMAL);
            //OSTimeDly(5);
            //video_encode_exit();
            //video_calculate_left_recording_time_disable();
            //ap_state_handling_power_off();
            //break;
			//--->
10. //进入摄像头状态,msgQSend(ApQ, MSG_APQ_VIDEO_RECORD_ACTIVE, NULL, NULL, MSG_PRI_NORMAL);
	
11. //摄像循环间隔： ap_state_config_record_time_set(void);  宏:define C_CYCLIC_VIDEO_RECORD on/off
	
12. //格式化TF卡命令：msgQSend(StorageServiceQ, MSG_STORAGE_SERVICE_FORMAT_REQ, NULL, NULL, MSG_PRI_NORMAL);

13. //移动侦测： msgQSend(ApQ, MSG_APQ_MOTION_DETECT_ACTIVE, NULL, NULL, MSG_PRI_NORMAL);
	//ap_state_config_md_set(status);status 要设置为1，不然停止的时候，会出问题。
	
14. //chdir(const char *path);更改当前工作目录。Path 目标目录，可以是绝对目录或相对目录。成功返回0 ，失败返回-1
	
15. // int unlink(const char* pathname);unlink从文件系统中中删除一个名字，若这个名字是指向这个文件的最后一个链接，
	//并且没有进程处于打开这个文件的状态，则删除这个文件，释放这个文件占用的空间。
	//如果这个名字是指向这个文件的最后一个链接，但有某个进程处于打开这个文件的状态，则暂时不删除这个文件，要等到打开
	//这个文件的进程关闭这个文件的文件描述符后才删除这个文件。
    //如果这个名字指向一个符号链接，则删除这个符号链接。
    //如果这个名字指向一个socket、fifo或者一个设备，则这个socket、fifo、设备的名字被删除，当时打开这些socke、fifo、
	//设备的进程仍然可以使用它们。
	//返回值：调用成功返回0，不成功返回-1.
	
16. //setfattr: The setfattr command associates a new value with an extended attribute name for each specified file.
	
17. // OS_EVENT     *OSQCreate(void **start, INT16U size);		调用OSQcreate()函数创建消息队列，
	
18. /*sprintf()函数用于将格式化的数据写入字符串，其原型为：
	  int sprintf(char *str, char * format [, argument, ...]);	
	  【参数】str为要写入的字符串；format为格式化字符串，与printf()函数相同；argument为变量。
	   sprintf的作用是将一个格式化的字符串输出到一个目的字符串中，而printf是将一个格式化的字
	   符串输出到屏幕。sprintf的第一个参数应该是目的字符串，
	   如果不指定这个参数，执行过程中出现 "该程序产生非法操作,即将被关闭...."的提示.
		sprintf()会根据参数format 字符串来转换并格式化数据，然后将结果复制到参数str 所指的字符串数组，
		直到出现字符串结束('\0')为止。关于参数format 字符串的格式请参考printf()。
	
	*/
   
19. /*
		(__asm)关键字启动内联汇编并且能写在任何C++合法语句之处。它不能单独出现，必须接汇编指令、
		一组被大括号包含的指令或一对空括号。术语"__asm块"在这里是任意一个指令或一组指令无论是否在括号内。
	*/
	
20. //MSG_STORAGE_SERVICE_MOUNT:检测有卡发送的状态.

21. //#define SD_POS   SDC_IOC4_IOC5_IOC6_IOC7_IOC8_IOC9 //sd卡

22. //录像自动保存： time_interval = 3 * VIDEO_RECORD_CYCLE_TIME_INTERVAL + 112;

23. //stat函数讲解
	//表头文件:    
	//		#include <sys/stat.h>
    //        #include <unistd.h>
	//定义函数:    
	//int stat(const char *file_name, struct stat *buf);
	//函数说明:    通过文件名filename获取文件信息，并保存在buf所指的结构体stat中
	//返回值:      执行成功则返回0，失败返回-1，错误代码存于errno
	
24. //void FS_OS_GetTime(dostime_t *dt);			//设置拍照录像显示时间与否
	//void FS_OS_GetDate(dosdate_t *dd);			//设置拍照录像显示时间与否
	
25. //APQ消息：只能在应用直接相互传递。	
	
26. //延时过程中，按键的抬起动作可能被过滤，没有及时的清除，从而影响操作。可以不用延时操作函数。
	
27. //void ap_video_record_md_tick(INT8U *md_tick, INT32U state), 移动侦测到一定时间后，停止侦测，并保存。
	
28. //ap_state_config_pic_size_set(8);设置图像大小，如：1280x720等

29. //ap_state_config_video_resolution_set(2);设置视频大小，如：720P

30. //循环录像，sys_set_timer((void *)msgQSend, (void *)ApQ, MSG_APQ_CYCLIC_VIDEO_RECORD, \
	//cyclic_record_timerid, time_interval);启动循环录像定时器，当触发点后，进行循环录像。
	
31. //state_handling_init(void)创建了APQ消息队列，所有的应用消息都从APQ中接收消息。应用之间的切换管理的窗口就是
	//state_handling_entry(void *para);相当于一个总应用管理窗口。
    
32. //ap_peripheral_charge_det();充电检测，配置好相应的IO口，如：#define CHARGE_PIN	 IO_D13//IO_C14

33. //ap_state_handling_connect_to_pc(INT32U prev_state),key_down = gpio_read_io(SWITCH_MODE_KEY);
	//来检测连接PC的是pc_cam模式还是usb模式。
	
33. //NVIC:嵌套中断向量控制器。
	
33. //定义函数：off_t lseek(int fildes, off_t offset, int whence);
	//每一个已打开的文件都有一个读写位置, 当打开文件时通常其读写位置是指向文件开头, 若是以附加的方式打开文件(如O_APPEND),
	//则读写位置会指向文件尾. 当read()或write()时, 读写位置会随之增加,lseek()便是用来控制该文件的读写位置. 
	//参数fildes 为已打开的文件描述词, 参数offset 为根据参数whence来移动读写位置的位移数.
	
	//参数 whence 为下列其中一种:
    //SEEK_SET 参数offset 即为新的读写位置.
    //SEEK_CUR 以目前的读写位置往后增加offset 个位移量.
    //SEEK_END 将读写位置指向文件尾后再增加offset 个位移量. 当whence 值为SEEK_CUR 或
    //SEEK_END 时, 参数offet 允许负值的出现.
	
	//下列是教特别的使用方式:
	//1) 欲将读写位置移到文件开头时:lseek(int fildes, 0, SEEK_SET);
	//2) 欲将读写位置移到文件尾时:lseek(int fildes, 0, SEEK_END);
	//3) 想要取得目前文件位置时:lseek(int fildes, 0, SEEK_CUR);
	
34. //定义函数:    int stat(const char *file_name, struct stat *buf); 通过文件名filename获取文件信息，并保存在buf所指的结构体stat中
	//返回值:      执行成功则返回0，失败返回-1，错误代码存于errno.
	//ENOENT         参数file_name指定的文件不存在
    //ENOTDIR        路径中的目录存在但却非真正的目录
    //ELOOP          欲打开的文件有过多符号连接问题，上限为16符号连接
    //EFAULT         参数buf为无效指针，指向无法存在的内存空间
    //EACCESS        存取文件时被拒绝
    //ENOMEM         核心内存不足
    //ENAMETOOLONG   参数file_name的路径名称太长
	
35. //task_state_handling.c中,state_handling_entry(void)管理着各个应用的切换任务，比如: preview, record, 
	//audio, browse, setting and so on.
	//每个应用的切换首先要经过这里，才能进入相应得应用处理对应的事件。

36. //开机logo, state_startup_init(void), 宏C_LOGO所定义的部分.

37. //tft_init();屏初始化相关的内容，点屏目涉及的参数时需要在这里调用。

38. //MAJOR(dev_t dev), MINOR(dev_t dev), MKDEV(int major, int minor);
	
39. //avi_audio_record_entry: gp_memset((INT8S *)(audio_frame[write_audio_idx].buffer_addrs + 8), 0, (AVI_AUDIO_PCM_SAMPLES << 1));
	//录像声音相关的。
	
40. //void FS_OS_GetDate(dosdate_t *dd),void FS_OS_GetTime(dostime_t *dt)显示文件时间日期。
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	