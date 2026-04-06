

<img width="3408" height="652" alt="481240583-10e51ed0-59d2-4b5c-8f69-76ebd5dd70a9" src="https://github.com/user-attachments/assets/d58153b9-ba59-4851-8a68-2cc01e6b6ade" />




# HIT837 Book of Answer

![GitHub repo size](https://img.shields.io/github/repo-size/mcxiaoxiao/wangan.online.svg)
![GitHub pull requests](https://img.shields.io/github/issues-pr/mcxiaoxiao/wangan.online.svg)
![GitHub contributors](https://img.shields.io/github/contributors/mcxiaoxiao/wangan.online.svg)

相关资源索引：[在线三科答题手册](https://mcxiaoxiao.github.io/HIT837-Book-of-Answer) | [备考交流](https://github.com/mcxiaoxiao/HIT837-Book-of-Answer/discussions) | [guoJohnny学长的资料库](https://github.com/guoJohnny/-837-) | [计算学部](https://computing.hit.edu.cn/11474/list.htm) | [哈工大SSE](https://sse.hit.edu.cn/t/#/main/home) | [Annas-Archive](https://annas-archive.li/) | [Z-Library](https://zh.z-library.sk/)

<h5 align="center"><i>愿哈工大能有幸录取如此优秀的你！</i></h5>

<p align="center">
<img height="150" src="https://github.com/user-attachments/assets/fb871140-8f17-47ed-b602-a2f19f7029ce" />
<img height="150" src="https://github.com/user-attachments/assets/8a575d48-f9bc-4b13-9233-2ae9cc260468" />

<img height="150" src="https://github.com/user-attachments/assets/9dcb0d69-26aa-4e25-b430-a9d983d675c5" />
<img height="150" src="https://github.com/user-attachments/assets/89d34a51-9a12-431e-ab0a-371a6651cec1" />

</p>

作为一个非本校的837跨考选手，我深知备考这样一个小众自命题的不易，十分感谢过程中学长的帮助以及guoJohnny前辈的资料库。我希望我也能一样以分享的形式给更多同学特别是跨考的同学一些帮助，这不仅是我学生时代自愿整理的最后一个笔记本也是我的一种尝试：仓库提供背题手册、课程PPT、相关题目、交流空间，其中手册部分集概念、个人见解、代码于一体，旨在帮所有网安自命题考生减少重复劳动，高效掌握哈工大网安837考研自命题全部核心内容和所需应试技能。

本仓库的目标是创建一个为实现以下目标的统一资源：

1. 在线知识库及仓库所有内容免费开源，由社区共同守护与更新，联合起来消灭837备考信息差，让考研机构无机可乘；
2. 提供恰到好处的知识深度，从而帮助读者，快速掌握各部分备考要点，有效应对考试挑战；
3. 包含可运行的代码，精选题目与知识点，覆盖信安、网安（共占90分）全部核心考察范围；
4. 通过社区力量快速迭代内容，从而紧跟仍不断变化发展的网安自命题考试；
5. 由包含有关应试备考细节问答的[开放论坛](https://github.com/mcxiaoxiao/wangan.online/discussions)作为补充，使大家可以相互答疑并交换经验。


作者26年哈理工数据科学专业网安小白跨考工大本部网安专硕，虽然希望这份手册能帮大家减轻点缺资料和自己整理笔记的痛苦（比如我就一向反感做笔记这种“形式主义行径”，但837资料的稀缺程度和这玩意很看重背书的现实迫使记性不好的我开始哐哐一顿抄题背题），但受限于本人的应试和专业能力，目前的这一版内容很可能存在错误，如有发现或者想补充欢迎提Pull Request。

分析考纲和历年真题，可知目前837包括计算机网络（60分）、 信息安全基础（45分）和网络安全基础（45分），一般其中选择30分（各10分，一题2分）填空10分（仅计网，一题2分）简答55-60分（计网信安各20分，一题5分）计算40-45分（信安一题≤计网一或两题≤网安两题，一题10-15分，计网【CRC/DV/LS-Dijkstra/时延/子网划分-CIDR/信道利用率】，信安【RSA/DH】，网安【AC/KMP/BM/WM×1+K-means/决策树/DBSCAN/层次聚类/Native-bayes×1】这类知识点也可能用简答/选择形式来考）。私以为对0基础同学来说记忆难度计网≈信安＞网安，答题手册配合思维导图一起使用效果很可能更佳。

内容主要收集自遇到且觉得有价值的题目和知识点，大部分来自真题、考纲参考书正文、PPT和课后题（主要来自信安导论、攻防原理、自顶向下、入侵检测技术），少部分来自各路其它试卷和资料。信安网安部分的知识点很全面，计网部分由于市面上资料很多所以这里主要是历年837真题中出现的点，相对较少，不足以作为主要复习材料。括号标注在真题中出现的年份。信安和网安内容量差不多的重复知识点优先划到信安，因此只看了其中一本书时答案找不全是正常的。

-	`重要·常考` 代表在考试中至少两次复现，直接考到概率较大，背下来比较好；
-	`重要` 代表考试中不一定多次出现，建议理解；
-	`Tips` 部分帮大家理解，不背；
-	`其他部分` 若只求考<=120可以酌情放弃。
-	考试时会发8张大白纸，自己标题号作答，可以文字也可以画画，格式自由，很够写，有思路就请尽情发挥。大家也可以提前练练排版。

## 文档结构

- 算法 
  - `KMP.py` KMP算法python实现 含例子可以当例题
  - `BM.py` BM算法python实现 含例子可以当例题
  - `PPT` kmeans NATIVE-BAYES 决策树分类算法\KMP BM AC WM匹配算法
- 真题
  - 历年真题回忆版
- 习题
  - 部分答案
  - `HIT837简答十张纸.pdf` 4×计网 6×信安网安 全是重点题（若11、12月才开始准备的话，那么这个大概有大用）
- 招生信息
  - 复试名单
  - 复试成绩单
  - 拟录取名单





> [!IMPORTANT]
> 本仓库包含以下部分，分别采用不同许可证：
> 1. 代码及其它本仓库原创部分：LGPL-3.0
> 2. HIT837三科答题手册：CC BY-NC-ND 4.0
> 3. 来自guoJohnny资料库的内容及试卷题目请尊重原作者劳动成果，参照具体使用条款
> 4. **延续开源精神，不可商用，欢迎再分发！**


## 更新动态
- 2026/4/6 2026招生信息更新
- 2026/1/18 整理复试资料
- 2025/12/23 26年837真题回忆
- 2025/12/21 考试
- 2025/9/30 考纲、算法ppt更新（根据新考纲更新：考点csv、决策树、去除SVM部分）
- 2025/8/30 算法更新（BM和KMP的python实现）
- 2025/8/25 真题更新（更新25真题 感谢[试卷一书](https://blog.csdn.net/m0_65416885?type=blog)）
- 2025/8/25 开始整理（去除[guoJohnny仓库]((https://github.com/guoJohnny/-837-))中的非必要部分，补充网络上能找到的相关资料） 为让后辈不再为做笔记苦恼 为消灭信息差而奋斗 【笨小狗也要创造奇迹！】



## 历年报考热度

观察一年内Star增量

<a href="https://www.star-history.com/#mcxiaoxiao/HIT837-Book-of-Answer&guoJohnny/-837-&type=date&legend=top-left">
 <picture>
   <source media="(prefers-color-scheme: light)" srcset="https://api.star-history.com/svg?repos=mcxiaoxiao/HIT837-Book-of-Answer,guoJohnny/-837-&type=date&legend=top-left" />
   <img alt="Star History Chart" src="https://api.star-history.com/svg?repos=mcxiaoxiao/HIT837-Book-of-Answer,guoJohnny/-837-&type=date&legend=top-left" />
 </picture>
</a>



如果本手册对你有帮助，请 Star🌟 本仓库或通过 BibTeX 引用：
```BibTeX
@book{guo2026hit,
    title={HIT837 Book of Answer},
    author={HIT837 Book of Answer Community},
    note={\url{https://mcxiaoxiao.github.io/HIT837-Book-of-Answer}},
    year={2026}
}
```


<p align="center">
  &nbsp;&nbsp;&nbsp;
  <a href="#repo-content-pjax-container" target="_blank">
    Back To Top
  </a>
</p>
