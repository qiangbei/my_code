
社区规则
http://rules.emergingthreats.net/open/suricata/rules/ 

http://cve.scap.org.cn/CVE-2005-0036.html
##规则管理与描述:

NVD  CNNVD  OSVDB  SECURITYFOCUS （几家收集的机构）

DeleGate　DNS消息解压远程拒绝服务漏洞(CNNVD-200512-967)
        DeleGate 8.10.2及之前版本使用的DNS使得远程攻击者可以通过一个带有不正确偏移量的标签长度字节的DNS压缩包，导致无限循环，从而发起拒绝服务攻击。
		
发布时间: 2010/06/09
攻击名称：DNS Multiple Vendor DNS消息解压拒绝服务(CVE-2005-0036)
级别：高

BUG ID：
CVE ID：CVE-2005-0036
描述：
多个软件商使用的DNS组件存在漏洞。攻击者可恶意制作DNS消息，导致有漏洞组件进入无限循环。
危害:远程攻击者可利用此问题在运行应用程序的用户的环境下执行任意机器代码。
受影响系统:网络设备
其他参考:CVE-2005-0036
解决方案：
更新软件商的补丁。

hill的描述

## IPS对比hillstone

hillstone
1、支持操作系统:window（1964）, Linux（654）, FreeBSD, Solaris,ios（15）,安卓（9）,网络设备等
2、攻击类型:访问控制(600)、邮件攻击（无）、垃圾邮件（无）、缓冲区溢出攻击（1000）、漏洞扫描（300）、恶意软件（10）、web攻击(800)、web-activex（157）、web-clinet（261）、web-php（无）、web-misc、web-cgi（1）、后门木马（7）、蠕虫（3）、拒绝服务攻击（205）。(数字为规则数)
3、支持协议DNS（16） FTP（41） HTTP（1262） POP3（5） SMTP（51） TELNET（10） TCP（782） UDP（77） IMAP（32） FINGER（8）  SUNRPC（2） NNTP（2） TFTP（11） SNMP（2） MYSQL（15） MSSQL（1） ORACLE（9） MSRPC （5）NETBIOS （88）DHCP（4） LDAP（23） VOIP（4）
4、目前规则库支持规则数2600条左右
5、支持严重等级划分，针对影响的软件进行划分，公告板划分。
6、详细的发布年份、规则简介。



社区IPS
1、支持Linux window IOS 安卓 需要自行规则区分
2、支持邮件攻击、漏洞扫描、恶意软件、web攻击、web-activex、web-clinet、web-server、后门木马、蠕虫、拒绝服务攻击等。
3、支持协议DNS FTP HTTP POP3 SMTP TELNET TCP UDP IMAP RPC VOIP TCTP NETBIOS 支持MYSQL（3条）ORACLE  MSSQL（2条） （详细其他协议需要仔细研究社区规则，逐个统计） 
4、具体规则数有待统计。（社区规则较多）
5、无严重等级划分，无针对影响的软件进行划分，有部分公告板划分（需要后续支持统计）
6、无年份信息以及规则介绍，需要额外工作量。


山石下载地址：
http://update1.hillstonenet.com/LIBCGI.html

虚拟机信息:
Product name: SG-6000-VM02 S/N: 0010276713459525 Assembly number: 0000
Boot file is SG6000-CloudEdge-VM02-5.5R3P2
Storage UUID is 8b871d4c-82ce-48a7-a36f-41a6faad00da


Uptime is 2 days 16 hours 55 minutes 45 seconds
System language is "en"

VRouter feature: disabled

IPS feature: enabled
IPS magic: 48a863e0f57c1dc65e689e028f2cc9e0d211

AV feature: enabled
AV magic: 2d81a0364bf51d0eafc84a2854b2a803c334

URLDB feature: enabled
URLDB magic: 5351becc6a3d976024bd11e81e8e7ceff757

APP feature: enabled
APP magic: 72b5a40b3cfc92bd6f7a22a95375981d8d8c
          
SANDBOX feature: enabled
SANDBOX magic: 2d81a0364bf51d0eafc84a2854b2a803c334




