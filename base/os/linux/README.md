[TOC]

# linux下的常用操作

## 查看linux进程占用的内存

```properties
可以直接使用top命令后，查看%MEM的内容。可以选择按进程查看或者按用户查看，如想查看oracle用户的进程内存使用情况的话可以使用如下的命令：
　 (1)top
　　top命令是Linux下常用的性能分析工具，能够实时显示系统中各个进程的资源占用状况，类似于Windows的任务管理器
　　可以直接使用top命令后，查看%MEM的内容。可以选择按进程查看或者按用户查看，如想查看oracle用户的进程内存使用情况的话可以使用如下的命令：
　　$ top -u oracle
内容解释：
　　PID：进程的ID
　　USER：进程所有者
　　PR：进程的优先级别，越小越优先被执行
　　NInice：值
　　VIRT：进程占用的虚拟内存
　　RES：进程占用的物理内存
　　SHR：进程使用的共享内存
　　S：进程的状态。S表示休眠，R表示正在运行，Z表示僵死状态，N表示该进程优先值为负数
　　%CPU：进程占用CPU的使用率
　　%MEM：进程使用的物理内存和总内存的百分比
　　TIME+：该进程启动后占用的总的CPU时间，即占用CPU使用时间的累加值。
　　COMMAND：进程启动命令名称
　　常用的命令：
　　P：按%CPU使用率排行
　　T：按MITE+排行
　　M：按%MEM排行
(2)pmap
　　可以根据进程查看进程相关信息占用的内存情况，(进程号可以通过ps查看)如下所示：
　　$ pmap -d 14596
(3)ps
　　如下例所示：
　　$ ps -e -o 'pid,comm,args,pcpu,rsz,vsz,stime,user,uid'  其中rsz是是实际内存
　　$ ps -e -o 'pid,comm,args,pcpu,rsz,vsz,stime,user,uid' | grep oracle |  sort -nrk5
　　其中rsz为实际内存，上例实现按内存排序，由大到小
(4)ps -aux --sort -rss 
查看内存实际占用排序
```

###### 清空cached

```shell
echo 1 > /proc/sys/vm/drop_caches
```

## 磁盘挂载和取消挂载

```properties
mkfs.ext4 /dev/vdb //新建数据盘，要格式化
mkdir /data
mount /dev/vdb /data
vi /etc/fstab
/dev/vda2               /usr/twsm               ext4    defaults        0 0
/dev/vda3               /opt                    ext4    defaults        0 0
/dev/vdb                /data                   ext4    defaults        0 0
umount /dev/vdb   ，其他反过来

更换磁盘：
将老数据拷贝到临时目录B，将新磁盘S1挂载上B。
将旧磁盘S2取消挂载A。
创建同名目录A。
取消新磁盘挂载B，然后挂载到这个同名目录A即可。
```

## 磁盘分区

```properties
管理员用户，你们可以不用使用了，我已帮你们把镜像全部创建好了，你们只需要使用普通用户按照要求创建主机即可（存储暂时悠着点用）。
产品线	普通用户	普通用户密码	管理员用户	实例数	CPU	内存(G)	数据盘（块）
CCE	shenjunguo	shenjunguo	cce_admin	15	180	200	30
教育云	zhumingliang       chengguangming	
ecp_admin	15	180	200	30
大数据组	zhangxiaoyou	
esc_admin	10	320	160	20
ECO平台	jiangwenping	
pingtai_admin	15	180	200	30
维优	penglin	
weiyou_admin	10	120	160	20
测试组	ouzongping	
ceshi_admin	10	160	160	20
综合部	yangsong	　	teewon_manager	5	40	80	10


附相关步骤及命令：
1、使用普通用户登录http://192.168.128.11:8080/cloud-web/#/login/login
2、根据自己的需要创建云主机
3、登录创建的主机，ubuntu和centos的厨师密码都是Cszt!2017，windows无初始密码
4、目前的镜像，前台登陆需要修改如下配置，修改参数PasswordAuthentication为yes
vi /etc/ssh/sshd_config
PasswordAuthentication yes
/etc/init.d/sshd restart
5、修改安全组规则，放开入方向22端口
6、分区
fdisk -l
fdisk /dev/vda
n
p
2
p5
w
fdisk -l
fdisk /dev/vda
n
p
3
p
w
fdisk -l
reboot
mkfs.ext4 /dev/vda2
mkfs.ext4 /dev/vda3
mkdir /usr/twsm
mount /dev/vda2 /usr/twsm
mount /dev/vda3 /opt
6、新建数据盘，挂载数据盘
mkfs.ext4 /dev/vdb
mkdir /data
mount /dev/vdb /data
vi /etc/fstab
/dev/vda2               /usr/twsm               ext4    defaults        0 0
/dev/vda3               /opt                    ext4    defaults        0 0
/dev/vdb                /data                   ext4    defaults        0 0





##工程化专题

jenkins_sonar（192.168.130.38） 密码：twsm11

##maven

##jenkins
java -jar jenkins.war -httpPort=8080 &

##es
因为安全问题elasticsearch 不让用root用户直接运行，所以要创建新用户
第一步：liunx创建新用户  adduser XXX    然后给创建的用户加密码 passwd XXX    输入两次密码。
第二步：切换刚才创建的用户 su XXX  然后执行elasticsearch  会显示Permission denied 权限不足。
第三步：给新建的XXX赋权限，chmod 777 *  这个不行，因为这个用户本身就没有权限，肯定自己不能给自己付权限。所以要用root用户登录付权限。
第四步：root给XXX赋权限，chown -R XXX /你的elasticsearch安装目录。
然后执行成功。

##mysql
##mysql root123
rpm -ivh /usr/twsm/install/mysql/MySQL-server-5.6.21-1.rhel5.x86_64.rpm --force
	
rpm -ivh /usr/twsm/install/mysql/MySQL-client-5.6.21-1.rhel5.x86_64.rpm --force

rpm -ivh /usr/twsm/install/mysql/MySQL-devel-5.6.21-1.rhel5.x86_64.rpm --force

	
/usr/bin/mysql_install_db

	
##开启mysql服务
	
service mysql start  

##看随机密码  修改root密码 
rootPwd=$(cat /root/.mysql_secret | awk -F ": " '{print $2}' )
##超级用户进入
mysqladmin -u root -p$rootPwd password root123
##远程连接不上 host is not allowed to connect mysql
mysql -u root -p
update user set host = '%' where user = 'root';
update user set password_expired='N' where user='root';
flush privileges;

##
su sonar
sh sonar.sh start

##
mvn sonar:sonar \-Dsonar.host.url=http://192.168.130.38:9000 \-Dsonar.login=65cf85b4ece78928b704915f2ca55cfc9d95f052
mvn clean org.jacoco:jacoco-maven-plugin:prepare-agent package sonar:sonar -Dsonar.host.url=https://sonarcloud.io -Dsonar.organization=your_organization_key -Dsonar.login=bca30024494715d11c64b90a53a1555c5530ca11

##配置jenkins和sonar集成
1，servers配置
2，全局工具配置
3，项目配置
sonar.projectKey=cloudzone
sonar.projectName=cloudzone
sonar.projectVersion=6.5
sonar.sources=src/main/java
sonar.language=java
sonar.scm.disabled=true
sonar.java.binaries=target/classes

##Failed to upload report - 500: An error has occurred. Please contact your administrator
set global max_allowed_packet = 100*1024*1024;
重启sonar


192.168.130.24
twsm24
---------安装RAP2-------------------
---------基础包安装-----------------
yum install gcc -y           #安装gcc
yum install perl* -y         #安装perl依赖包
yum install gcc-c++
---------处理 ruby 和 gem-----------
yum install ruby
yum install rubygemscurl -sSL https://get.rvm.io | bash -s stable
source ~/.bashrc 
source ~/.bash_profile
curl -sSL  https://rvm.io/mpapis.asc  |  gpg2  --import  -
curl -L  get.rvm.io | bash -s stable 
rvm install 2.3.0
---------安装sass--------------------
gem install sass
---------安装前端-------------------- 
cd /usr/local/nginx/html/
unzip rap2-frontend2.zip
cnpm install node-sass@latest 
npm run build
cp -r rap2-dolores-master/build/* ./
---------安装后端--------------------
cd /usr/twsm/rap2-delos-working 
cnpm install
npm run build 
npm run create-db
nohup npm start &
```

## Linux如何查看端口

> lsof -i:端口号 用于查看某一端口的占用情况，比如查看8000端口使用情况，lsof -i:8000
>
> netstat -tunlp |grep 端口号，用于查看指定的端口号的进程情况，如查看8000端口的情况，netstat -tunlp |grep 8000



## CentOS修改IP地址

**# ifconfig eth0 192.168.1.80**

这样就把IP地址修改为**192.168.1.80**(如果发现上不了网了，那么你可能需要把网关和DNS也改一下，后面会提到)，但是当你重新启动系统或网卡之后，还是会变回原来的地址，这种修改方式只适用于需要临时做IP修改。要想永久性修改，就要修改**/etc/sysconfig/network-scripts/ifcfg-eth0**这个文件，这个文件的主要内容如下（你的文件中没有的项，你可以手动添加）：

**# vi  /etc/sysconfig/network-scripts/ifcfg-eth0**

**DEVICE=eth0 #描述网卡对应的设备别名**

**BOOTPROTO=static #设置网卡获得ip地址的方式，选项可以为为static，dhcp或bootp**

**BROADCAST=192.168.1.255 #对应的子网广播地址**

**HWADDR=00:07:E9:05:E8:B4 #对应的网卡物理地址**

**IPADDR=12.168.1.80 #只有网卡设置成static时，才需要此字段**

**NETMASK=255.255.255.0 #网卡对应的网络掩码**

**NETWORK=192.168.1.0 #网卡对应的网络地址，也就是所属的网段**

**ONBOOT=yes #系统启动时是否设置此网络接口，设置为yes时，系统启动时激活此设备**

## CentOS修改网关

**# route add default gw 192.168.1.1 dev eth0**

这样就把网关修改为**192.168.1.1了**，这种修改只是临时的，当你重新启动系统或网卡之后，还是会变回原来的网关。要想永久性修改，就要修改**/etc/sysconfig/network** 这个文件，这个文件的主要内容如下（你的文件中没有的项，你可以手动添加）：

**# vi  /etc/sysconfig/network**

**NETWORKING=yes #表示系统是否使用网络，一般设置为yes。如果设为no，则不能使用网络。**

**HOSTNAME=centos #设置本机的主机名，这里设置的主机名要和/etc/hosts中设置的主机名对应**

**GATEWAY=192.168.1.1 #设置本机连接的网关的IP地址。**

**********上面的文件修改完要重新启动一下网卡才会生效：**# service network restart** ***\*********

## CentOS修改DNS

上面的都修改完之后，当你ping一个域名是肯能不通，但ping对应的IP地址是同的，这时我们需要修改一下DNS。修改DNS要通过修改**/etc/resolv.conf**这个文件：

**# vi /etc/resolv.conf**

**nameserver 8.8.8.8 #google域名服务器 nameserver 8.8.4.4 #google域名服务器**

通过上面的所有设置，系统应该可以上网了。

如果centos系统建立在虚拟机之上，那么在设置虚拟机的网络时请选择‘网桥适配器’连接。

修改vi /etc/sysconfig/network-scripts/ifcfg-eth0，添加

```properties
DNS1=192.168.102.3
DNS2=8.8.8.8
```

## 更换yum源

进入以下目录，替换同目录的CentOS-Base.repo.

```shell
[root@root3-7 yum.repos.d]# ll
total 28
-rw-r--r--. 1 root root 1664 Aug 30  2017 CentOS-Base.repo
-rw-r--r--. 1 root root 1309 Aug 30  2017 CentOS-CR.repo
-rw-r--r--. 1 root root  649 Aug 30  2017 CentOS-Debuginfo.repo
-rw-r--r--. 1 root root  314 Aug 30  2017 CentOS-fasttrack.repo
-rw-r--r--. 1 root root  630 Aug 30  2017 CentOS-Media.repo
-rw-r--r--. 1 root root 1331 Aug 30  2017 CentOS-Sources.repo
-rw-r--r--. 1 root root 3830 Aug 30  2017 CentOS-Vault.repo
[root@root3-7 yum.repos.d]# pwd
/etc/yum.repos.d
```

```
yum源的替换大致分为三步：备份，替换，更新

一、备份
进入目录下将原来的文件重命名备份

cd /etc/yum.repos.d
mv CentOS-Base.repo CentOS-Base.repo.old
1
2
二、替换
先下载想要的源，并重命名。
sohu的源：http://mirrors.sohu.com/help/CentOS-Base-sohu.repo
163的源：http://mirrors.163.com/.help/CentOS6-Base-163.repo
阿里云的源：http://mirrors.aliyun.com/repo/Centos-7.repo
下载之后将新的源改名为 CentOS-Base.repo

wget http://mirrors.aliyun.com/repo/Centos-7.repo
mv Centos-7.repo CentOS-Base.repo
1
2
三、更新
让yum重新缓存新的数据

yum update
1
经过漫长的等待后就可以用了，美滋滋。
```

## 根据端口定位到进程

netstat   -anp   |   grep  portno

# shell 脚本编写

## 语法

### if

```shell
1.只适用于数值的比较
该类型操作会把两边变量当成整型进行加减运算，字符串abcd按整型运算无法进行，所以此类型不能用于字符串比较

参数	说明
-eq	等于则为真
-ne	不等于则为真
-gt	大于则为真
-ge	大于等于则为真
-lt	小于则为真
-le	小于等于则为真

2.适用于字符串的比较（也可用于数值比较）
参数	说明
==	相等则为真
!=	不相等则为真
 
3.字符串测试运算
参数	说明
-z 字符串	字符串的长度为零则为真
-n 字符串	字符串的长度不为零则为真
 
4.文件测试运算
参数	说明
-e 文件名	如果文件存在则为真
-r 文件名	如果文件存在且可读则为真
-w 文件名	如果文件存在且可写则为真
-x 文件名	如果文件存在且可执行则为真
-s 文件名	如果文件存在且至少有一个字符则为真
-d 文件名	如果文件存在且为目录则为真
-f 文件名	如果文件存在且为普通文件则为真
-c 文件名	如果文件存在且为字符型特殊文件则为真e
-b 文件名	如果文件存在且为块特殊文件则为真

```

解决执行脚本报syntax error: unexpected end of file或syntax error near unexpected token `fi'错误的问题：

vim --- > set ff=unix

### (),{},[],[[]]符号

```
(1)$(cmd)与··(键盘上1左边的~)一样，都是命令替换，可以将执行结果提取出来
(2)[]使用的时候[  ]前后都必须有空格，且两个字符或数字之间的比较符左右也必须有空格。
(3)   []是test的另一种形式，[]中间只能使用= 和 != 比较字符串，如果使用< 、>需要进行转义\。
[]中间如果比较数字需要用 -lt 等符号，不能使用\<比较数字，会当成字符串处理。
(4)[[]]可用于处理逻辑命令，也可以用于处理字符串是否相等，且使用<、>不用转义符.
(5)(())可用于比较数字，且不用转义，而且也可以用于数字计算，比较的时候也是用普通的>,<。(())计算的时候运算符与数字之间不能有空格，例如: sum=$(($sum+4))
(6)字符串比较 用[],与普通的<,>,=,!=符号，如果使用<,>需要转义;或者使用[[]]比较字符串也是用普通符号不用转义.数字比较用[]的时候用-lt,-gt等符号，不能使用\<(因为会当成字符串处理);或者用(())比较数字用普通符号不用转义
(7)可以将$理解为取变量的符号，$var 或者 ${}  ，在不影响语义的情况下可以省去{},但是最好写上{}。例如:test=XXX.$testWWWW.这时候就必须加上{}变为${test}WWWW
```

# pam认识

# 查看系统信息

1. lsblk 　　　　                               　　                                            查看**分区**和**磁盘**
2. df -h 　　                                                                                         查看**空间**使用情况
3. fdisk -l 　　                                                                                      分区工具查看分区信息
4. cfdisk /dev/sda  　　                                                                        查看分区
5. blkid 　                                       　                                                  查看硬盘label（别名）
6. du -sh ./* 　　                                                                                  统计当前目录各文件夹大小
7. free -h 　                                    　                                                  查看**内存大小**
8. cat /proc/cpuinfo| grep "cpu cores"| uniq  　　                                查看**cpu核心数**
9. cat /proc/cpuinfo| grep "physical id"|uniq| wc -l                                **查看物理cpu个数**
10. cat /proc/cpuinfo| grep "processor"| wc -l                                         **查看逻辑cpu的个数**

# 异常

###### 1，CentOS执行ping命令报错 name or service not know

```
添加DNS服务器
vi /etc/resolv.conf
在文件中添加如下两行（可以自己选择DNS服务器，这里选的是114的，包括谷歌的8.8.8.8和腾讯的119.29.29.29都可以）：
nameserver 114.114.114.114
nameserver 114.114.114.115
两行分别是首选DNS服务器和备选DNS服务器。 
:wq保存退出，直接就可以使用。 
如果还不好使，接着向下看。
```

2，Cetnos7重启后/etc/resolv.conf被重置

```
https://blog.csdn.net/sdutphp/article/details/82957160
----------------------------------------------------

```

去掉linux的图形界面

```
systemctl set-default multi-user.target

增加图形界面systemctl set-default graphical.target
```