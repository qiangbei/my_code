## 抗ip分片逃避技术的设计与实现

文章借鉴:

http://xueshu.baidu.com/s?wd=paperuri:(0e32df8ef4f202586e328d81dc49842f)&filter=sc_long_sign&sc_ks_para=q%3D%E6%8A%97IP%E5%88%86%E7%89%87%E9%80%83%E9%81%BF%E6%8A%80%E6%9C%AF%E7%9A%84%E8%AE%BE%E8%AE%A1%E4%B8%8E%E5%AE%9E%E7%8E%B0&tn=SE_baiduxueshu_c1gjeupa&ie=utf-8&sc_us=17722235192251157079

http://www.docin.com/p-812537145.html


**由于不同OS的分片重组技术不同，将导致IPS的检测功能被规避**。

以下为不同OS的重组策略:

BSD  两个分片的偏移量相同 则保留**先到**达的数据,保留偏移量较低分片中的数据

BSD-right 两个分片的偏移量相同 则保留**后到**达的数据 否则保留偏移量较高分片中的数据

linux 两个分片的偏移量相同 则保留**后到**达的数据 ,保留偏移量较低分片中的数据 （不理会先到或者后到，除了相同偏于）

first 重叠部分保留先到达分片中的数据 -- window os

last  重叠部分保留后到达分片中的数据
